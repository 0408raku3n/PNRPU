#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int k, ...);

int main()
{
	setlocale(LC_ALL, "russian");

	int a[11] = {};
	int k;
	
	cout << "¬ведите 4 элемента суммы: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	cout << "—умма 4-х элементов равна: ";
	cout << sum(4, a[0], a[1], a[2], a[3]) << endl;

	cout << "¬ведите 9 элементов суммы: ";
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	cout << "сумма 9-ти элементов равна: ";
	cout << sum(9, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]) << endl;

	cout << "введите 11 элементов суммы: ";
	for (int i = 0; i < 11; i++)
	{
		cin >> k;
		a[i] = k;
	}
	cout << "сумма 11-ти элементов равна: ";
	cout << sum(11, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]) << endl;
}
int sum(int k, ...)
{
	int s = 0;
	va_list args;
	va_start(args, k);
	for (int i = 0; i < k; i++)
	{
		s += va_arg(args, int);
	}
	va_end(args);
	
	return s;
}