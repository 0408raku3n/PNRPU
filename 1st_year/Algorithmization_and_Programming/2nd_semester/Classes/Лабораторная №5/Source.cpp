#include "./Object.h"
#include "./Pair.h"
#include  "./Rightangled.h"
#include "./Vector.h"
#include <iostream>
using namespace std;

int main()
{
	Pair p;
	cin >> p;
	cout << "Pair:\n" << p;
	
	Object* pp = &p;
	cout << "\nPair by virtual class:";
	pp->Show();										//print by virtual class

	int tmp;
	cout << "\nEnter number to change first number: ";
	cin >> tmp;
	p.setFirst(tmp);

	cout << "Enter number to change second number: ";
	cin >> tmp;
	p.setSecond(tmp);
	cout << "Pair:\n" << p;

	cout << "Production of first and second numbers: " << p.production() << endl;

	Rightangled r;
	cin >> r;
	cout << "\nRightangled: \n";
	cout << r;

	cout << "\nHypotenuse: ";
	cout << r.calculatingHypotenuse() << endl;

	Vector v(5);

	Pair p1;
	cin >> p1;
	cout << "First pair:\n" << p1;

	Rightangled p2;
	cin >> p2;
	cout << "Second rightangled:\n" << p2;

	Object* pointer = &p1;
	v.add(pointer);
	pointer = &p2;
	v.add(pointer);

	cout << "\nVector: " << v;
}