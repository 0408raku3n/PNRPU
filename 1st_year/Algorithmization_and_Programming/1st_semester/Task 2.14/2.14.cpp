#include <iostream>
#include <string>

int main()
{
	int N, tmp, length; int sum = 0;

	std::cout << "Введите число N" << endl;
	std::cin >> N;
	
	length = std::to_string(N).length();

	for (int i = 1; i <= length; i++)
	{
		tmp = pow(10, (length - i));
		
		sum += (N / tmp);

		N %= tmp;
	}

	std::cout << "Сумма цифер числа N равна:" << sum;
}
