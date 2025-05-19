import sympy as sp
import random as rd
import tkinter as tk
from tkinter import messagebox

def hashing(message, p):
    hash_sum = sum([ord(l) for l in message])
    return hash_sum % p

class ElGamal:
    def __init__(self):
        self.public_key, self.private_key = (), ()
        self.hash_sum = 0
        self.signature = ()

    def generate_keys(self, bit_depth_p=20, bit_depth_xg=12):           # Генерация ключей с 20-разрядным p и 12-разрядными x и g
        p = sp.randprime(2 ** (bit_depth_p - 1), 2 ** bit_depth_p)
        g = self.generate_g(p, bit_depth_xg)
        x = self.generate_x(p, bit_depth_xg)
        y = self.calculate_y(p, g, x)

        self.public_key = (p, g, y)
        self.private_key = x

    def signing_message(self, message):
        self.hash_sum = hashing(message, self.public_key[0])
        k = self.generate_k(self.public_key[0])
        r = self.calculate_r(self.public_key[0], self.public_key[1], k)
        k_inv = self.calculate_inverse_k(k, self.public_key[0])
        s = self.calculate_s(k_inv, self.hash_sum, self.private_key, r, self.public_key[0])

        self.signature = (r, s)

    @staticmethod
    def phi(n):
        return n - 1

    @staticmethod
    def find_divisors(n):
        factors = []

        while n % 2 == 0:
            factors.append(2)
            n //= 2

        divisor = 3
        while divisor ** 2 <= n:
            while n % divisor == 0:
                factors.append(divisor)
                n //= divisor
            divisor += 2

        if n > 2:
            factors.append(n)

        return factors

    @staticmethod
    def generate_g(n, min_digits):
        phi_n = ElGamal.phi(n)

        n_divisors = sorted(ElGamal.find_divisors(phi_n))

        prim_roots = []
        for g in range(2 ** (min_digits - 1), 2 ** min_digits):
            is_primitive_root = True
            for d in n_divisors:
                if pow(g, phi_n // d, n) == 1:
                    is_primitive_root = False
                    break
            if is_primitive_root :
                prim_roots.append(g)

        return rd.choice(prim_roots)

    @staticmethod
    def generate_x(n, min_digits):
        return rd.choice([i for i in range(1, n) if 2 ** (min_digits - 1) < i < 2 ** min_digits])

    @staticmethod
    def calculate_y(p, g, x):
        return pow(g, x, p)

    @staticmethod
    def generate_k(p):
        return sp.randprime(1, p)

    @staticmethod
    def calculate_r(p, g, k):
        return pow(g, k, p)

    @staticmethod
    def calculate_s(k_inv, m, x, r, p):
        return (k_inv * (m - x * r)) % (p - 1)

    @staticmethod
    def calculate_inverse_k(k, p):
        return sp.mod_inverse(k, p - 1)

class SignatureVerification:
    def __init__(self, public_key, signature, message):
        self.public_key = public_key
        self.signature = signature
        self.hash_sum = hashing(message, self.public_key[0])
        self.v1, self.v2 = self.calculate_v1_v2()

    def calculate_v1_v2(self):
        p, g, y = self.public_key
        r, s = self.signature
        m = self.hash_sum
        v1 = ((y ** r) * (r ** s)) % p
        v2 = (g ** m) % p
        return v1, v2

    def check_signature(self):
        r, s = self.signature
        p = self.public_key[0]
        return 0 < r < p and 0 < s < p - 1 and self.v1 == self.v2

class ElGamalApp(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Цифровая подпись в схеме Эль-Гамаля")
        self.geometry("600x500")  # Базовый размер окна
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)

        self.elgamal_signing = None

        self.create_widgets()

    def create_widgets(self):
        frame = tk.Frame(self, bg="#f0f0f0")
        frame.pack(pady=20)

        tk.Button(frame, text="Сгенерировать ключи", command=self.generate_keys_gui, font=("Arial", 12), bg="#4CAF50", fg="white", padx=10, pady=5).pack(pady=5)
        self.public_key_label = tk.Label(frame, text="Открытый ключ: Нет", font=("Arial", 10), bg="#f0f0f0")
        self.public_key_label.pack(pady=5)

        self.private_key_label = tk.Label(frame, text="Закрытый ключ: Нет", font=("Arial", 10), bg="#f0f0f0")
        self.private_key_label.pack(pady=5)

        self.text_input = tk.Text(frame, height=10, width=50, font=("Arial", 10))
        self.text_input.pack(pady=5)

        tk.Button(frame, text="Создать подпись", command=self.generate_signature_gui, font=("Arial", 12), bg="#2196F3", fg="white", padx=10, pady=5).pack(pady=5)

        self.signature_label = tk.Label(frame, text="Подпись:", font=("Arial", 10), bg="#f0f0f0")
        self.signature_label.pack(pady=5)
        self.signature = tk.Entry(frame, font=("Arial", 10), bg="#f0f0f0")
        self.signature.pack(pady=5)

        tk.Button(frame, text="Проверить подпись", command=self.verify_signature_gui, font=("Arial", 12), bg="#FF9800", fg="white", padx=10, pady=5).pack(pady=5)

    def generate_keys_gui(self):
        self.elgamal_signing = ElGamal()
        self.elgamal_signing.generate_keys()
        self.public_key_label.config(text=f"Открытый ключ: p={self.elgamal_signing.public_key[0]}, g={self.elgamal_signing.public_key[1]}, y={self.elgamal_signing.public_key[2]}")
        self.private_key_label.config(text=f"Закрытый ключ: x={self.elgamal_signing.private_key}")

    def generate_signature_gui(self):
        message = self.text_input.get("1.0", tk.END).strip()
        if len(message) < 256:
            messagebox.showerror("Ошибка", "Длина сообщения должна быть не менее 256 символов.")
            return
        if not self.elgamal_signing.public_key or not self.elgamal_signing.private_key:
            messagebox.showerror("Ошибка", "Сначала сгенерируйте ключи.")
            return
        self.elgamal_signing.signing_message(message)
        self.signature.insert(0, f"{self.elgamal_signing.signature[0]}, {self.elgamal_signing.signature[1]}")

    def verify_signature_gui(self):
        message = self.text_input.get("1.0", tk.END).strip()
        cur_signature = tuple(map(int, self.signature.get().split(", ")))
        self.elgamal_signing.signature = cur_signature
        signature_verification = SignatureVerification(self.elgamal_signing.public_key, self.elgamal_signing.signature, message)
        messagebox.showinfo("Результат проверки", "Подпись верна!" if signature_verification.check_signature() else "Подпись недействительна.")

if __name__ == "__main__":
    app = ElGamalApp()
    app.mainloop()