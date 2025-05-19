import tkinter as tk
from tkinter import messagebox

def bytes_to_bits(d):
    return [int(bit) for bit in ''.join(format(byte, '08b') for byte in d)]

def crc4(data, polynomial=0b10011):
    crc = 0                                         # Инициализация регистра CRC (4 бита)
    for byte in data:
        crc ^= byte                                 # Добавляем байт данных
        for _ in range(8):                          # Обрабатываем каждый бит
            if crc & 0b1000:                        # Если старший бит CRC равен 1
                crc = (crc << 1) ^ polynomial
            else:
                crc <<= 1
            crc &= 0b1111                           # Ограничиваем 4 битами
    return crc


if __name__ == "__main__":
    pol = 0b11001    # 4 битный полином x^4 + x^3 + 1
    text = input()
    text_bytes = text.encode('utf-8')
    print(f"test: {crc4(text_bytes, pol):04b}")
    text_bits = bytes_to_bits(text_bytes)
    text_bits = ''.join(map(str, text_bits))
    print(text_bits)

    bits_array = []
    for i in range(0, len(text_bits), 4):
        bits_array.append(int(text_bits[i:i+4], 2))
    print(bits_array)
    print(f"{crc4(bits_array, pol):04b}")


