#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int k, ...);

int main()
{
	setlocale(LC_ALL, "russian");

	int a[11] = {};
	int k;
	
	cout << "������� 4 �������� �����: ";
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	cout << "����� 4-� ��������� �����: ";
	cout << sum(4, a[0], a[1], a[2], a[3]) << endl;

	cout << "������� 9 ��������� �����: ";
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	cout << "����� 9-�� ��������� �����: ";
	cout << sum(9, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]) << endl;

	cout << "������� 11 ��������� �����: ";
	for (int i = 0; i < 11; i++)
	{
		cin >> k;
		a[i] = k;
	}
	cout << "����� 11-�� ��������� �����: ";
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