#include <iostream>
#include "Pair.h"
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Pair> St;
typedef vector<Pair> Vec;

St make_stack(int n)
{
	St s;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		s.push(p);
	}
	return s;
}

Vec copyStacktoVector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St copyVectortoStack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

void print_stack(St s)
{
	cout << endl;
	Vec v;
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		cout << tmp << " ";
		v.push_back(tmp);
		s.pop();
	}
	cout << endl;
	s = copyVectortoStack(v);
}

Pair max_elem(St s)
{
	Vec v = copyStacktoVector(s);
	Vec::iterator it = max_element(v.begin(), v.end());
	return *it;
}

void del_elem(St s, Pair p)
{
	Vec v;
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		if (tmp != p)
		{
			v.push_back(tmp);
		}
		s.pop();
	}
	s = copyVectortoStack(v);
}

Pair arithm_avg(St s)
{
	Vec v;
	Pair tmp;
	Pair sum;
	int n = s.size();
	while (!s.empty())
	{
		tmp = s.top();
		sum = sum + tmp;
		v.push_back(tmp);
		s.pop();
	}
	s = copyVectortoStack(v);
	return sum / n;
}

void add_constant(St& s, Pair p)
{
	Vec v;
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		tmp = tmp + p;
		v.push_back(tmp);
		s.pop();
	}
	s = copyVectortoStack(v);
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
	St s = make_stack(n);
	print_stack(s);

	cout << "\nTask #1:\n";
	Pair m = max_elem(s);
	Vec copy = copyStacktoVector(s);
	copy.push_back(m);
	s = copyVectortoStack(copy);
	print_stack(s);

	cout << "\nTask #2:";
	cout << "\nEnter number of keys:"; cin >> n;
	cout << "\nEnter keys: ";
	Pair* keys = new Pair[n];
	for (int i = 0; i < n; i++) cin >> keys[i];
	copy = copyStacktoVector(s);
	for (int i = 0; i < n; i++)
	{
		int k = count(copy.begin(), copy.end(), keys[i]);
		if (k >= 1)
		{
			for (int j = 0; j < k; j++)
			{
				del_elem(s, keys[i]);
			}
		}
	}
	print_stack(s);

	sort(copy.begin(), copy.end(), comp_less());
	s = copyVectortoStack(copy);
	cout << "\nSorted in descending order:\n";
	print_stack(s);

	sort(copy.begin(), copy.end());
	s = copyVectortoStack(copy);
	cout << "\nSorted in ascending order:\n";
	print_stack(s);

	cout << "\nTask #3:";
	Pair c = arithm_avg(s);
	add_constant(s, c);
	print_stack(s);
}