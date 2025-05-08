#include <iostream>
#include "./money.h"

using namespace std;

int main()
{
	money A;

	A.Read();
	A.Show();
	cout << "Sum of money: " << A.summa();
}