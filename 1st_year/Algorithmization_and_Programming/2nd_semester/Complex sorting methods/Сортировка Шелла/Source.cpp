#include <iostream>

using namespace std;

void shellSort(int arr[], int N)
{
	int j;
	int d = N / 2;
	
	while (d > 0)
	{
		for (int i = 0; i < N - d; i++)
		{
			j = i;
			while (j >= 0 && arr[j] > arr[j + d])
			{
				swap(arr[j], arr[j + d]);
				j--;
			}
		}

		d /= 2;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int N;
	cout << "¬ведите число случайных чисел: \n";
	cin >> N;

	srand(time(NULL));

	int* numbers = new int[N];

	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl << endl;

	shellSort(numbers, N);

	cout << "ќтсортированный массив: \n";
	for (int i = 0; i < N; i++)
	{
		cout << numbers[i] << ' ';
	}

	delete[] numbers;
}