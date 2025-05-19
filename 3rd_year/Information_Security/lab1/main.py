from tkinter import *
from tkinter.messagebox import showerror

A = 1
B = 0
m = 26

def GCD(a, b):                  # Алгоритм нахождения НОД
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return (a + b)

def is_relatively_prime(a, b):
    if GCD(a, m) != 1:
        showerror(title="Ошибка", message=f"Числа a = {a} и m = {m} НЕ взаимно простые. Попробуйте еще раз!")
        return
    else:
        global A
        A = a
        global B
        B = b
        encryption_btn.config(state="normal")
        return
        

def encryption(a, b, text):        # Логика шифрования
    alphabet = ['a', 'b', 'c', 'd', 'e', 'f',
                'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    
    cypher = []
    for i in range(len(alphabet)):              # Шифрование числовых кодов алфавита
        index = (a * i + b) % m
        cypher.append(index)
    
    cypher_alphabet = []
    for c in cypher:                            # Преобразование кодов шифра в шифрованный алфавит
        cypher_alphabet.append(alphabet[c])

    cyphered_text = ''
    for letter in text:
        if letter.isalpha():
            index_alphabet = alphabet.index(letter.lower())
            is_capital = letter.isupper()
            if is_capital:
                cyphered_letter = cypher_alphabet[index_alphabet].upper()
            else:
                cyphered_letter = cypher_alphabet[index_alphabet]
            cyphered_text += cyphered_letter
        else:
            cyphered_text += letter
    label5.config(text=cyphered_text)

root = Tk()
root.title("Шифрование аффинной системой подстановок Цезаря")
icon = PhotoImage(file="InfBez\lab1\icon.png")
root.iconphoto(False, icon)
root.geometry("600x480+350+150")

label_header = Label(text=f"Лабораторная работа №1, в. 23", font=("Roboto", 20))
label_top = Label(text=f"Число m = {m}", font=("Roboto", 16))
label1 = Label(text="Введите a:", font=("Roboto", 16))
spinbox1 = Spinbox(from_=1.0, to=1000, font=("Roboto", 16), width=5)
label2 = Label(text="Введите b:", font=("Roboto", 16))
spinbox2 = Spinbox(from_=0.0, to=1000, font=("Roboto", 16), width=5)
label3 = Label(text="Введите текст для шифрования:", font=("Roboto", 14))
entry1 = Entry(font=("Roboto", 14), width=40)
label5 = Label(text="", font=("Roboto", 14))
encryption_btn = Button(text="Зашифровать", font=("Roboto", 12), state="disabled", command=lambda: encryption(A, B, entry1.get()))
confirm_btn = Button(text="Подтвердить", font=("Roboto", 12), command=lambda: is_relatively_prime(int(spinbox1.get()), int(spinbox2.get())))
label4 = Label(text="Зашифрованный текст:", font=("Roboto", 14))
label6 = Label(text="Выполнил студент группы АСУ-22-1б", font=("Roboto", 14))
label7 = Label(text="Хамидуллин Даниил Ринатович", font=("Roboto", 14))

label_header.place(x=0,y=0)
label_top.place(x=0,y=40)
label1.place(x=0,y=80)
spinbox1.place(x=115,y=80)
label2.place(x=0,y=120)
spinbox2.place(x=115,y=120)
confirm_btn.place(x=30,y=160)
label3.place(x=0,y=200)
entry1.place(x=0,y=240)
encryption_btn.place(x=30,y=280)
label4.place(x=0,y=320)
label5.place(x=0,y=360)
label6.place(x=0,y=400)
label7.place(x=0,y=430)

root.mainloop()