#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n; int r = 0;

	std::cout << "Введите число N:";
	std::cin >> n;

	while (n > 0)
	{
		r = r * 10 + n % 10;
		n /= 10;
	}
	std::cout << "Перевернутое число N:" << r << std::endl;
}