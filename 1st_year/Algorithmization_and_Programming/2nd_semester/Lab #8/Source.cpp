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

	ofstream outFile("Страны.txt");
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
		cout << " | " << "Название:  "  << states[i].Name << endl;
		cout << " | " << "Название столицы:  "  << states[i].NameCapital << endl;
		cout << " | " << "Количество населения:  "  << states[i].Population  << endl;
		cout << " | " << "Площадь:  " << states[i].Square << endl;
		cout << endl;
	}
}

void addStates()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите число государств: \n";
	cin >> amountStates;
	for (int i = 0; i < amountStates; i++)
	{
		cout << "Введите название государства: \n";
		cin >> states[i].Name;

		cout << "Введите название столицы: \n";
		cin >> states[i].NameCapital;

		cout << "Введите количество населения: \n";
		cin >> states[i].Population;

		cout << "Введите площадь государства: \n";
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

	cout << "Введите минимальное количество населения, элементы с меньшим количеством будут удалены: \n";
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

	cout << "Данные о государствах после удаления элементов: \n";
	printStates();
}

void addNewState()
{
	setlocale(LC_ALL, "Russian");

	int k;

	cout << "Введите номер элемента, после которого нужно добавить элемент: \n";
	cin >> k;

	for (int i = amountStates; i > k; i--)
	{
		states[i].Name = states[i - 1].Name;
		states[i].NameCapital = states[i - 1].NameCapital;
		states[i].Population = states[i - 1].Population;
		states[i].Square = states[i - 1].Square;
	}
	
	amountStates++;

	cout << "Введите данные добавленного элемента: \n";

	cout << "Введите название государства: \n";
	cin >> states[k].Name;

	cout << "Введите название столицы: \n";
	cin >> states[k].NameCapital;

	cout << "Введите количество населения: \n";
	cin >> states[k].Population;

	cout << "Введите площадь государства: \n";
	cin >> states[k].Square;
	cout << endl;

	writeNewInfo();

	cout << "Данные о государствах после добавления элемента: \n";
	printStates();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные государств: \n \n";
	addStates();

	deleteStates();

	addNewState();
}

