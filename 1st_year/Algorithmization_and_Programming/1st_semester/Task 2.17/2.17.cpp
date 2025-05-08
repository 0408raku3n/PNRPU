#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int x, n; float sum = 0; int factorial = 1;

	std::cout << "¬ведите число x" << std::endl;
	std::cin >> x;

	std::cout << "¬ведите число n" << std::endl;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			factorial *= i;
		}
		
		sum += (pow(x, i) / factorial);
	}

	std::cout << "«начение многочлена равно:" << sum << std::endl;

}