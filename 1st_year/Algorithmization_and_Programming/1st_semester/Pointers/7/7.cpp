#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	int* ptr = &n;

	std::cout << "������� �����: ";
	std::cin >> *ptr;

	std::cout << "����� �����: ";
	std::cout << n;
}