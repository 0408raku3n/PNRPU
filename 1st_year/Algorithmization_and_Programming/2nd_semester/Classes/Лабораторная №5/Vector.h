#pragma once
#include "./Object.h"
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();

	void add(Object*);
	friend ostream& operator<<(ostream& out,const Vector& v);
private:
	Object** beg;
	int size;
	int cur;
};

