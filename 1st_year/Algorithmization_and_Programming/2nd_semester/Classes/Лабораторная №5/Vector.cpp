#include "Vector.h"

Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != 0) { delete[] beg; }
	beg = 0;
}

Vector::Vector(int n)
{
	size = n;
	beg = new Object * [n];
	cur = 0;
}

void Vector::add(Object* o)
{
	if (cur < size)
	{
		beg[cur] = o;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) { out << "Empty\n"; }
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}