#include <iostream>

using namespace std;

void bucketSort(int arr[], int N)
{
	const int NUM = 10;
	const int ARRAY = 10;

	int buckets[NUM][ARRAY];

	int bucketSizes[NUM] = { 0 };

	for (int i = 0; i < N; i++)
	{
		int bucketIndex = arr[i] / NUM;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
		bucketSizes[bucketIndex]++;
	}

	for (int i = 0; i < NUM; i++)
	{
		for (int j = 1; j < bucketSizes[i]; j++)
		{
			int temp = buckets[i][j];
			int k = j - 1;

			while (k >= 0 && buckets[i][k] > temp)
			{
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}

			buckets[i][k + 1] = temp;
		}
	}

	int ind = 0;

	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			arr[ind++] = buckets[i][j];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "¬ведите число случайных чисел: \n";
	cin >> n;

	srand(time(NULL));

	int* numbers = new int[n];

	for (int i = 0; i < n; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl << endl;

	bucketSort(numbers, n);

	cout << "ќтсортированный массив: \n";
	for (int i = 1; i < n; i++)
	{
		cout << numbers[i] << ' ';
	}

	delete[] numbers;
}