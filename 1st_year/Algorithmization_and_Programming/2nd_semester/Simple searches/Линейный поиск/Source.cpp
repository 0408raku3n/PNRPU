#include <iostream>

using namespace std;

int search(int arr[], int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_ALL, "russian");

	int n;
	cout << "������� ���������� ��������� �������: \n";
	cin >> n;
	cout << endl;

	int* numbers = new int[n];

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		numbers[i] = rand();
		cout << numbers[i] << " ";
	}
	cout << endl << endl;

	int key_elem;
	cout << "������� ������� ��� ������: \n";
	cin >> key_elem;
	cout << endl;

	int result = search(numbers, n, key_elem);
	delete[] numbers;

	if (result == -1)
	{
		cout << "������� �� ������!";
	}
	else
	{
		cout << "������� ������! " << "��� ����� �����: " << result + 1;
	}
}