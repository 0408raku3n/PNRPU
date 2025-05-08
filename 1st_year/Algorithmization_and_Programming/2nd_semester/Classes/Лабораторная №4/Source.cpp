#include <iostream>
#include "./pair.h"
#include "./Rightangled.h"
using namespace std;

int main()
{
	Pair  a;
	cin >> a;
	cout << "\nFirst pair of numbers: \n";
	cout << a;

	Pair b(4, 5);
	cout << "\nSecond pair of numbers: \n";
	cout << b;
	
	a = b;
	cout << "\nFirst pair of numbers after copy: \n" << a;

	int tmp;
	cout << "\nEnter number to change first number: ";
	cin >> tmp;
	a.setFirst(tmp);

	cout << "Enter number to change second number: ";
	cin >> tmp;
	a.setSecond(tmp);

	cout << "Production of first and second numbers: " << a.production() << endl;

	Rightangled r;
	cin >> r;
	cout << "\nFirst rightangled: \n";
	cout << r;

	cout << "\nHypotenuse: ";
	cout << r.calculatingHypotenuse();
}