def findGCD(a, b):                  # Алгоритм нахождения НОД
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return (a + b)

def main():
    print(findGCD(12, 4))

if __name__ == "__main__":
    main()