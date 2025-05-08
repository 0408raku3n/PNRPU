#include <iostream>

using namespace std;

int main()
{
	int l; int max = 0; int tmp;

	cin >> l;

	for (int i = 1; i <= l; i++)
	{
		cin >> tmp;

		if (tmp > max)
		{
			max = tmp;
		}
	}

	cout << max;
}