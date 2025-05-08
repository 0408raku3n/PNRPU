#include <iostream>
#include <deque>
#include <cstdlib>
#include "Pair.h"
using namespace std;
typedef deque<Pair> Deq;

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
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

void pushback_max_elem(Deq& d)
{
	Pair max(0, 0);
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] > max)
		{
			max = d[i];
		}
	}
	d.push_back(max);
}

void del_elem(Deq& d, int pos)
{
	d.erase(d.begin() + pos);
}

void del_keys(Deq& d, Pair* k, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < d.size(); j++)
		{
			if (d[j] == k[i])
			{
				del_elem(d, j);
			}
		}
	}
}

Pair arithmetic_average(Deq& d)
{
	Pair s(0, 0);
	int n = d.size();
	for (int i = 0; i < d.size(); i++)
	{
		s = s + d[i];
	}
	return s / n;
}

void add_number(Deq& d, Pair& p)
{
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = d[i] + p;
	}
}

int main()
{
	try
	{
		deque<Pair> d;
		int n;
		cout << "Enter number of elements: ";
		cin >> n;
		d = make_deque(n);
		print_deque(d);

		cout << "\nTask #1:\n";
		pushback_max_elem(d);
		print_deque(d);

		cout << "\nTask #2:\n";
		cout << "Enter number of keys:";
		cin >> n;
		Pair* keys = new Pair[n];
		cout << "\nEnter keys:";
		for (int i = 0; i < n; i++)
		{
			cin >> keys[i];
		}
		del_keys(d, keys, n);
		print_deque(d);

		cout << "\nTask #3:\n";
		Pair c = arithmetic_average(d);
		add_number(d, c);
		print_deque(d);
	}
	catch (double)
	{
		cout << "\nError!";
	}
}