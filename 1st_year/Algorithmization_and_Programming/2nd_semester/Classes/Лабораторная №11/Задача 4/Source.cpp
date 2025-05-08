#include <iostream>
#include "Pair.h"
#include <vector>
#include <stack>
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
	Vec v;
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		cout << tmp << " ";
		v.push_back(tmp);
		s.pop();
	}
	s = copyVectortoStack(v);
}

void push_back_max(St& s)
{
	Vec v;
	Pair max = s.top();
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		if (tmp > max)
		{
			max = tmp;
		}
		v.push_back(tmp);
		s.pop();
	}
	v.push_back(max);
	s = copyVectortoStack(v);
}

void del_key(St& s, Pair key)
{
	Vec v;
	Pair tmp;
	while (!s.empty())
	{
		tmp = s.top();
		if (tmp != key)
		{
			v.push_back(tmp);
		}
		s.pop();
	}
	s = copyVectortoStack(v);
}

Pair arith_avg(St& s)
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

int main()
{
	Pair p;
	St s;
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	s = make_stack(n);
	print_stack(s);

	cout << "\nTask #1: \n";
	push_back_max(s);
	print_stack(s);

	cout << "\nTask #2:";
	cout << "\nEnter number of keys: ";
	cin >> n;
	Pair* keys = new Pair[n];
	for (int i = 0; i < n; i++)
	{
		cin >> keys[i];
	}
	for (int i = 0; i < n; i++)
	{
		del_key(s, keys[i]);
	}
	print_stack(s);

	cout << "\nTask #3:\n";
	Pair c = arith_avg(s);
	add_constant(s, c);
	print_stack(s);
}