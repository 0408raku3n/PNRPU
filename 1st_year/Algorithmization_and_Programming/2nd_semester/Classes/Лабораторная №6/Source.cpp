#include <iostream>
#include "./list.h"
using namespace std;

int main()
{
	List l1(5, 0);
	cout << "First list: " << l1;

	cout << "\n\nEnter data to change elements: ";
	cin >> l1;
	cout << "\n\nFirst list after changing: " << l1;

	l1[4] = 69;
	cout << "\n\nFirst list after changing element: " << l1;

	List l2(5, 0);
	cout << "\n\nSecond list: " << l2;
	
	l2 = l1;
	cout << "\n\nSecond list after copying first list: " << l2;

	List l3(5, 0);
	l3 = l2 + 10;
	cout << "\n\nThird list after copying second list and increasing elements: " << l3;
	
	cout << "\n\nEnd position of third list: " << *(l3.last());

	Iterator i = l3.last();
	--i;
	cout << "\n\nPosition of third list after decreement: " << *i;
	++i;
	cout << "\n\nElements of third list using iterator:\n";
	for (i; i != l3.first(); --i)
	{
		cout << *i << " ";
	}

	List l4(5, 2);
	cout << "\n\nFourth list: " << l4;

	cout << "\n\nSumma of third and fourth lists:" << l3 + l4;

}