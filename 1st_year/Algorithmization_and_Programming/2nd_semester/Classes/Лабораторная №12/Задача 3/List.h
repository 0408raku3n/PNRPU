#pragma once
#include <iostream>
#include <set>
using namespace std;

template <class T>
class List
{
	set<T, less<T>> s;
	int len;
public:
	List();
	List(int n);
	~List();

	void Print();
	void del_key(T key);
	T arithm_avg();
	void add_constant(T constant);
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
		s.insert(a);

	}
	len = s.size();
}

template <class T>
void List<T>::Print()
{
	for (T i : s)
	{
		cout << i << " ";
	}
}

template <class T>
void List<T>::del_key(T key)
{
	s.erase(key);
}

template <class T>
T List<T>::arithm_avg()
{
	T sum(0, 0);
	int n = s.size();
	for (T i : s)
	{
		sum = sum + i;
	}
	return sum / n;
}

template <class T>
void List<T>::add_constant(T constant)
{
	int iv = 0;
	T* m = new T[s.size()];
	for (T i : s)
	{
		m[iv] = i + constant;
		iv++;
	}
	set<T> tmp(m, m + s.size());
	s = tmp;
}