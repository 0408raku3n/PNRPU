#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int amountStates;

struct State
{
	string Name;
	string NameCapital;
	int Population;
	float Square;
};

State states[1000];

void writeNewInfo()
{
	setlocale(LC_ALL, "Russian");

	ofstream outFile("������.txt");
	for (int i = 0; i < amountStates; i++)
	{
		outFile << states[i].Name << " " << states[i].NameCapital << " " << states[i].Population << " " << states[i].Square << endl;
	}
	outFile.close();
}

void printStates()
{
	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < amountStates; i++)
	{
		cout << " | " << "��������:  "  << states[i].Name << endl;
		cout << " | " << "�������� �������:  "  << states[i].NameCapital << endl;
		cout << " | " << "���������� ���������:  "  << states[i].Population  << endl;
		cout << " | " << "�������:  " << states[i].Square << endl;
		cout << endl;
	}
}

void addStates()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ����� ����������: \n";
	cin >> amountStates;
	for (int i = 0; i < amountStates; i++)
	{
		cout << "������� �������� �����������: \n";
		cin >> states[i].Name;

		cout << "������� �������� �������: \n";
		cin >> states[i].NameCapital;

		cout << "������� ���������� ���������: \n";
		cin >> states[i].Population;

		cout << "������� ������� �����������: \n";
		cin >> states[i].Square;
		cout << endl;
	}
	writeNewInfo();
	printStates();
}
void deleteStates()
{
	setlocale(LC_ALL, "Russian");

	int minpopulation;

	cout << "������� ����������� ���������� ���������, �������� � ������� ����������� ����� �������: \n";
	cin >> minpopulation;

	for (int i = 0; i < amountStates; i++)
	{
		if (states[i].Population < minpopulation)
		{
			for (int j = i; j < amountStates - 1; j++)
			{
				states[j] = states[j + 1];
			}
			
			amountStates--;
			i--;
		}
	}
	writeNewInfo();

	cout << "������ � ������������ ����� �������� ���������: \n";
	printStates();
}

void addNewState()
{
	setlocale(LC_ALL, "Russian");

	int k;

	cout << "������� ����� ��������, ����� �������� ����� �������� �������: \n";
	cin >> k;

	for (int i = amountStates; i > k; i--)
	{
		states[i].Name = states[i - 1].Name;
		states[i].NameCapital = states[i - 1].NameCapital;
		states[i].Population = states[i - 1].Population;
		states[i].Square = states[i - 1].Square;
	}
	
	amountStates++;

	cout << "������� ������ ������������ ��������: \n";

	cout << "������� �������� �����������: \n";
	cin >> states[k].Name;

	cout << "������� �������� �������: \n";
	cin >> states[k].NameCapital;

	cout << "������� ���������� ���������: \n";
	cin >> states[k].Population;

	cout << "������� ������� �����������: \n";
	cin >> states[k].Square;
	cout << endl;

	writeNewInfo();

	cout << "������ � ������������ ����� ���������� ��������: \n";
	printStates();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ������ ����������: \n \n";
	addStates();

	deleteStates();

	addNewState();
}

