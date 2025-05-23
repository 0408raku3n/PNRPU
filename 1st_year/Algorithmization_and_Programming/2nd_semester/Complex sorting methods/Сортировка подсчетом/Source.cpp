#include <iostream>

using namespace std;

void countSort(int arr[], int size);

int main()
{
	setlocale(LC_ALL, "Russian");

	int numbers[100] = {};
	int N;

	cout << "Ââåäèòå êîëè÷åñòâî ñèìâîëîâ: " << endl;
	cin >> N;

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl;

	countSort(numbers, N);
}

void countSort(int arr[], int size)
{
	int* output = new int[size];
	int* count;
	int max = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	count = new int[max + 1];

	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}


	for (int i = 1; i < size + 1; i++)
	{
		arr[i] = output[i];
		cout << arr[i] << " ";
	}

	delete[] count;
	delete[] output;
}
