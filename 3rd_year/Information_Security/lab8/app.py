import tkinter as tk
from operator import index
from tkinter import filedialog
import GammaEncryption

class App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Алгоритм гаммирования")
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)
        self.geometry("600x600")

        self.selected_file = ''

        self.data = ''
        self.gamma = b''
        self.cipher = b''
        self.decipher = b''


        self.create_widgets()

    def create_widgets(self):
        select_button = tk.Button(text='Выбрать файл', font=("Roboto", 12, "bold"), width=15, bg='red', command=self.select_file)
        select_button.grid(row=0, columnspan=2, pady=10)

        text_label = tk.Label(text='Файл:', font=("Roboto", 12, "bold"))
        text_label.grid(row=1, column=0, pady=10, sticky='E')
        self.text_text = tk.Text(font=("Roboto", 12, "bold"), width=50, height=5, state='disabled')
        self.text_text.grid(row=1, column=1, pady=10)

        encrypt_button = tk.Button(text='Зашифровать', font=("Roboto", 12, "bold"), width=15, bg='red', command=self.encrypt_file)
        encrypt_button.grid(row=2, columnspan=2, pady=10)

        cipher_label = tk.Label(text='Шифр:', font=("Roboto", 12, "bold"))
        cipher_label.grid(row=3, column=0, pady=10, sticky='E')
        self.cipher_text = tk.Text(font=("Roboto", 12, "bold"), width=50, height=5, state='disabled')
        self.cipher_text.grid(row=3, column=1, pady=10)

        decrypt_button = tk.Button(text="Дешифровать", font=("Roboto", 12, "bold"), width=15, bg='red', command=self.decrypt_file)
        decrypt_button.grid(row=4, columnspan=2, pady=10)

        decrypt_label = tk.Label(text='Дешифр:', font=("Roboto", 12, "bold"))
        decrypt_label.grid(row=5, column=0, pady=10, sticky='E')
        self.decipher_text = tk.Text(font=("Roboto", 12, "bold"), width=50, height=5, state='disabled')
        self.decipher_text.grid(row=5, column=1, pady=10)

    def select_file(self):
        file_path = filedialog.askopenfilename(title="Выберите файл",
                                               filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
        if file_path:
            self.selected_file = file_path
        with open(self.selected_file, "r", encoding='utf-8') as file:
            self.data = file.read()

        self.text_text.config(state='normal')
        self.text_text.insert('1.0', self.data)
        self.text_text.config(state='disabled')

    def encrypt_file(self):
        self.gamma = GammaEncryption.generate_gamma(len(self.data.encode('utf-8')))
        encryptor = GammaEncryption.GammaEncryptor(self.data.encode('utf-8'), self.gamma)
        self.cipher = encryptor.encryption()

        self.cipher_text.config(state='normal')
        self.cipher_text.insert('1.0', self.cipher)
        self.cipher_text.config(state='disabled')

        print(self.cipher)
        with open(self.selected_file[:-4] + '_encrypted.txt', 'w', encoding='utf-8') as file:
            file.writelines(str(self.cipher))

    def decrypt_file(self):
        decryptor = GammaEncryption.GammaDecryptor(self.cipher, self.gamma)
        self.decipher = decryptor.decryption()

        self.decipher_text.config(state='normal')
        self.decipher_text.insert('1.0', self.decipher.decode('utf-8'))
        self.decipher_text.config(state='disabled')

        with open(self.selected_file[:-4] + '_decrypted.txt', 'w', encoding='utf-8') as file:
            file.writelines(self.decipher.decode('utf-8'))



if __name__ == "__main__":
    app = App()
    app.mainloop()
