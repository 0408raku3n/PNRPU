#include <iostream>
#include <set>
#include "Pair.h"
using namespace std;
typedef set<Pair, less<Pair>> TSet;
typedef TSet::iterator it;

TSet make_set(int n)
{
	TSet s;
	Pair a;
	cout << "\nEnter data:";
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(TSet s)
{
	for (it i = s.begin(); i != s.end(); i++)
	{
		cout << *i << " ";
	}
}

Pair arithm_avg(TSet s)
{
	Pair sum(0, 0);
	int n = s.size();
	for (it i = s.begin(); i != s.end(); i++)
	{
		sum = sum + *i;
	}
	return sum / n;
}

TSet add_constant(TSet s, Pair constant)
{
	int iv = 0;
	Pair* m = new Pair[s.size()];
	for (it i = s.begin(); i != s.end(); i++)
	{
		m[iv] = constant + *i;
		iv++;
	}
	TSet tmp(m, m + s.size());
	return tmp;
}

int main()
{
	int n;
	cout << "Enter number of elements:";
	cin >> n;
	TSet s = make_set(n);
	print_set(s);

	cout << "\nTask #1:";
	cout << "\nTask's impossible, because set store only unique values, and so max value is already in set";

	cout << "\nTask #2:";
	cout << "\nEnter number of keys:";
	cin >> n;
	Pair* keys = new Pair[n];
	cout << "\nEnter keys:";
	for (int i = 0; i < n; i++) cin >> keys[i];
	for (int i = 0; i < n; i++) s.erase(keys[i]);
	print_set(s);

	cout << "\nTask #3:\n";
	Pair c = arithm_avg(s);
	TSet s2 = add_constant(s, c);
	print_set(s2);
}

