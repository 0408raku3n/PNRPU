#include <iostream>
using namespace std;

template <class T>
class List
{
public:
	List(int, T);
	List(const List<T>&);
	~List();

	List& operator=(const List<T>&);
	T& operator[](int);
	List operator+(const T);
	List operator+(const List<T>&);
	int operator()();

	friend istream& operator>> <>(istream& in, List<T>& l);
	friend ostream& operator<< <>(ostream& out, const List<T>& l);
private:
	int size;
	T* data;
};

template <class T>
List<T>::List(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <class T>
List<T>::List(const List<T>& l)
{
	size = l.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
}

template <class T>
List<T>::~List()
{
	delete[] data;
	data = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l)
{
	if (this == &l) { return *this; }
	size = l.size;
	if (data != 0) { delete[] data; }
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
	return *this;
}

template <class T>
T& List<T>::operator[](int i)
{
	return data[i];
}

template <class T>
List<T> List<T>::operator+(const T k)
{
	List<T> tmp(size, 0);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] = data[i] + k;
	}
	return tmp;
}

template <class T>
List<T> List<T>::operator+(const List<T>& l)
{
	List<T> tmp(size, 0);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] += data[i] + l.data[i];
	}
	return tmp;
}

template <class T>
int List<T>::operator()()
{
	return size;
}

template <class T>
istream& operator>>(istream& in, List<T>& l)
{
	for (int i = 0; i < l.size; ++i)
	{
		in >> l.data[i];
	}
	return in;
}

template <class T>
ostream& operator<<(ostream& out, const List<T>& l)
{
	for (int i = 0; i < l.size; ++i)
	{
		out << l.data[i] << " ";
	}
	return out;
}
