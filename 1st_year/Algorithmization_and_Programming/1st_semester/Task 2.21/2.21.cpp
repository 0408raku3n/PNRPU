#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n; int prevn = -999999; int k = 0;
	bool sort;

	std::cout << "Введите последовательность чисел (ввод 0 - признак окончания ввода чисел)" << std::endl;
	std::cin >> n;

	while (n != 0)
	{
		if (n <= prevn)
		{
			sort = false;
			k++;
		}

		prevn = n;
		std::cin >> n;
	}

	if (k == 0)
	{
		sort = true;
	}
	
	if (sort)
	{
		std::cout << "Упорядочены по возрастанию";
	}
	else
	{
		std::cout << "Не упорядочены по возрастанию";
	}
}