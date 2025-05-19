import DES

def des_encrypt(block: bytes, key):
    des_encoder = DES.DES(block, key)
    encrypted_block = des_encoder.bits_to_bytes(des_encoder.encrypted_data)
    return encrypted_block

def compress_function(block, state):
    encrypted_block = des_encrypt(block, state)
    new_state = bytes([s ^ e for s, e in zip(state, encrypted_block)])
    return new_state

def merkle_damgard(data, block_size=8, initial_state=None):
    if initial_state is None:
        # Начальное состояние (IV) — нулевой блок
        initial_state = b'\x00' * block_size

    # Разбиваем данные на блоки
    blocks = [data[i:i + block_size] for i in range(0, len(data), block_size)]

    # Инициализируем состояние
    state = initial_state

    # Применяем сжимающую функцию к каждому блоку
    for block in blocks:
        state = compress_function(block, state)

    # Возвращаем финальный хеш
    return state