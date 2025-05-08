#include "Person.h"

Person::Person()
{
	name = " ";
	age = 0;
}

Person::~Person()
{
}

Person::Person(string n, int a)
{
	name = n;
	age = a;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

void Person::setName(string n)
{
	name = n;
}

void Person::setAge(int a)
{
	age = a;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this) { return *this; }
	name = p.name;
	age = p.age;
	return *this;
}

void Person::Show()
{
	cout << "\nName of person: " << name;
	cout << "\nAge of person: " << age << endl << endl;
}

void Person::Input()
{
	cout << "Enter name of person: "; cin >> name;
	cout << "\nEnter age of person: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
			case cmGet: cout << "\nEnter name:" << getName();
			break;
		}
	}
}