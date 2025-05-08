
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int N; int sum = 0;

	std::cout << "¬ведите число N слагаемых: ";
	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			sum -= i;
		}
		else
		{
			sum += i;
		}
	}

	std::cout << "—умма равна: " << sum;
}