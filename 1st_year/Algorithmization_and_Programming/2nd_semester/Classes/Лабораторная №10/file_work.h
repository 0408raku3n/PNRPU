#include "Pair.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "\nEnter number of pairs:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p);
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0;
	Pair p;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i != k) tmp << p;
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			tmp << pp;
			l++;
		}
		tmp << p;
	}
	stream.close();
	tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return l;
}

int add_end(const char* f_name, Pair pp)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << pp;
	return 1;
}

int change_file(const char* f_name, int k, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, l = 0;
	char x;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			cout << pp << "\n - is changin... Do you want to continue [y/n]?";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			tmp << pp;
			l++;
		}
		else tmp << p;
	}
	stream.close();
	tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return l;
}

int del_pair(const char* f_name, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p != pp)
		{
			tmp << p;
		}
		else tmp << p;
	}
	stream.close();
	tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return i;
}

int decrease_pair(const char* f_name, int value, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p == pp)
		{
			for (int j = 0; j < value; j++)
			{
				p--;
				--p;
			}
			tmp << p;
		}
		else tmp << p;
	}
	stream.close();
	tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return i;
}

int add_pairs(const char* f_name, int k, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	Pair ptmp;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		tmp << p;
		if (p == pp)
		{
			for (int j = 0; j < k; j++)
			{
				cin >> ptmp;
				tmp << ptmp;
			}
		}
	}
	stream.close();
	tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return i;
}