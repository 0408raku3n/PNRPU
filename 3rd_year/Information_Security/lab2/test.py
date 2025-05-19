import tkinter as tk
import sympy as sp
from tkinter import filedialog

class RSAHandler:
    @staticmethod
    def generate_large_primes(num_primes=2, min_digits = 20):
        primes = []
        for _ in range(num_primes):
            candidate = sp.randprime(10 ** (min_digits - 1), 10 ** min_digits)
            primes.append(candidate)
        return primes

    @staticmethod
    def get_public_exponent(phi, min_digits = 20):
        while True:
            prime = sp.randprime(10 ** (min_digits - 15), 10 ** (min_digits))
            if prime < phi and sp.gcd(prime, phi) == 1:
                return prime

    @staticmethod
    def int_to_bytes(x):
        return x.to_bytes((x.bit_length() + 7) // 8, byteorder='big')

    @staticmethod
    def bytes_to_int(b):
        return int.from_bytes(b, byteorder='big')

    @staticmethod
    def generate_keys():
        p, q = RSAHandler.generate_large_primes()
        n = p * q
        phi_n = (p - 1) * (q - 1)
        e = RSAHandler.get_public_exponent(phi_n)
        d = sp.mod_inverse(e, phi_n)
        public_key = (e, n)
        private_key = (d, n)
        return public_key, private_key

class RSAApp(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Алгоритм RSA")
        self.geometry("1000x500")  # Базовый размер окна
        self.configure(bg="lightgrey")  # Фон
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)

        self.columnconfigure(0, weight=1)
        self.columnconfigure(1, weight=1)
        self.rowconfigure(0, weight=1)

        self.public_key = ()
        self.private_key = ()
        self.selected_file = None
        self.encrypted_data = ''
        self.decrypted_data = ''

        self.create_widgets()

    def create_widgets(self):
        frame_encrypt = tk.Frame(self, bg="white")
        frame_encrypt.grid(row=0, column=0, sticky="nsew", padx=5, pady=20)

        frame_decrypt = tk.Frame(self, bg="white")
        frame_decrypt.grid(row=0, column=1, sticky="nsew", padx=5, pady=20)

        self.columnconfigure(0, weight=1)
        self.columnconfigure(1, weight=1)


        tk.Label(frame_encrypt, text="Шифрование файла:", font=("Arial", 14, "bold"), bg="white").pack(pady=5)

        tk.Label(frame_encrypt, text="Открытый ключ:", font=("Arial", 12, "bold"), bg="white").pack(pady=2)
        self.public_key1_label = tk.Label(frame_encrypt, text="", bg="white", font=("Arial", 8), width=50)
        self.public_key1_label.pack(pady=2)
        self.public_key2_label = tk.Label(frame_encrypt, text="", bg="white", font=("Arial", 8), width=50)
        self.public_key2_label.pack(pady=2)

        tk.Label(frame_encrypt, text="Закрытый ключ:", font=("Arial", 12, "bold"), bg="white").pack(pady=2)
        self.private_key1_label = tk.Label(frame_encrypt, text="", bg="white", font=("Arial", 8), width=50)
        self.private_key1_label.pack(pady=2)
        self.private_key2_label = tk.Label(frame_encrypt, text="", bg="white", font=("Arial", 8), width=50)
        self.private_key2_label.pack(pady=2)

        self.create_button(frame_encrypt, "Сгенерировать ключи", self.generate_keys)
        self.create_button(frame_encrypt, "Выбрать файл", self.select_file)
        self.create_button(frame_encrypt, "Зашифровать", self.encrypt_file)
        self.create_button(frame_encrypt, "Сохранить файл", lambda: self.save_file('encrypted'))


        tk.Label(frame_decrypt, text="Дешифрование файла:", font=("Arial", 14, "bold"), bg="white").pack(pady=5)

        tk.Label(frame_decrypt, text="Введите закрытый ключ:", font=("Arial", 12, "bold"), bg="white").pack(pady=5)

        frame_keys = tk.Frame(frame_decrypt, bg="white")
        frame_keys.pack(pady=5)

        tk.Label(frame_keys, text="d = ", bg="white", font=("Arial", 14, "bold")).grid(row=0, column=0, sticky="e")
        self.d_key_entry = tk.Entry(frame_keys, width=45)
        self.d_key_entry.grid(row=0, column=1, padx=5)

        tk.Label(frame_keys, text="n = ", bg="white", font=("Arial", 14, "bold")).grid(row=1, column=0, sticky="e")
        self.n_key_entry = tk.Entry(frame_keys, width=45)
        self.n_key_entry.grid(row=1, column=1, padx=5)

        self.create_button(frame_decrypt, "Подтвердить ключ", self.confirm_private_key)
        self.create_button(frame_decrypt, "Выбрать файл", self.select_file)
        self.create_button(frame_decrypt, "Дешифровать", self.decrypt_file)
        self.create_button(frame_decrypt, "Сохранить файл", lambda: self.save_file('decrypted'))

    def create_button(self, parent, text, command=None):
        btn = tk.Button(parent, text=text, font=("Arial", 12, "bold"), bg="#bfb69b", fg="black",
                        relief="flat", padx=10, pady=5, width=20, height=1, command=command)
        btn.pack(pady=5, fill="x")

        btn.bind("<Enter>", lambda e: btn.config(bg="#ccc5b1"))
        btn.bind("<Leave>", lambda e: btn.config(bg="#bfb69b"))

    def select_file(self):
        file_path = filedialog.askopenfilename(title="Выберите файл", filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
        if file_path:
            self.selected_file = file_path
            print(f"Выбран файл: {file_path}")

    def generate_keys(self):
        self.public_key, self.private_key = RSAHandler.generate_keys()

        self.public_key1_label.config(text=self.public_key[0])
        self.public_key2_label.config(text=self.public_key[1])
        self.private_key1_label.config(text=self.private_key[0])
        self.private_key2_label.config(text=self.private_key[1])

        print(f"Public_key: {self.public_key}")
        print(f"Private_key: {self.private_key}")

    def confirm_private_key(self):
        self.private_key = (int(self.d_key_entry.get()), int(self.n_key_entry.get()))

    def encrypt_file(self):
        with open(self.selected_file, 'rb') as f:
            file_data = f.read()
        if self.public_key:
            e, n = self.public_key
            self.block_size = (n.bit_length() + 7) // 8 - 11
            blocks = [file_data[i:i + self.block_size] for i in range(0, len(file_data), self.block_size)]

            encrypted_blocks = []
            for block in blocks:
                # Преобразование блока в целое число
                block_int = RSAHandler.bytes_to_int(block)
                # Шифрование блока
                encrypted_block = pow(block_int, e, n)
                encrypted_blocks.append(encrypted_block)

            self.encrypted_data = ' '.join(map(str, encrypted_blocks))
            print("Данные зашифрованы!")
        else:
            print("Ошибка, нет открытого ключа!")

    def decrypt_file(self):
        with open(self.selected_file, 'rb') as f:
            file_data = f.read()
        if self.private_key:
            d, n = self.private_key
            decrypted_message = bytearray()

            file_data = file_data.decode('utf-8')
            print(file_data.split())
            for block in file_data.split():
                # Дешифрование блока
                decrypted_block = pow(int(block), d, n)
                # Преобразование целого числа обратно в байты
                decrypted_message.extend(RSAHandler.int_to_bytes(decrypted_block))

            self.decrypted_data = decrypted_message.decode('utf-8')
            print("Данные дешифрованы!")
        else:
            print("Ошибка, нет закрытого ключа!")

    def save_file(self, flag):
        if self.selected_file:
            new_file_path = self.selected_file.rstrip(".txt").rstrip("_encrypted") + "_" + flag + ".txt"
            with open(new_file_path, "w") as file:
                if flag == 'encrypted':
                    file.write(self.encrypted_data)
                elif flag == 'decrypted':
                    file.write(self.decrypted_data)
                print("Файл сохранен!")


if __name__ == "__main__":
    app = RSAApp()
    app.mainloop()
