#include "Abiturient.h"

Abiturient::Abiturient()
{
	score = 0;
	spec = " ";
}

Abiturient::~Abiturient()
{
}

Abiturient::Abiturient(string n, int a, int sc, string sp):Person(n, a)
{
	score = sc;
	spec = sp;
}

Abiturient::Abiturient(const Abiturient& a)
{
	name = a.name;
	age = a.age;
	score = a.score;
	spec = a.spec;
}

void Abiturient::setScore(int sc)
{
	score = sc;
}

void Abiturient::setSpec(string sp)
{
	spec = sp;
}

Abiturient& Abiturient::operator=(const Abiturient& a)
{
	if (&a == this) return *this;
	name = a.name;
	age = a.age;
	score = a.score;
	spec = a.spec;
}

void Abiturient::Show()
{
	cout << "\nName of abiturient: " << name;
	cout << "\nAge of abiturient: " << age;
	cout << "\nScore of abiturient: " << score;
	cout << "\nSpeciality of abiturient: " << spec << endl << endl;
}

void Abiturient::Input()
{
	cout << "Enter name of abiturient: "; cin >> name;
	cout << "\nEnter age of abiturient: "; cin >> age;
	cout << "\nEnter score of abiturient: "; cin >> score;
	cout << "\nEnter speciality of abiturient: "; cin >> spec;
}