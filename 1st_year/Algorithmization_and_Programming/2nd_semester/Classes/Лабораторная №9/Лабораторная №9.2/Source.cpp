#include "Vector.h"
#include "Error.h"
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
		--x;
		cout << x;
		x--;
		cout << x;
		--x;
	}
	catch (Error e) { e.what(); }
}