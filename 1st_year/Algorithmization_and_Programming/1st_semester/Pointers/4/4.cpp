#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n, min, max;
	int* ptr1 = &tmp;

	std::cout << "������� ����� ������������������: " << std::endl;
	std::cin >> n;

	std::cout << "������� ������ �����: " << std::endl;
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

	std::cout << "����������� �������: " << std::endl;
	std::cin >> min;
	std::cout << "������������ �������: " << std::endl;
	std::cin >> max;

}