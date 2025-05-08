#include "./Vector.h"
#include <iostream>
using namespace std;

int main()
{
	try
	{
		Vector x(2);
		cout << x;
		cout << "\nEnter number: ";
		int i;
		cin >> i;

		cout << x[i] << endl;
		cout << x() << endl;
		--x;
		cout << x;
		--x;
		cout << x;
		x--;
	}
	catch(int)
	{
		cout << "\n\nERROR!!!" << endl;
	}
	return 0;
}
