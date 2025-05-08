#include <iostream>

using namespace std;

int main() 
{
	int arr[] = { 41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22 };
	int tmp;

	int size = 11;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			tmp = arr[j + 1];
			if (arr[j] > arr[j + 1])
			{
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
}
