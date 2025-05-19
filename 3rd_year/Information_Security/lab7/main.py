import tkinter as tk
from tkinter import messagebox
from tkinter.messagebox import showerror

from HashingAlgorithm import merkle_damgard

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Алгоритм хеширования")
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)

        self.create_widgets()

    def create_widgets(self):
        input_label = tk.Label(text="Пароль:", font=("Roboto", 12, "bold"))
        input_label.grid(row=0, column=0, sticky='E', pady=10)
        self.input_password = tk.Entry(font=("Roboto", 12, "bold"), width=20)
        self.input_password.grid(row=0, column=1, sticky='W', pady=10)

        hash_button = tk.Button(text="Хэшировать пароль", font=("Roboto", 10, "bold"), bg='red', command=self.hashing)
        hash_button.grid(row=1, columnspan=2, sticky='N', pady=10)

        hash_label = tk.Label(text="Хэш:", font=("Roboto", 12, "bold"))
        hash_label.grid(row=2, column=0, sticky='E', pady=10)
        self.hash_text = tk.Text(font=("Roboto", 12, "bold"), width=20, height=2)
        self.hash_text.grid(row=2, column=1, sticky='W', pady=10)

    def hashing(self):
        data = self.input_password.get()
        if 4 <= len(data) <= 10:
            hash_val = merkle_damgard(data.encode())
            print(hash_val)
            self.hash_text.insert('1.0', str(hash_val))
        else:
            showerror(title="Ошибка!", message="Пароль должен быть от 4 до 10 символов.")

if __name__ == "__main__":
    app = App()
    app.mainloop()