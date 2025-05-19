import os

IP = [58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7]

IP_INV = [40, 8, 48, 16, 56, 24, 64, 32,
          39, 7, 47, 15, 55, 23, 63, 31,
          38, 6, 46, 14, 54, 22, 62, 30,
          37, 5, 45, 13, 53, 21, 61, 29,
          36, 4, 44, 12, 52, 20, 60, 28,
          35, 3, 43, 11, 51, 19, 59, 27,
          34, 2, 42, 10, 50, 18, 58, 26,
          33, 1, 41, 9, 49, 17, 57, 25]

E = [32, 1,	2,	3,	4,	5,
        4,	5,	6,	7,	8,	9,
        8,	9,	10,	11,	12,	13,
        12,	13,	14,	15,	16, 17,
        16,	17,	18,	19,	20,	21,
        20,	21,	22,	23,	24,	25,
        24,	25,	26,	27,	28,	29,
        28,	29,	30,	31,	32,	1]

P = [16, 7,	20,	21,	29,	12,	28,	17,
    1,	15, 23,	26,	5,	18,	31,	10,
    2,	8,	24,	14,	32,	27,	3,	9,
    19,	13,	30,	6,	22,	11,	4,	25]

S_BOXES = [
    # S1
    [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
    ],
    # S2
    [
        [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]
    ],
    # S3
    [
        [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]
    ],
    # S4
    [
        [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]
    ],
    # S5
    [
        [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]
    ],
    # S6
    [
        [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]
    ],
    # S7
    [
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]
    ],
    # S8
    [
        [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]
    ]
]

PC1 = [57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4]

PC2 = [14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32]

SHIFTS = [
    (1 if i in [1, 2, 9, 16] else 2) for i in range(1, 17)
]

def generate_key(key_size: int):
    return os.urandom(key_size)

class DES:
    def __init__(self, d: bytes, k: bytes):
        self.block_size = 8 # Стандартный размер блока в DES
        self.key_size = 8 # Стандартный размер ключа в DES (7 байт + 1 байт проверочный)

        padded_data = DES.padding(d, self.block_size)       # Дополнение блока данных до стандарта в 8 байт
        padded_key = DES.padding(k, self.key_size)          # Дополнение блока ключа до стандарта в 8 байт

        self.data = DES.bytes_to_bits(padded_data)          # Перевод байт в биты
        self.key = DES.bytes_to_bits(padded_key)            # Перевод байт в биты
        self.sub_keys = DES.generate_sub_keys(self)         # Генерация подключей

        self.encrypted_data = DES.encrypt(self)             # Шифровка сообщения
        self.decrypted_data = DES.decrypt(self)             # Дешифровка сообщения

        decrypted_data_bytes = DES.bits_to_bytes(self.decrypted_data)  # Дешифрованное сообщение в байтах
        self.decrypted_data = DES.unpadding(decrypted_data_bytes)       # Дешифрованное сообщение без байтов дополнения

    def generate_sub_keys(self):
        key = DES.permutation(self.key, PC1)
        sub_keys = []

        left, right = key[:28], key[28:]
        for shift in SHIFTS:
            left = left[shift:] + left[:shift]
            right = right[shift:] + right[:shift]
            sub_keys.append(DES.permutation(left + right, PC2))

        return sub_keys

    def encrypt(self):
        permuted_data = DES.permutation(self.data, IP)

        left, right = permuted_data[:32], permuted_data[32:]

        for sub_key in self.sub_keys:
            new_right = DES.xor(left, DES.feistel_func(right, sub_key))
            left, right = right, new_right

        permuted_data_inv = DES.permutation(right + left, IP_INV)

        return permuted_data_inv

    def decrypt(self):
        permuted_data = DES.permutation(self.encrypted_data, IP)

        left, right = permuted_data[:32], permuted_data[32:]

        for sub_key in self.sub_keys[::-1]:
            new_right = DES.xor(left, DES.feistel_func(right, sub_key))
            left, right = right, new_right

        permuted_data_inv = DES.permutation(right + left, IP_INV)

        return permuted_data_inv

    @staticmethod
    def bytes_to_bits(d):
        return [int(bit) for bit in ''.join(format(byte, '08b') for byte in d)]

    @staticmethod
    def bits_to_bytes(bit_array):
        bit_string = ''.join(map(str, bit_array))

        # Разделяем строку на группы по 8 бит
        byte_strings = [bit_string[i:i + 8] for i in range(0, len(bit_string), 8)]

        # Преобразуем каждую группу бит в байт
        byte_array = bytes(int(byte_str, 2) for byte_str in byte_strings)

        return byte_array

    @staticmethod
    def padding(data: bytes, size: int):
        padding_length = size - len(data)
        padding_bytes = bytes([padding_length] * padding_length)
        return data + padding_bytes

    @staticmethod
    def unpadding(data: bytes):
        padding_length = data[-1]
        return data[:-padding_length]

    @staticmethod
    def permutation(data: list[int], table: list[int]):
        return [data[i - 1] for i in table]

    @staticmethod
    def xor(bit_array1: list[int], bit_array2: list[int]):
        return [bit1 ^ bit2 for bit1, bit2 in zip(bit_array1, bit_array2)]

    @staticmethod
    def s_box_lookup(i: int, bit_array: list[int]):
        row = (bit_array[0] << 1) | bit_array[5]
        col = (bit_array[1] << 3) | (bit_array[2] << 2) | (bit_array[3] << 1) | bit_array[4]
        s_box_value = S_BOXES[i][row][col]
        return [int(bit) for bit in f"{s_box_value:04b}"]

    @staticmethod
    def feistel_func(right: list[int], sub_key: list[int]):
        expanded = DES.permutation(right, E)
        xor_expanded = DES.xor(expanded, sub_key)

        sbox_output = []
        for i in range(8):
            sbox_output += DES.s_box_lookup(i, xor_expanded[i * 6: (i + 1) * 6])

        return DES.permutation(sbox_output, P)

if __name__ == "__main__":
    data = b'\xd0\x9f\xd1\x80\xd0\xb8\xd0\xb2\xd0\xb5\xd1\x82'
    key = generate_key(2)

    data_blocks = []
    for i in range(0, len(data), 2):
        data_blocks.append(data[i:(i + 2)])
    print('Original blocks:', data_blocks)

    encrypted_blocks = []
    decrypted_blocks = []
    for block in data_blocks:
        des_encoder = DES(block, key)
        encrypted_blocks.append(des_encoder.encrypted_data)
        decrypted_blocks.append(des_encoder.decrypted_data)

    print('Encrypted blocks', encrypted_blocks)
    print('Decrypted blocks', decrypted_blocks)



