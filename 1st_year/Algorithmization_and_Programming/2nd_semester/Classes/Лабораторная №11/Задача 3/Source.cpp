#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<Pair> list(3);
	list.Print();

	cout << "\nTask #1:\n";
	list.push_back_max();
	list.Print();

	cout << "\nTask #2:";
	cout << "\nEnter number of keys: ";
	int n;
	cin >> n;
	Pair* keys = new Pair[n];
	cout << "\nEnter keys: ";
	for (int i = 0; i < n; i++)
	{
		cin >> keys[i];
	}
	list.del_keys(keys, n);
	list.Print();

	cout << "\nTask #3:\n";
	Pair c = list.arithmetic_average();
	list.add_const(c);
	list.Print();
}