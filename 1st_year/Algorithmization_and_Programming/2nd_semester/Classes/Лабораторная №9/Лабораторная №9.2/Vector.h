#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class Vector
{
	int size;
	int* beg;
public:
	Vector();
	Vector(int);
	Vector(int, int*);
	Vector(const Vector&);
	~Vector();

	const Vector& operator=(const Vector&);
	int operator[](int);
	Vector operator--();
	Vector operator--(int);

	int operator()();

	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
};
