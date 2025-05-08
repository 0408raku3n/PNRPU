#include <iostream>

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");

	char star = '*'; char space = ' '; int n;

	begin:

	cout << "¬ведите натуральное число N, большее 2" << endl;

	cin >> n;
	
	int nstar = n; int nspace = 0;

	if (n <= 2)
	{
		cout << "¬ведено неверное число N" << endl;

		goto begin;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= nstar; j++)
			{
				cout << star;
			}
			for (int j = 1; j <= nspace; j++)
			{
				cout << space;
			}
			
			cout << endl;

			nstar = nstar - 1;
			nspace = nspace + 1;
		
		}
	}



}