#include <iostream>

using namespace std;

int main() 
{
	int arr[] = {41, 42, 66, 87, 86, 38, 77, 84, 45, 35, 22};
	int tmp;
	int min_ind;

	int size = 11;

	for (int i = 0; i < size - 1; i++)
	{
		tmp = arr[i];
		min_ind = i + 1;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_ind])
			{
				min_ind = j;
			}
		}
		if (arr[i] > arr[min_ind])
		{
			arr[i] = arr[min_ind];
			arr[min_ind] = tmp;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
}
