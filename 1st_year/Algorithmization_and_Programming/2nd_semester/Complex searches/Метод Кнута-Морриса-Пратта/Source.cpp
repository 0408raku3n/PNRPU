#include <iostream>
#include <string>

using namespace std;

int search(string str, string substr)
{
	int strSize, substrSize;
	strSize = str.size();
	substrSize = substr.size();

	int* pref = new int[substrSize];

	int i = 0;
	int j = -1;
	pref[0] = -1;



		while ((j >= 0) && (substr[j] != substr[i]))
		{
			j = pref[j];
		}
		i++;
		j++;
		
		if (substr[i] == substr[j])
		{
			pref[i] = pref[j];
		}
		else
		{
			pref[i] = j;
		}
		i = 0;
		j = 0;

		for (i = 0, j = 0; (i <= strSize - 1) && (j <= substrSize - 1); i++, j++)
		{
			while ((j >= 0) && (substr[j]) != str[i])
			{
				j = pref[j];
			}
		}

		delete[] pref;
		if (j == substrSize) { return i - j; }
		else return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string inputStr, keyStr;
	cout << "Введите строку: \n";
	cin >> inputStr;
	cout << "Введите искомую часть строки: \n";
	cin >> keyStr;

	int index = search(inputStr, keyStr);
	
	if (index == -1) { cout << "Не найдено!"; }
	else { cout << "Индекс начала найденной строки: " << index; }
}