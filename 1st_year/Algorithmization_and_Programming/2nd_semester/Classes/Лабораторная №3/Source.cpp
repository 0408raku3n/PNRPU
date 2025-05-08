#include <iostream>
#include "./Time.h"
using namespace std;

int main()
{
	Time t1;
	Time t2;

	cout << "Enter first time: ";
	cin >> t1;
	cout << endl;
	cout << "Enter second time:";
	cin >> t2;
	cout << endl;

	++t1;
	--t2;

	cout << "First time after plussing: ";
	cout << t1 << endl;
	cout << "Second time after minussing: ";
	cout << t2 << endl;

	t1--;
	t2++;

	cout << "First time after minussing: ";
	cout << t1 << endl;
	cout << "Second time after plussing: ";
	cout << t2 << endl;
}