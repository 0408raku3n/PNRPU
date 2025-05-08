#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, tmp;

	int* pointer1;
	int* pointer2;

	std::cout << "¬ведите первое число: " << std::endl;
	std::cin >> n;
	pointer1 = &n;
	tmp = *pointer1;

	std::cout << "¬ведите второе число: " << std::endl;
	std::cin >> n;
	pointer2 = &n;
	*pointer1 = *pointer2;
	*pointer2 = tmp;

	std::cout << *pointer1 << std::endl;
	std::cout << *pointer2 << std::endl;
}