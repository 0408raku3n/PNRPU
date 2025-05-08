#include "Pair.h"

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::~Pair()
{
}

Pair::Pair(int f, double s)
{
	first = f;
	second = s;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

Pair& Pair::operator=(const Pair& p)
{
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator+(double k)
{
	int tf = k + first;
	double ts = k + second;
	Pair tmp(tf, ts);
	return tmp;
}

ostream& operator<< (ostream& out, const Pair& p)
{
	out << p.first << ":" << p.second;
	return out;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "\nFirst number: "; in >> p.first;
	cout << "\nSecond number: "; in >> p.second;
	return in;
}

bool Pair::operator>(const Pair& p)
{
	if (first > p.first && second > p.second) return true;
	else if (first == p.first && second > p.second) return true;
	else if (first > p.first && second == p.second) return true;
	else return false;
}
bool Pair::operator<(const Pair& p)
{
	if (first < p.first && second < p.second) return true;
	else if (first == p.first && second < p.second) return true;
	else if (first < p.first && second == p.second) return true;
	else return false;
}

bool Pair::operator==(const Pair& p)
{
	if (first == p.first && second == p.second) return true;
	else return false;
}

bool Pair::operator!=(const Pair& p)
{
	if (*this == p) return false;
	else return true;
}

Pair Pair::operator+(const Pair& p)
{
	Pair tmp;
	tmp.first = first + p.first;
	tmp.second = second + p.second;
	return tmp;
}

Pair Pair::operator/(const Pair& p)
{
	Pair tmp;
	tmp.first = first / p.first;
	tmp.second = second / p.second;
	return tmp;
}

Pair Pair::operator/(int t)
{
	Pair tmp;
	tmp.first = first / t;
	tmp.second = second / t;
	return tmp;
}
