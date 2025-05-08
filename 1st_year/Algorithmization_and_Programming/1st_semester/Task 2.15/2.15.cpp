#include <iostream>
#include <string>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	int N, tmp, length, S; bool entry = false;

	std::cin >> N >> S;
	
	length = std::to_string(N).length();

	for (int i = 1; i <= length; i++)
	{
		tmp = pow(10, (length - i));
		
		if (S == (N / tmp))
		{
			entry = true;
		}

		N %= tmp;
	}

	if (entry == true)
	{
		std::cout << "Цифра S входит в запись числа N";
	}
	else
	{
		std::cout << "Цифра S не входит в запись числа N";
	}
}