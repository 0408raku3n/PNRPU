#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter number of elements:"; cin >> n;
	List<Pair> l(n);
	l.Print();

	cout << "\nTask #1:";
	cout << "\nTask's impossible, because set store only unique values, and so max value is already in set";

	cout << "\nTask #2:";
	Pair* keys = new Pair[n];
	cout << "\nEnter number of keys:"; cin >> n;
	cout << "\nEnter keys:";
	for (int i = 0; i < n; i++) cin >> keys[i];
	for (int i = 0; i < n; i++) l.del_key(keys[i]);
	l.Print();

	cout << "\nTask #3:\n";
	Pair c = l.arithm_avg();
	l.add_constant(c);
	l.Print();
}