#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int l; int tmp; bool sign;

	cin >> l;

	for (int i = 1; i <= l; i++)
	{
		cin >> tmp;

		if (i == 1)
		{
			if (tmp > 0)
			{
				sign = true;
			}
			else
			{
				sign = false;
			}
		}
	}	

	if (sign == true)
	{
		cout << "Первее выводится положительное число";
	}
	else
	{
		cout << "Первее выводится отрицательное число";
	}
}