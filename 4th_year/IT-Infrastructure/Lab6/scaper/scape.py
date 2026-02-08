from datetime import datetime
from typing import List, Dict
import pandas as pd
import matplotlib.pyplot as plt
import calendar
import os
from playwright.sync_api import sync_playwright

def parse_release_to_date(release_text: str) -> datetime:
    import re
    match = re.search(r"([A-Za-z]+)\s+(\d{4})", release_text)
    if not match:
        raise ValueError(f"Не удалось распознать дату: {release_text}")
    
    month_name, year = match.groups()
    month_num = list(calendar.month_name).index(month_name) 
    if month_num == 0:
        raise ValueError(f"Некорректное название месяца: {month_name}")
    
    return datetime(int(year), month_num, 1)

def show_country_evolution(base_dir, country_name: str, country_name_rus: str):
    data = df[df["country"] == country_name].sort_values("date").copy()
    if data.empty:
        print(f"Данные по {country_name} не найдены")
        return

    print(f"\n{'='*25} {country_name} {'='*25}")
    print(data[["release", "systems", "systems_share", "total_rmax_pflops"]].round(2).to_string(index=False))

    changing_params = {
        "systems": ["Количество систем", "Изменение числа систем"],
        "total_rmax_pflops": ["Макс. производительность, PFlop/s", "Изменение производительности систем"],
        "systems_share": ["Доля в общей численности", "Изменение доли систем в общей численности"]
    }

    for key, item in changing_params.items():
        fig, ax = plt.subplots(figsize=(10, 12))
        ax.plot(data["date"], data[key], marker="o", linewidth=2, markersize=4)
        ax.set_title(f"{country_name_rus}: {item[1]}")
        ax.set_ylabel(f"{item[0]}")
        ax.grid(True, alpha=0.5)
        plt.tight_layout()

        out_dir = "plots"
        os.makedirs(os.path.join(base_dir, out_dir, country_name), exist_ok=True)
        filename = f"{os.path.join(base_dir, out_dir, country_name)}/{item[1]}.png"
        plt.savefig(filename, dpi=300)
        plt.close(fig)

if __name__ == "__main__":
    all_data: List[Dict] = []
    base_dir = os.path.dirname(os.path.abspath(__file__))

    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True)
        page = browser.new_page()
        page.goto("https://www.top500.org/statistics/list/")
        page.wait_for_load_state("networkidle")

        page.select_option("#id_stats_type", "country")
        page.click("button[type='submit']")
        page.wait_for_load_state("networkidle")

        options = page.locator("#id_t500list option").all()
        releases = []
        for opt in options:
            text = opt.inner_text().strip()
            value = opt.get_attribute("value")
            if value and text:
                releases.append((text, value))

        releases.sort(key=lambda x: parse_release_to_date(x[0]))

        print(f"Найдено релизов: {len(releases)} ({releases[0][0]} — {releases[-1][0]})")

        for idx, (release_text, release_value) in enumerate(releases, 1):
            print(f"[{idx}/{len(releases)}] {release_text}")

            page.select_option("#id_t500list", release_value)
            page.click("button[type='submit']")                    
            page.wait_for_selector("table.google-visualization-table-table", timeout=20000)

            header_elements = page.locator("table.google-visualization-table-table th").all()
            headers = [th.inner_text().strip() for th in header_elements]

            try:
                country_idx = headers.index("Countries")         
            except ValueError:
                country_idx = headers.index("Country")

            try:
                systems_idx = headers.index("Count")
            except ValueError:
                systems_idx = headers.index("Systems")

            try:
                share_idx = headers.index("System Share (%)")
            except ValueError:
                share_idx = headers.index("Share (%)")

            rmax_idx = -1
            for i, h in enumerate(headers):
                if "Rmax" in h:
                    rmax_idx = i
                    break

            rows = page.locator("table.google-visualization-table-table tbody tr").all()
            for row in rows:
                cells = row.locator("td").all()
                if len(cells) < max(country_idx, systems_idx, share_idx, rmax_idx) + 1:
                    continue

                country = cells[country_idx].inner_text().strip()
                if country == "" or country.startswith("#"): 
                    continue

                try:
                    systems = int(cells[systems_idx].inner_text().replace(",", "").strip())
                    rmax_text = cells[rmax_idx].inner_text().replace(",", "").strip()
                    rmax_header = headers[rmax_idx]
                    rmax_pflops = float(rmax_text)
                    systems_share = float(cells[share_idx].inner_text().strip().replace("%", "").strip())

                except (ValueError, IndexError) as e:
                    print(f"Ошибка парсинга строки: {e}")
                    continue

                all_data.append({
                    "release": release_text,
                    "date": parse_release_to_date(release_text),
                    "country": country,
                    "systems": systems,
                    "systems_share": systems_share,
                    "total_rmax_pflops": round(rmax_pflops, 2),
                })

        browser.close()


    output_dir = "tables"
    os.makedirs(os.path.join(base_dir, output_dir), exist_ok=True)

    df = pd.DataFrame(all_data)
    pivot_systems = df.pivot_table(index="date", columns="country", values="systems", fill_value=0)
    pivot_rmax = df.pivot_table(index="date", columns="country", values="total_rmax_pflops", fill_value=0)
    latest_date = pivot_systems.index.max()
    current = df[df["date"] == latest_date].set_index("country")

    print("\n" + "="*70)
    print("Текущий топ-10 стран по количеству систем")
    top_10 = current["systems"].sort_values(ascending=False).head(10)
    print(top_10)

    top_10_df = pd.DataFrame(top_10).reset_index()
    top_10_df.columns = ["Country", "Systems"]
    top_10_df.to_excel(os.path.join(base_dir, output_dir, "топ10_количество_последний_релиз.xlsx"), index=False)


    print("\n" + "="*70)
    print("Текущий антитоп-10 стран по количеству систем")
    tail_10 = current[current["systems"] >= 1]["systems"].sort_values().head(10)
    print(tail_10)

    tail_10_df = pd.DataFrame(tail_10).reset_index()
    tail_10_df.columns = ["Country", "Systems"]
    tail_10_df.to_excel(os.path.join(base_dir, output_dir, "антитоп10_количество_последний_релиз.xlsx"), index=False)


    print("\n" + "="*70)
    print("Топ-10 по росту числа систем за всё время")
    growth_all_time = pivot_systems.iloc[-1] - pivot_systems.iloc[0]
    growth_leaders = growth_all_time.sort_values(ascending=False).head(10)
    print(growth_leaders)

    growth_leaders_df = pd.DataFrame(growth_leaders, columns=["Growth"]).reset_index()
    growth_leaders_df.columns = ["Country", "Growth"]
    growth_leaders_df.to_excel(os.path.join(base_dir, output_dir, "топ10_рост_числа_все_время.xlsx"), index=False)


    print("\n" + "="*70)
    print("Антитоп-10 по росту числа систем за всё время")
    growth_outsiders = growth_all_time.sort_values().head(10)
    print(growth_outsiders)

    growth_outsiders_df = pd.DataFrame(growth_outsiders, columns=["Growth"]).reset_index()
    growth_outsiders_df.columns = ["Country", "Growth"]
    growth_outsiders_df.to_excel(os.path.join(base_dir, output_dir, "антитоп10_рост_числа_все_время.xlsx"), index=False)


    print("\n" + "="*70)
    print("\nТоп-10 по росту числа систем за последние 5 лет")
    recent_slice = pivot_systems.tail(10)
    growth_5y = recent_slice.iloc[-1] - recent_slice.iloc[0]
    growth_5y_leaders = growth_5y.sort_values(ascending=False).head(10)
    print(growth_5y_leaders)

    growth_5y_leaders_df = pd.DataFrame(growth_5y_leaders, columns=["Growth"]).reset_index()
    growth_5y_leaders_df.columns = ["Country", "Growth"]
    growth_5y_leaders_df.to_excel(os.path.join(base_dir, output_dir, "топ10_рост_числа_5_лет.xlsx"), index=False)


    print("\n" + "="*70)
    print("\nАнтитоп-10 по росту числа систем за последние 5 лет")
    growth_5y_outsiders = growth_5y.sort_values().head(10)
    print(growth_5y_outsiders)

    growth_5y_outsiders_df = pd.DataFrame(growth_5y_outsiders, columns=["Growth"]).reset_index()
    growth_5y_outsiders_df.columns = ["Country", "Growth"]
    growth_5y_outsiders_df.to_excel(os.path.join(base_dir, output_dir, "антитоп10_рост_числа_5_лет.xlsx"), index=False)


    show_country_evolution(base_dir, "Russia", "Россия")
    show_country_evolution(base_dir, "China", "Китай")

    df.to_excel(os.path.join(base_dir, output_dir, "топ500_все_время.xlsx"), index=False)
    pivot_systems.to_excel(os.path.join(base_dir, output_dir, "топ500_количество_по_странам.xlsx"))
    pivot_rmax.to_excel(os.path.join(base_dir, output_dir, "топ500_производительность_по_странам.xlsx"))