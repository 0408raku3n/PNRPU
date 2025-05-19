import tkinter as tk
from tkinter import messagebox

class CRC4App(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Проверка правильности передачи - CRC4")
        self.icon = tk.PhotoImage(file="icon.png")
        self.iconphoto(False, self.icon)

        self.bits_array = []
        self.crc4_checksum = 0
        self.text_bits = ''

        self.transferred_text_bits = ''

        self.create_widgets()

    def create_widgets(self):
        text_label = tk.Label(self, text="Введите текст:", font=("Robot", 12, "bold"), fg='black')
        text_label.grid(row=0, column=0, sticky='E', pady=10)
        self.text_text = tk.Text(self, font=("Robot", 12, "bold"), fg='black', height=5)
        self.text_text.grid(row=0, column=1, pady=10)

        tobit_btn = tk.Button(self, text="Перевести в бинарный вид", font=("Robot", 10, "bold"), command=self.text_to_bits, bg='#34685c')
        tobit_btn.grid(row=1, column=1, sticky='N', pady=10)

        bit_label = tk.Label(self, text="Передаваемое сообщение:", font=("Robot", 12, "bold"), fg='black')
        bit_label.grid(row=2, column=0, sticky='E', pady=10)
        self.bit_text = tk.Text(self, font=("Robot", 12, "bold"), fg='black', height=5)
        self.bit_text.grid(row=2, column=1, pady=10)

        calc_btn = tk.Button(self, text="Рассчитать контрольную \nсумму CRC4", font=("Robot", 10, "bold"), command=self.calculate_crc, bg='#34685c')
        calc_btn.grid(row=3, column=1, sticky='N', pady=10)

        crc_label = tk.Label(self, text="CRC:", font=("Robot", 12, "bold"), fg='black')
        crc_label.grid(row=4, column=0, sticky='E', pady=10)
        self.crc4_text = tk.Text(self, font=("Robot", 12, "bold"), fg='black', height=1)
        self.crc4_text.grid(row=4, column=1, pady=10)

        transfer_data_btn = tk.Button(self, text="Передать данные", font=("Robot", 10, "bold"), command=self.transfer_data, bg='#34685c')
        transfer_data_btn.grid(row=5, column=1, sticky='N', pady=10)

        get_label = tk.Label(self, text="Получаемое сообщение:", font=("Robot", 12, "bold"), fg='black')
        get_label.grid(row=6, column=0, sticky='E', pady=10)
        self.transferred_text = tk.Text(self, font=("Robot", 12, "bold"), fg='black', height=5)
        self.transferred_text.grid(row=6, column=1, pady=10)

        check_btn = tk.Button(self, text="Проверка данных", font=("Robot", 10, "bold"), command=self.check_sum, bg='#34685c')
        check_btn.grid(row=7, column=1, sticky='N', pady=10)

    @staticmethod
    def crc4(data, polynomial=0b10011):
        crc = 0  # Инициализация регистра CRC (4 бита)
        for byte in data:
            crc ^= byte  # Добавляем байт данных
            for _ in range(8):  # Обрабатываем каждый бит
                if crc & 0b1000:  # Если старший бит CRC равен 1
                    crc = (crc << 1) ^ polynomial
                else:
                    crc <<= 1
                crc &= 0b1111  # Ограничиваем 4 битами
        return crc

    @staticmethod
    def bytes_to_bits(data):
        return [int(bit) for bit in ''.join(format(byte, '08b') for byte in data)]

    def text_to_bits(self):
        text = self.text_text.get("1.0", "end")
        text_bytes = text.encode('utf-8')
        text_bits = self.bytes_to_bits(text_bytes)
        self.text_bits = ''.join(map(str, text_bits))
        self.bit_text.replace('1.0', 'end', self.text_bits)

        for i in range(0, len(self.text_bits), 4):
            self.bits_array.append(int(self.text_bits[i:i + 4], 2))

    def calculate_crc(self, polynomial=0b10011):
        crc = CRC4App.crc4(self.bits_array)
        self.crc4_checksum = str(bin(crc))[2:]

        self.crc4_text.replace('1.0', 'end', self.crc4_checksum)
        self.crc4_text.config(state='disabled')

    def transfer_data(self):
        self.transferred_text_bits = self.text_bits + str(self.crc4_checksum)
        self.transferred_text.replace('1.0', 'end', self.transferred_text_bits)

    def check_sum(self):
        self.transferred_text_bits = self.transferred_text.get('1.0', 'end')[:-1]
        transf_bits_array = []
        for i in range(0, len(self.transferred_text_bits), 4):
            transf_bits_array.append(int(self.transferred_text_bits[i:i + 4], 2))

        crc = CRC4App.crc4(transf_bits_array)
        if crc == 0:
            message = "Сообщение передано без ошибок!"
        else:
            message = "Сообщение передано с ошибками!"
        messagebox.showinfo(title="Проверка передачи", message=message)

if __name__ == "__main__":
    app = CRC4App()
    app.mainloop()