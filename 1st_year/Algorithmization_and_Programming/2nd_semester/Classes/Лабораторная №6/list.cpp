#include "list.h"
Iterator::Iterator()
{
	elem = 0;
}

Iterator::~Iterator()
{
}

Iterator::Iterator(const Iterator& iter)
{
	elem = iter.elem;
}

bool Iterator::operator==(const Iterator& iter)
{
	return elem == iter.elem;
}

bool Iterator::operator!=(const Iterator& iter)
{
	return elem != iter.elem;
}

void Iterator::operator--()
{
	elem--;
}

void Iterator::operator++()
{
	elem++;
}

int& Iterator::operator*()
{
	return *elem;
}

List::List(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size-1];
}

List::List(const List& l)
{
	size = l.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
	beg = l.beg;
	end = l.end;
}

List::~List()
{
	delete[] data;
	data = 0;
}

List& List::operator=(const List& l)
{
	if (&l == this) return *this;
	size = l.size;
	if (data != 0) delete[] data;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
	beg = l.beg;
	end = l.end;
	return *this;
}

int& List::operator[](int i)
{
	return data[i];
}

int List::operator() ()
{
	return size;
}

List List::operator+(const int k)
{
	List tmp(size, 0);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] += data[i] + k;
	}
	return tmp;
}

List List::operator+(const List& l)
{
	List tmp(size, 0);
	for (int i = 0; i < size; i++)
	{
		tmp.data[i] += data[i] + l.data[i];
	}
	return tmp;
}

ostream& operator<<(ostream& out, const List& l)
{
	for (int i = 0; i < l.size; i++)
	{
		out << l.data[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, List& l)
{
	for (int i = 0; i < l.size; i++)
	{
		in >> l.data[i];
	}
	return in;
}

Iterator List::first()
{
	return beg;
}

Iterator List::last()
{
	return end;
}