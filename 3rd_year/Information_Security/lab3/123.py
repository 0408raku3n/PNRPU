import random
from sympy import randprime, primitive_root
import numpy as np
from numba import jit

def generate_prime(digits):
    """Генерирует простое число с заданным количеством цифр."""
    return randprime(10 ** (digits - 1), 10 ** digits)


def find_primitive_root_with_20_digits(digits):
    """Находит первообразный корень с разрядностью 20 для простого числа."""
    while True:
        p = generate_prime(digits)  # Генерируем простое число с нужной разрядностью
        g = primitive_root(p)  # Находим первообразный корень для этого числа
        if len(str(g)) == 20:  # Проверяем разрядность корня
            return p, g

# Тест
digits = 20  # Генерируем простое число с разрядностью 20
p, g = find_primitive_root_with_20_digits(digits)
print(f"Простое число p: {p}")
print(f"Первообразный корень g: {g}")
print(f"Разрядность g: {len(str(g))}")
