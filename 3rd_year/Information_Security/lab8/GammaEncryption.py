import os

def split_into_blocks(data: bytes, block_size=8):
    """Разделяет данные на блоки указанного размера (по умолчанию 8 байт)."""
    return [data[i:i + block_size] for i in range(0, len(data), block_size)]

def generate_gamma(length: int) -> bytes:
    """Генерирует гамму (ключ) заданной длины, гарантируя, что каждый блок нечетный."""
    gamma = os.urandom(length)
    gamma = bytearray(gamma)
    for i in range(len(gamma)):
        if gamma[i] % 2 == 0:
            gamma[i] |= 1  # Делаем нечетным
    return bytes(gamma)

def pad_data(data: bytes, block_size=8):
    """Дополняет данные до длины, кратной block_size."""
    padding_length = block_size - (len(data) % block_size)
    padding = bytes([padding_length] * padding_length)
    return data + padding

def unpad_data(data: bytes):
    """Убирает дополнение из данных."""
    padding_length = data[-1]
    return data[:-padding_length]

class GammaEncryptor:
    def __init__(self, data: bytes, gamma: bytes):
        self.data = pad_data(data)  # Дополняем данные
        self.gamma = gamma

    @staticmethod
    def encrypt_block(data_block: bytes, gamma_block: bytes, n: int):
        block_int = int.from_bytes(data_block, byteorder='big')
        gamma_int = int.from_bytes(gamma_block, byteorder='big')
        encrypted = (block_int * gamma_int) % (2 ** n)
        return encrypted.to_bytes(len(data_block), byteorder='big')

    def encryption(self):
        data_blocks = split_into_blocks(self.data)
        gamma_blocks = split_into_blocks(self.gamma)
        n = 64  # Используем N = 64 (размер блока в битах)
        encrypted_data = b''
        for i in range(len(data_blocks)):
            encrypted_block = self.encrypt_block(data_blocks[i], gamma_blocks[i], n)
            encrypted_data += encrypted_block

        return encrypted_data

class GammaDecryptor:
    def __init__(self, data: bytes, gamma: bytes):
        self.data = data
        self.gamma = gamma

    @staticmethod
    def extended_gcd(a, b):
        """Расширенный алгоритм Евклида для нахождения обратного элемента."""
        if a == 0:
            return b, 0, 1
        else:
            g, x, y = GammaDecryptor.extended_gcd(b % a, a)
            return g, y - (b // a) * x, x

    @staticmethod
    def modinv(a, mod):
        """Находит мультипликативный обратный элемент по модулю."""
        g, x, _ = GammaDecryptor.extended_gcd(a, mod)
        if g != 1:
            raise ValueError(f"Обратный элемент не существует для a={a}, mod={mod}")
        else:
            return x % mod

    @staticmethod
    def decrypt_block(data_block: bytes, gamma_block: bytes, n: int):
        block_int = int.from_bytes(data_block, byteorder='big')
        gamma_int = int.from_bytes(gamma_block, byteorder='big')

        gamma_inv = GammaDecryptor.modinv(gamma_int, 2 ** n)

        decrypted = (block_int * gamma_inv) % (2 ** n)
        return decrypted.to_bytes(len(data_block), byteorder='big')

    def decryption(self):
        data_blocks = split_into_blocks(self.data)
        gamma_blocks = split_into_blocks(self.gamma)
        n = 64  # Используем N = 64 (размер блока в битах)
        decrypted_data = b''
        for i in range(len(data_blocks)):
            try:
                decrypted_block = self.decrypt_block(data_blocks[i], gamma_blocks[i], n)
                decrypted_data += decrypted_block
            except ValueError as e:
                print(f"Ошибка при дешифровании блока {i}: {e}")
                return None  # Прерываем дешифрование при ошибке

        return unpad_data(decrypted_data)  # Убираем дополнение