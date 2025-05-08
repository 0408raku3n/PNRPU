#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int arr[100] = {};
	int N; int tmp;
	int k = 0;

	cout << "Ââåäèòå äëèíó ìàññèâà (ìåíüøå 100)" << endl;
	cin >> N;

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand();
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0)
		{
			N--;
			for (int j = i; j < N - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (k != 1)
		{
			if (arr[i] % 2 == 0)
			{
				N++;
				for (int j = i + 2; j < N; j += 2)
				{
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j + 1] = tmp;
				}
				arr[i + 1] = arr[i - 1] + 2;
				k++;
			}
		}
		
	}

	cout << "Èçìåíåííûé ìàññèâ: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}
