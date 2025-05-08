#include <iostream>
#include <string>
#include "./route.h"

using namespace std;

route makeRoute()
{
	string s;
	string f;
	float t;

	cout << "Enter start name: \n";
	cin >> s;
	cout << "Enter finish name: \n";
	cin >> f;
	cout << "Enter time of route: \n";
	cin >> t;

	route r(s, f, t);
	return r;
}

int main()
{
	route R1;
	R1.Show();

	route R2("Chusovoy", "Perm", 2.2);
	R2.Show();

	route R3 = R2;
	R3.Show();

	R3.getStart();
	R3.getFinish();
	R3.getTime();
	R3.Show();

	route R4;
	R4.setStart("Perm");
	R4.setFinish("Moscow");
	R4.setTime(10.3);

	route R5 = makeRoute();
	R5.Show();
}
