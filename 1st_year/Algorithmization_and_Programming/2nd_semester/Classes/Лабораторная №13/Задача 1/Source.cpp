#include <iostream>
#include <deque>
#include "Pair.h"
#include <algorithm>
using namespace std;

typedef deque<Pair> Deq;
Pair pp;

Deq make_deque(int n)
{
	Deq d;
	for (int i = 0; i < n; i++)
	{
		Pair r;
		cin >> r;
		d.push_back(r);
	}
	return d;
}

void print_deque(Deq d)
{
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

Pair arithm_avg(Deq d)
{
	Pair sum = *d.begin();
	int n = d.size();
	for (int i = 0; i < n; i++)
	{
		sum = sum + d[i];
	}
	return sum / n;
}

void add_constant(Deq& d, Pair constant)
{
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = d[i] + constant;
	}
}

struct comp_less
{
	bool operator()(Pair p1, Pair p2)
	{
		if (p1 > p2) return true;
		else return false;
	}
};

int main()
{
	int n;
	cout << "Enter number of elements:"; cin >> n;
	Deq d = make_deque(n);
	print_deque(d);

	cout << "\nTask #1:\n";
	Deq::iterator it;
	it = max_element(d.begin(), d.end());
	Pair m = *it;
	d.push_back(m);
	print_deque(d);

	cout << "\nTask #2:";
	cout << "\nEnter number of keys:"; cin >> n;
	cout << "\nEnter keys: ";
	Pair* keys = new Pair[n];
	for (int i = 0; i < n; i++) cin >> keys[i];
	for (int i = 0; i < n; i++)
	{
		int k = count(d.begin(), d.end(), keys[i]);
		if (k >= 1)
		{
			for (int j = 0; j < k; j++)
			{
				d.erase(remove(d.begin(), d.end(), keys[i]));
			}
		}
	}
	print_deque(d);

	sort(d.begin(), d.end(), comp_less());
	cout << "\nSorted in descending order:";
	print_deque(d);
	sort(d.begin(), d.end());
	cout << "\nSorted in ascending order:";
	print_deque(d);

	cout << "\nTask #3:";
	Pair c = arithm_avg(d);
	add_constant(d, c);
	print_deque(d);
}