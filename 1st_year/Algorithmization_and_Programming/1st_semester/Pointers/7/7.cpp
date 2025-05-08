#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	int* ptr = &n;

	std::cout << "Введите число: ";
	std::cin >> *ptr;

	std::cout << "Число равно: ";
	std::cout << n;
}