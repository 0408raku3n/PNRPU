#include <iostream>

using namespace std;

int interpolSearch(int* arr, int n, int key)
{
	int left = 0;
	int right = n;
	int mid = 0;
	bool flag = false;

	while ((left <= right) && flag != true)
	{
		mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
		if (arr[mid] < key) { left = mid + 1; }
		else if (arr[mid] > key) { right = mid - 1; }
		else { flag = true; }
	}

	if (arr[left] == key) { return left; }
	else if (arr[right] == key) { return right; }
	return -1;
}

void quickSort(int* arr, int l, int r)
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

int main()
{
	setlocale(LC_ALL, "Russian");

	int N, key;
	cout << "¬ведите длину массива: \n";
	cin >> N;
	int* numbers = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl;

	quickSort(numbers, 0, N);

	int* new_numbers = new int[N];
	for (int i = 0; i < N; i++)
	{
		new_numbers[i] = numbers[i + 1];
	}

	cout << "ќтсортированный массив: \n";
	for (int i = 0; i < N; i++)
	{
		cout << new_numbers[i] << " ";
	}
	cout << endl;

	cout << "¬ведите элемент дл€ поиска: \n";
	cin >> key;

	int result = interpolSearch(new_numbers, N, key);

	if (result == -1) { cout << "Ёлемент не найден!"; }
	else { cout << "»ндекс найденного элемента: " << result; }

	delete[] numbers;
	delete[] new_numbers;
}