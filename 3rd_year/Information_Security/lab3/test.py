import tkinter as tk
from tkinter import messagebox
import random
from sympy import isprime, mod_inverse

def generate_prime(bits=256):
    while True:
        num = random.getrandbits(bits)
        if isprime(num):
            return num

def generate_keys():
    p = generate_prime()
    g = random.randint(2, p - 1)
    x = random.randint(2, p - 2)
    y = pow(g, x, p)
    return (p, g, y), x

def sign_message(message, private_key, public_key):
    p, g, y = public_key
    h = hash(message)
    k = random.randint(2, p - 2)
    while mod_inverse(k, p - 1) is None:
        k = random.randint(2, p - 2)
    r = pow(g, k, p)
    s = ((h - private_key * r) * mod_inverse(k, p - 1)) % (p - 1)
    return r, s

def verify_signature(message, signature, public_key):
    p, g, y = public_key
    r, s = signature
    h = hash(message)
    if not (1 <= r < p):
        return False
    v1 = pow(y, r, p) * pow(r, s, p) % p
    v2 = pow(g, h, p)
    return v1 == v2

def generate_keys_gui():
    global public_key, private_key
    public_key, private_key = generate_keys()
    public_key_label.config(text=f"Открытый ключ: p={public_key[0]}, g={public_key[1]}, y={public_key[2]}")
    private_key_label.config(text=f"Закрытый ключ: x={private_key}")
    messagebox.showinfo("Ключи сгенерированы", "Открытый и закрытый ключи успешно созданы.")

def sign_message_gui():
    message = text_input.get("1.0", tk.END).strip()
    if len(message) < 256:
        messagebox.showerror("Ошибка", "Длина сообщения должна быть не менее 256 символов.")
        return
    if not public_key or not private_key:
        messagebox.showerror("Ошибка", "Сначала сгенерируйте ключи.")
        return
    global signature
    signature = sign_message(message, private_key, public_key)
    signature_label.config(text=f"Подпись: r={signature[0]}, s={signature[1]}")

def verify_signature_gui():
    message = text_input.get("1.0", tk.END).strip()
    if not public_key or not signature:
        messagebox.showerror("Ошибка", "Сначала создайте подпись.")
        return
    valid = verify_signature(message, signature, public_key)
    messagebox.showinfo("Результат проверки", "Подпись верна!" if valid else "Подпись недействительна.")

app = tk.Tk()
app.title("ЭЦП методом Эль-Гамаля")

public_key, private_key, signature = None, None, None

tk.Button(app, text="Сгенерировать ключи", command=generate_keys_gui).pack()

public_key_label = tk.Label(app, text="Открытый ключ: Нет")
public_key_label.pack()

private_key_label = tk.Label(app, text="Закрытый ключ: Нет")
private_key_label.pack()

text_input = tk.Text(app, height=10, width=50)
text_input.pack()

tk.Button(app, text="Создать подпись", command=sign_message_gui).pack()

tk.Button(app, text="Проверить подпись", command=verify_signature_gui).pack()

signature_label = tk.Label(app, text="Подпись: Нет")
signature_label.pack()

app.mainloop()
