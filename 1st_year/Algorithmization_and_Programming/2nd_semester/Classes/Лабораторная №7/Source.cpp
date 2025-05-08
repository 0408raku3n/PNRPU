#include "./List.h"
#include "./Pair.h"
#include <iostream>
using namespace std;

int main()
{
	List<int> L1(5, 0);
	cout << "Enter data for first list: ";
	cin >> L1;
	cout << "\n\nFirst list: " << L1;

	List<int> L2(10, 1);
	cout << "\n\nSecond list: " << L2;

	L2 = L1;
	cout << "\n\nSecond list after copying first list: " << L2;

	cout << "\n\nThird element of first list: " << L1[2];

	cout << "\n\nSize of first list: " << L1();

	L2 = L1 + 10;
	cout << "\n\nSecond list after plussing 10: " << L2;

	List<int> L3(10, 3);
	cout << "\n\nThird list: " << L3;
	cout << "\n\nFourth list after summing second and third lists: " << L2 + L3;

	Pair P1;
	cout << "\n\nEnter first pair: ";
	cin >> P1;
	cout << "\n\nFirst pair: " << P1;

	int k;
	cout << "\n\nEnter number to add to first pair: ";
	cin >> k;
	Pair P2;
	P2 = P1 + k;
	cout << "\n\nFirst pair after add 'k': " << P2;

	Pair P3;
	cout << "\n\nEnter third pair: ";
	cin >> P3;
	cout << "\n\nThird pair: " << P3;

	List<Pair> A(5, P3);
	cout << "\n\nEnter data to first parametric list: ";
	cin >> A;
	cout << "\n\nFirst parametric list: " << A;

	List<Pair> B(10, P3);
	cout << "\n\nSecond parametric list: " << B;

	B = A;
	cout << "\n\nSecond parametric list after copying first one: " << B;

	cout << "\n\nThird element of firtst parametric list: " << A[2];

	cout << "\n\nSize of first parametric list: " << A();

}

