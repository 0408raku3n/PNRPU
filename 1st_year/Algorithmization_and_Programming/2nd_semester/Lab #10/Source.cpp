#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int N, k, number;

	cout << "Введите размер массива: \n";
	cin >> N;

	int *numbers = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "Введите номер элемента, с которого удалите элементы: \n";
	cin >> number;

	cout << "Введите количество элементов для удаления: \n";
	cin >> k;

	int* new_numbers = new int[N - k + 1];
	int count = 0;
	int i = 0;

	while (count != N)
	{
		if (count < number - 1 || count > number + k - 2)
		{
			new_numbers[i] = numbers[count];
			i++;
		}
		count++;
	}

	delete[] numbers;

	cout << "Введите число для добавления: \n";
	cin >> new_numbers[N - k];

	for (i = 0; i < N - k + 1; i++)
	{
		cout << new_numbers[i] << ' ';
	}
	cout << endl;

	delete[] new_numbers;
}
