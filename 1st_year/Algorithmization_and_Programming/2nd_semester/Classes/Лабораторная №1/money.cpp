#include <iostream>
#include "./money.h"

using namespace std;

void money::Read()
{
	int tmp;
	cout << "Enter denomination of the bill (1, 2, 5, 10, 50, 100, 500, 1000, 5000): \n";
	start:
	cin >> tmp;
	if (tmp != 1 && tmp != 2 && tmp != 5 && tmp != 10 && tmp != 50 && tmp != 100 && tmp != 500 && tmp != 1000 && tmp != 5000)
	{
		cout << "You entered wrong denomination of the bill, enter again: \n";
		goto start;
	}
	first = tmp;
	cout << "Enter number of bills: \n";
	cin >> second;
}

void money::Show()
{
	cout << "You entered " << second << " bills of " << first << " denomintaion \n";
}

int money::summa()
{
	return (first * second);
}


