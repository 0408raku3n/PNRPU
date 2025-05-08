#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair
{
public:
	Pair();
	~Pair();
	Pair(int, double);
	Pair(const Pair&);

	Pair operator=(const Pair&);
	friend ostream& operator<<(ostream&, const Pair&);
	friend istream& operator>>(istream&, Pair&);
	friend fstream& operator<<(fstream&, const Pair&);
	friend fstream& operator>>(fstream&, Pair&);

	bool operator<(const Pair&);
	bool operator>(const Pair&);
	bool operator!=(const Pair&);
	bool operator==(const Pair&);

	Pair operator--();
	Pair operator--(int);
private:
	int first;
	double second;
};

