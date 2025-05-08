#pragma once
#include <deque>
#include <iostream>
#include "Pair.h"
using namespace std;

template<class T>
class List
{
	deque<T> d;
	int len;
public:
	List();
	List(int n);
	~List();

	void Print();
	void push_back_max();
	void del_keys(T*, int);
	void del_elem(int);
	void add_const(T);
	T arithmetic_average();
};

template <class T>
List<T>::List()
{
	len = 0;
}

template <class T>
List<T>::~List()
{
}

template <class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		d.push_back(a);

	}
	len = d.size();
}

template <class T>
void List<T>::Print()
{
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

template <class T>
T List<T>::arithmetic_average()
{
	T s(0, 0);
	int n = d.size();
	for (int i = 1; i < d.size(); i++)
	{
		s = s + d[i];
	}
	return s / n;
}

template <class T>
void List<T>::push_back_max()
{
	T max = d[0];
	for (int i = 1; i < d.size(); i++)
	{
		if (d[i] > max) max = d[i];
	}
	d.push_back(max);
}

template <class T>
void List<T>::del_keys(T* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < d.size(); j++)
		{
			if (p[i] == d[j])
			{
				del_elem(j);
			}
		}
	}
}

template <class T>
void List<T>::del_elem(int pos)
{
	d.erase(d.begin() + pos);
}

template <class T>
void List<T>::add_const(T t)
{
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = d[i] + t;
	}
}

