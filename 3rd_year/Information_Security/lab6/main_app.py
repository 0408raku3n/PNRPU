import tkinter as tk
from tkinter import filedialog

class ArithmeticCoding:
    def __init__(self, text: str):
        self.text = text
        self.frequencies = ArithmeticCoding.get_frequencies(text)
        self.alphabet = list(set(text))
        self.segments = ArithmeticCoding.get_segments(self.alphabet, self.frequencies)

        self.code = self.coding()

    @staticmethod
    def get_frequencies(string: str) -> dict:
        symbols = set(string)
        frequencies = dict()

        for symbol in symbols:
            frequencies[symbol] = string.count(symbol) / len(string)

        return frequencies

    @staticmethod
    def get_segments(letters: list[str], frequencies: dict):
        left = 0
        segments = dict()

        for letter in letters:
            segments[letter] = (left, left + frequencies.get(letter))
            left += frequencies.get(letter)

        return segments

    def coding(self):
        left = 0
        right = 1
        for letter in self.text:
            new_left = left + (right - left) * self.segments.get(letter)[0]
            new_right = left + (right - left) * self.segments.get(letter)[1]
            left = new_left
            right = new_right

        return (left + right) / 2

class LZWAlgorithm:
    def __init__(self, string: str):
        self.data = string

        self.code = self.coding()
        self.decode = self.decoding()

    def coding(self):
        dictionary = {chr(i): i for i in range(256)}
        next_code = 256
        current_string = ""
        code = []

        for char in self.data:
            combined_string = current_string + char
            if combined_string in dictionary:
                current_string = combined_string
            else:
                code.append(dictionary[current_string])
                dictionary[combined_string] = next_code
                next_code += 1
                current_string = char

        if current_string:
            code.append(dictionary[current_string])

        return code

    def decoding(self):
        dictionary = {i: chr(i) for i in range(256)}
        next_code = 256
        current_string = chr(self.code.pop(0))
        decode = [current_string]

        for code in self.code:
            if code in dictionary:
                entry = dictionary[code]
            elif code == next_code:
                entry = current_string + current_string[0]
            else:
                raise ValueError("Invalid compressed data")

            decode.append(entry)
            dictionary[next_code] = current_string + entry[0]
            next_code += 1
            current_string = entry

        return ''.join(decode)

class CompressionApp(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Сжатие ариф. кодированием - алгоритмом Лемпеля-Зива-Велча")
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)

        self.selected_file = ''
        self.data = ''
        self.arithm_code = ''
        self.lzw_code = ''

        self.create_widgets()

    def create_widgets(self):
        select_button = tk.Button(self, text="Выбрать файл", font=("Robot", 12, "bold"), fg='black', bg='#34685c', command=self.select_file)
        select_button.grid(row=0, column=0, sticky='N', pady=10)
        self.select_label = tk.Label(self, text='', font=("Robot", 10, "bold"), fg='black')
        self.select_label.grid(row=1, column=0, sticky='N')

        arithmetic_encoding_button = tk.Button(self, text="Сжатие алгоритмом арифм. кодирования", font=("Robot", 12, "bold"), fg='black', bg='#34685c', command=self.arithm_coding)
        arithmetic_encoding_button.grid(row=2, column=0, sticky='N', pady=10)
        self.arithmetic_encoding_label = tk.Label(self, text='', font=("Robot", 10, "bold"), fg='black')
        self.arithmetic_encoding_label.grid(row=3, column=0, sticky='N')

        lzw_button = tk.Button(self, text="Сжатие алгоритмом LZW", font=("Robot", 12, "bold"), fg='black', bg='#34685c', command=self.lzw_coding)
        lzw_button.grid(row=4, column=0, sticky='N', pady=10)
        self.lzw_label = tk.Label(self, text='', font=("Robot", 10, "bold"), fg='black')
        self.lzw_label.grid(row=5, column=0, sticky='N')

    def select_file(self):
        file_path = filedialog.askopenfilename(title="Выберите файл",
                                               filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
        if file_path:
            self.selected_file = file_path
            self.select_label.config(text=f"Выбран файл: {file_path.split("/")[-1]}")
        with open(self.selected_file, "r") as file:
            self.data = file.read()

    def arithm_coding(self):
        encoder = ArithmeticCoding(self.data)
        self.arithm_code = str(encoder.code)
        self.arithmetic_encoding_label.config(text=f"Код: {self.arithm_code}")
        with open('arithmetic_encoded.bin', 'w', encoding='utf-8') as file:
            file.write(self.arithm_code)

    def lzw_coding(self):
        encoder = LZWAlgorithm(self.arithm_code)
        self.lzw_code = ' '.join(map(str, encoder.code))
        self.lzw_label.config(text=f"Код: {self.lzw_code}")
        with open('lzw_encoded.bin', 'w', encoding='utf-8') as file:
            file.write(self.lzw_code)

if __name__ == "__main__":
    app = CompressionApp()
    app.mainloop()