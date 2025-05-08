#include <iostream>
#include <stack>
#include <vector>
#include "List.h"
using namespace std;

int main()
{
	List<Pair> l(3);
	l.Print();

	cout << "\nTask #1:\n";
	l.push_max();
	l.Print();

	cout << "\nTask #2:";
	int n;
	cout << "\nEnter number of keys:"; cin >> n;
	Pair* keys = new Pair[n];
	cout << "\nEnter keys: ";
	for (int i = 0; i < n; i++)
	{
		cin >> keys[i];
	}
	for (int i = 0; i < n; i++)
	{
		l.del_key(keys[i]);
	}
	l.Print();

	cout << "\nTask #3:\n";
	Pair c = l.arithm_avg();
	l.add_constant(c);
	l.Print();
}