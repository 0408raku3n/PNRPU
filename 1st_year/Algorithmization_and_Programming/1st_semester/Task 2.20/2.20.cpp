#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Russian");

	int i, n; float S, a;
	bool flag = false;

	std::cout << "������� ����� n" << std::endl;
	std::cin >> n;

	std::cout << "������� ����� i" << std::endl;
	std::cin >> i;

	std::cout << "������� ����� S" << std::endl;
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
		std::cout << "����� ��������� ���� ������ S";
	}
	else
	{
		std::cout << "����� ��������� ��� ������� S";
	}
}