#include "Rightangled.h"

Rightangled::Rightangled(void) :Pair()
{
}

Rightangled::~Rightangled(void)
{
}

Rightangled::Rightangled(int f, int s) :Pair(f, s)
{
}

Rightangled::Rightangled(const Rightangled& r)
{
	first = r.first;
	second = r.second;
}

Rightangled& Rightangled::operator=(const Rightangled& r)
{
	if (&r == this) { return *this; }
	first = r.first;
	second = r.second;
	return *this;
}

istream& operator>>(istream& in, Rightangled& r)
{
	cout << "\nEnter first cathet: ";
	in >> r.first;
	cout << "Enter second cathet: ";
	in >> r.second;
	return in;
}

ostream& operator<<(ostream& out, const Rightangled& r)
{
	out << "First cathet: " << r.first;
	out << "\nSecond cathet: " << r.second;
	return out;
}

int Rightangled::calculatingHypotenuse()
{
	return (pow((pow(first, 2) + pow(second, 2)), 0.5));
}

void Rightangled::Show()
{
	cout << "\nFirst cathet: " << first;
	cout << "\nSecond cathet: " << second << endl;
}