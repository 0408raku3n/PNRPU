class ArithmeticCoding:
    def __init__(self, text: str):
        self.text = text
        self.frequencies = ArithmeticCoding.get_frequencies(text)
        self.alphabet = list(set(text))
        self.segments = ArithmeticCoding.get_segments(self.alphabet, self.frequencies)

        self.code = self.coding()

    @staticmethod
    def get_frequencies(string: str) -> dict:
        symbols = set(string)
        frequencies = dict()

        for symbol in symbols:
            frequencies[symbol] = string.count(symbol) / len(string)

        return frequencies

    @staticmethod
    def get_segments(letters: list[str], frequencies: dict):
        left = 0
        segments = dict()

        for letter in letters:
            segments[letter] = (left, left + frequencies.get(letter))
            left += frequencies.get(letter)

        return segments

    def coding(self):
        left = 0
        right = 1
        for letter in self.text:
            new_left = left + (right - left) * self.segments.get(letter)[0]
            new_right = left + (right - left) * self.segments.get(letter)[1]
            left = new_left
            right = new_right

        return (left + right) / 2



class LZWAlgorithm:
    def __init__(self, string: str):
        self.data = string

        self.code = self.coding()
        self.decode = self.decoding()

    def coding(self):
        dictionary = {chr(i): i for i in range(256)}
        next_code = 256
        current_string = ""
        code = []

        for char in self.data:
            combined_string = current_string + char
            if combined_string in dictionary:
                current_string = combined_string
            else:
                code.append(dictionary[current_string])
                dictionary[combined_string] = next_code
                next_code += 1
                current_string = char

        if current_string:
            code.append(dictionary[current_string])

        return code

    def decoding(self):
        dictionary = {i: chr(i) for i in range(256)}
        next_code = 256
        current_string = chr(self.code.pop(0))
        decode = [current_string]

        for code in self.code:
            if code in dictionary:
                entry = dictionary[code]
            elif code == next_code:
                entry = current_string + current_string[0]
            else:
                raise ValueError("Invalid compressed data")

            decode.append(entry)
            dictionary[next_code] = current_string + entry[0]
            next_code += 1
            current_string = entry

        return ''.join(decode)


if __name__ == "__main__":
    file_name = 'input.txt'
    with open(file_name, 'r', encoding='utf-8') as file:
        data = file.read()

    encoder = ArithmeticCoding("Hello")
    with open('arithmetic_encoded.bin', 'w', encoding='utf-8') as file:
        file.write(str(encoder.code))

    lzw_encoder= LZWAlgorithm(str(encoder.code))
    with open('lzw_encoded.bin', 'w', encoding='utf-8') as file:
        file.write(' '.join(map(str, lzw_encoder.code)))


