#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Russian");

	int i, n; float S, a;
	bool flag = false;

	std::cout << "¬ведите число n" << std::endl;
	std::cin >> n;

	std::cout << "¬ведите число i" << std::endl;
	std::cin >> i;

	std::cout << "¬ведите число S" << std::endl;
	std::cin >> S;
	
	for (int j = 1; j <= i; j++)
	{
		a = sin(n + j / n);

		if (a == S)
		{
			flag = true;
		}
	}

	if (flag)
	{
		std::cout << "—реди элементов есть равный S";
	}
	else
	{
		std::cout << "—реди элементов нет равного S";
	}
}