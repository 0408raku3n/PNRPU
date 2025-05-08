#include <iostream>

using namespace std;

void quickSort(int* arr, int l, int r);

int main()
{
	setlocale(LC_ALL, "Russian");

	int N;
	cout << "¬ведите число случайных чисел: \n";
	cin >> N;

	srand(time(NULL));

	int* numbers = new int[N + 1];

	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl << endl;

	quickSort(numbers, 0, N);

	cout << "ќтсортированный массив: \n";
	for (int i = 1; i <= N; i++)
	{
		cout << numbers[i] << " ";
	}

	delete[] numbers;
}

void quickSort(int *arr, int l, int r)
{
	int i = l;
	int j = r;
	int pivot = arr[(i + j) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		} 

		while (arr[j] > pivot)
		{
			j--;
		} 

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	
	if (j > l)
	{
		quickSort(arr, l, j);

	}

	if (i < r)
	{
		quickSort(arr, i, r);
	}

}
