#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, min, max;
	int* ptr1 = &tmp;

	std::cout << "Введите длину последовательности: " << std::endl;
	std::cin >> n;

	std::cout << "Введите первое число: " << std::endl;
	std::cin >> *ptr1;

	min = *ptr1;
	max = *ptr1;

	for (int i = 1; i <= n; i++)
	{
		std::cin >> *ptr1;
		if (*ptr1 > max)
		{
			max = *ptr1;
		}
		else if (*ptr1 < min)
		{
			min = *ptr1;
		}
	}

	std::cout << "Минимальный элемент: " << std::endl;
	std::cin >> min;
	std::cout << "Максимальный элемент: " << std::endl;
	std::cin >> max;

}