#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int N; int tmp; int max = -9999; int min = 9999;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;

		if (tmp > max)
		{
			max = tmp;
		}

		if (tmp < min)
		{
			min = tmp;
		}
	}

	cout << max + min;
}