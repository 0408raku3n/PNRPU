#include <iostream>
#include "./Time.h"
using namespace std;

Time::Time()
{
	min = 0;
	sec = 0;
	cout << "Construstor without parameters: " << this << endl;
}

Time::Time(int m, int s)
{
	min = m;
	sec = s;
	cout << "Construstor with parameters: " << this << endl;
}

Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
	cout << "Copy constructor: " << this << endl;
}

Time::~Time()
{
	cout << "Destructor:  " << this << endl;
}

int Time::getMin()
{
	return min;
}

int Time::getSec()
{
	return sec;
}

void Time::setMin(int m)
{
	min = m;
}

void Time::setSec(int s)
{
	sec = s;
}

Time& Time::operator=(const Time& t)
{
	if (&t == this)
	{
		return *this;
	}

	min = t.min;
	sec = t.sec;
	return *this;
}

Time& Time::operator--()
{
	int tmp;
	tmp = min * 60 + sec;
	tmp--;
	min = tmp / 60;
	sec = tmp % 60;
	return *this;
}

Time Time::operator--(int)
{
	int tmp;
	tmp = min * 60 + sec;
	tmp--;
	Time t(min, sec);
	min = tmp / 60;
	sec = tmp % 60;
	return t;
}

Time& Time::operator++()
{
	int tmp;
	tmp = min * 60 + sec;
	tmp++;
	min = tmp / 60;
	sec = tmp % 60;
	return *this;
}

Time Time::operator++(int)
{
	int tmp;
	tmp = min * 60 + sec;
	tmp++;
	Time t(min, sec);
	min = tmp / 60;
	sec = tmp % 60;
	return t;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "Enter minutes: ";
	in >> t.min;
	cout << endl;

	cout << "Enter seconds: ";
	in >> t.sec;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << ":" << t.sec);
}