#include "Pair.h"

Pair::Pair(void)
{
	first = 0;
	second = 0;
}

Pair::~Pair(void)
{
}

Pair::Pair(int f, int s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

void Pair::setFirst(int f)
{
	first = f;
}

void Pair::setSecond(int s)
{
	second = s;
}

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) { return *this; }
	first = p.first;
	second = p.second;
	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Enter first number: ";
	in >> p.first;
	cout << "Enter second number: ";
	in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "First number: " << p.first;
	out << "\nSecond number: " << p.second << endl;
	return out;
}

int Pair::production()
{
	return (first * second);
}

void Pair::Show()
{
	cout << "\nFirst number: " << first;
	cout << "\nSecond number: " << second << endl;
}