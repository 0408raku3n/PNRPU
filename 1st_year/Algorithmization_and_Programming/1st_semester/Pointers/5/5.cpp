#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n; int factorial = 1;
	int* f = &factorial;

	std::cout << "Введите число:" << std::endl;
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		*f *= i;
	}

	std::cout << "Факториал числа " << n << " равен: " << factorial << std::endl;
}