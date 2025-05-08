#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int n; int product = 1; int sum = 0;

	begin:

	cout << "¬ведите натуральное число N" << endl;
	cin >> n;

	if (n < 1)
	{
		cout << "¬ведено неверное число N" << endl;
		goto begin;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			product = product * i;
			for (int j = 1; j <= i; j++)
			{
				product = product * (i + j);
			}
			sum = sum + product;
			product = 1;
		}
	}


	cout << sum;
}