import sympy as sp
import tkinter as tk

min_digits = 20

def generate_large_primes(num_primes=2):
    primes = []
    for _ in range(num_primes):
        candidate = sp.randprime(10 ** (min_digits - 1), 10 ** min_digits)
        primes.append(candidate)
    return primes

def get_public_exponent(phi):
    while True:
        prime = sp.randprime(10 ** (min_digits - 15), 10 ** (min_digits))
        if prime < phi and sp.gcd(prime, phi) == 1:
            return prime

def int_to_bytes(x):
    return x.to_bytes((x.bit_length() + 7) // 8, byteorder='big')

def bytes_to_int(b):
    return int.from_bytes(b, byteorder='big')

def encrypt(text, key):
    e, n = public_key

    block_size = (n.bit_length() + 7) // 8 - 11  
    blocks = [text[i:i + block_size] for i in range(0, len(text), block_size)]
    
    encrypted_blocks = []
    for block in blocks:
        # Преобразование блока в целое число
        block_int = bytes_to_int(block.encode('utf-8'))
        # Шифрование блока
        encrypted_block = pow(block_int, e, n)
        encrypted_blocks.append(encrypted_block)
    
    return encrypted_blocks

def decrypt(encrypted_blocks, key):
    d, n = key
    decrypted_message = ''
    
    for block in encrypted_blocks:
        # Дешифрование блока
        decrypted_block = pow(block, d, n)
        # Преобразование целого числа обратно в байты
        decrypted_message += int_to_bytes(decrypted_block).decode('utf-8', errors='ignore')
    
    return decrypted_message

p, q = generate_large_primes()

n = p * q
phi_n = (p - 1) * (q - 1)
e = get_public_exponent(phi_n)
d = sp.mod_inverse(e, phi_n)

public_key = (e, n)
private_key = (d, n)

print(f"Открытый ключ - {public_key}")
print(f"Закрытый ключ - {private_key}")

# Пример использования
message = "Информация для шифрования"
print("Оригинальное сообщение:", message)

encrypted_message = encrypt(message, public_key)
print("Зашифрованное сообщение:", encrypted_message)

decrypted_message = decrypt(encrypted_message, private_key)
print("Дешифрованное сообщение:", decrypted_message)