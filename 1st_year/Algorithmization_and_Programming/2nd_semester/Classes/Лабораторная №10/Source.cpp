#include "Pair.h"
#include <iostream>
#include <fstream>
#include "file_work.h"
#include <string>
using namespace std;

int main()
{
	Pair p, p1, p2, p3, p4, p5;
	int k, c, v, n;
	char file_name[30];
	do
	{
		cout << "\nWhat you want to do?" << "\n1. Make file" << "\n2. Print file" 
			<< "\n3. Delete info from file" << "\n4. Add file" << "\n5. Change file"
			<< "\n6. Delete pairs from file" << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "\nEnter file name:"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "\nIt's impossible to make file!";
			break;
		case 2:
			cout << "\nEnter file name:"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "\nFile's empty";
			if (k < 0) cout << "\nIt's impossible to read file!";
			break;
		case 3:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter number: "; cin >> n;
			k = del_file(file_name, n);
			if (k < 0) cout << "\nIt's impossible to read file!";
			break;
		case 4:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter number: "; cin >> n;
			cout << "\nEnter pair:"; cin >> p1;
			k = add_file(file_name, n, p1);
			if (k == 0) k = add_end(file_name, p1);
			if (k < 0) cout << "\nIt's impossible to read file!";
			break;
		case 5:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter number: "; cin >> n;
			cout << "\nEnter pair:"; cin >> p2;
			k = change_file(file_name, n, p2);
			if (k < 0) cout << "\nIt's impossible to read file!";
			if (k == 0) cout << "\nThere's not such record!";
			break;
		case 6:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter pair:"; cin >> p3;
			k = del_pair(file_name, p3);
			if (k < 0) cout << "\nIt's impossible to read file!";
			if (k == 0) cout << "\nThere's not such record! Nothing has changed";
			break;
		case 7:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter pair:"; cin >> p4;
			cout << "\nEnter value:"; cin >> v;
			k = decrease_pair(file_name, v, p4);
			if (k < 0) cout << "\nIt's impossible to read file!";
			if (k == 0) cout << "\nThere's not such record! Nothing has changed";
			break;
		case 8:
			cout << "\nEnter file name:"; cin >> file_name;
			cout << "\nEnter pair:"; cin >> p5;
			cout << "\nEnter number of pairs to add:"; cin >> n;
			k = add_pairs(file_name, n, p5);
			if (k < 0) cout << "\nIt's impossible to read file!";
			if (k == 0) cout << "\nThere's not such record! Nothing has changed";
			break;
		}
	} while (c != 0);
}