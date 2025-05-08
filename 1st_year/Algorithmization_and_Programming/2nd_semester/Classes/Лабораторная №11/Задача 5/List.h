#pragma once
#include <stack>
#include <iostream>
#include <vector>
#include "Pair.h"
using namespace std;

template<class T>
class List
{
	stack<T> s;
	int len;
public:
	List();
	List(int n);
	List(const List<T>&);
	~List();

	void push_max();
	void del_key(T key);
	T arithm_avg();
	void add_constant(T constant);

	void Print();
};

template <class T>
vector<T> copyStacktoVector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

template <class T>
stack<T> copyVectortoStack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

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
		s.push(a);
	}
	len = s.size();
}

template <class T>
List<T>::List(const List<T>& l)
{
	len = l.len;
	vector<T> v = copyStacktoVector(l.s);
	s = copyVectortoStack(v);
}

template <class T>
void List<T>::Print()
{
	vector<T> v = copyStacktoVector(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	s = copyVectortoStack(v);
}

template <class T>
void List<T>::push_max()
{
	T max = s.top();
	T tmp;
	vector<T> v;
	while (!s.empty())
	{
		tmp = s.top();
		if (tmp > max) max = tmp;
		v.push_back(tmp);
		s.pop();
	}
	v.push_back(max);
	s = copyVectortoStack(v);
}

template <class T>
void List<T>::del_key(T key)
{
	T tmp;
	vector<T> v;
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

template <class T>
T List<T>::arithm_avg()
{
	T tmp;
	vector<T> v;
	int n = s.size();
	T sum;
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

template <class T>
void List<T>::add_constant(T constant)
{
	T tmp;
	vector<T> v;
	while (!s.empty())
	{
		tmp = s.top();
		tmp = tmp + constant;
		v.push_back(tmp);
		s.pop();
	}
	s = copyVectortoStack(v);
}