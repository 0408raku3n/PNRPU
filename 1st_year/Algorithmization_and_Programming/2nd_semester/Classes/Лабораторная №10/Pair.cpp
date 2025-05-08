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

Pair Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << ":" << p.second;
	return out;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "\nEnter first number:"; in >> p.first;
	cout << "\nEnter second number:"; in >> p.second;
	return in;
}

fstream& operator<<(fstream& fout, const Pair& p)
{
	fout << p.first << ":";
	fout << p.second << "\n";
	return fout;
}

fstream& operator>>(fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}

bool Pair::operator<(const Pair& p)
{
	if ((first < p.first) && (second < p.second)) return true;
	else return false;
}

bool Pair::operator>(const Pair& p)
{
	if ((first > p.first) && (second > p.second)) return true;
	else return false;
}

bool Pair::operator!=(const Pair& p)
{
	if (first != p.first && second != p.second) return true;
	else return false;
}

bool Pair::operator==(const Pair& p)
{
	if (first == p.first && second == p.second) return true;
	else return false;
}

Pair Pair::operator--()
{
	first--;
	return *this;
}

Pair Pair::operator--(int k)
{
	second -= k;
	return *this;
}

