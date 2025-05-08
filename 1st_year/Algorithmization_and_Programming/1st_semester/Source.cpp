#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
#include <map>

using namespace std;

void quicksort(int* arr, int l, int r)
{
	int i = l;
	int j = r;
	int pivot = (i + j) / 2;

	while (i <= j)
	{
		while (arr[i] < arr[pivot])
		{
			i++;
		}

		while (arr[j] > arr[pivot])
		{
			j--;
		}

		if (i <= j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	}
	if (j > l)
	{
		quicksort(arr, l, j);
	}

	if (i < r)
	{
		quicksort(arr, j, r);
	}
}



void hanoiTower(int quantity, int from, int to, int other)
{
	if (quantity == 0)
	{
		return;
	}

	hanoiTower(quantity - 1, from, other, to);

	cout << "Move" << quantity << " " << from << "->" << to;

	hanoiTower(quantity - 1, other, to, from);
}

void shellSort(int* arr, int N)
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

template <class T>
int maxLength(T str, int n)
{
	int max = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		count++;

		if (str[i] == ' ' || str[i] == '.')
		{
			if (count > max)
			{
				count--;
				max = count;
			}

			count = 0;
		}
	}

	return max;
}

template <class T>
T findMax(T* arr, int n)
{
	T max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

void reverse(int* arr, int n)
{
	if (n % 2 == 0)
	{
		for (int i = 0, j = n - 1; i < n / 2 && j > n / 2 - 1; i++, j--)
		{
			swap(arr[i], arr[j]);
		}
	}
	else
	{
		for (int i = 0, j = n - 1; i < n / 2 && j > n / 2; i++, j--)
		{
			swap(arr[i], arr[j]);
		}
	}
}

void reverseRange(int* arr, int n, int from, int to)
{
	int range = (to - from + 1);
	if (range % 2 == 0)
	{
		for (int i = from, j = to; i < from + range / 2 && j > to - range / 2 - 1; i++, j--)
		{
			swap(arr[i], arr[j]);
		}
	}
	else
	{
		for (int i = from, j = to; i < from + range / 2 && to - range > range / 2; i++, j--)
		{
			swap(arr[i], arr[j]);
		}
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


// ƒружественные функции - это функции, которые не €вл€ютс€ членами класса,
// однако имеют доступ к его закрытым членам - переменным и функци€м, которые имеют спецификатор private.
class Auto
{
	friend void drive(const Auto&);
	friend void setPrice(Auto&, unsigned);
public:
	Auto(string autoName, unsigned autoPrice)
	{
		name = autoName;
		price = autoPrice;
	}
	void print()
	{
		std::cout << name << " : " << price << endl;
	}

private:
	string name;   // название автомобил€
	unsigned price;  // цена автомобил€
};

void drive(const Auto& car)
{
	cout << car.name << " is driven" << endl;
}
void setPrice(Auto& car, unsigned price)
{
	car.price = price;
}

void countSort(int* arr, int size)
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


	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}

	delete[] count;
	delete[] output;
}

char* replace(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '1')
		{
			string[i] = '0';
		}
		i++;
	}

	return string;
}

void printNoA(char* string)
{
	int i = 0;
	int start = 0;
	int end = 0;
	bool isA = false;

	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			end = i;

			for (int j = start; j < end; j++)
			{
				if (string[j] == 'a' || string[j] == 'A')
				{
					isA = true;
				}
			}

			if (!isA)
			{
				for (int j = start; j < end; j++)
				{
					cout << string[j];
				}
				cout << endl;
			}

			start = i + 1;
		}

		i++;
	}
}

int** deleteZeroLines(int** matrix, int m, int n)
{
	bool* lines = new bool[m];
	int k = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				k++;
			}
		}

		if (k == n)
		{
			lines[i] = false;
		}

		k = 0;
	}

	int** newMatrix = new int*[m];
	for (int i = 0; i < m; i++)
	{
		newMatrix[i] = new int[n];
	}
	int newm = 0;

	for (int i = 0; i < m; i++)
	{
		if (lines[i])
		{
			for (int j = 0; j < n; j++)
			{
				newMatrix[newm][j] = matrix[i][j];
			}
			newm++;
		}
	}

	return newMatrix;
}

int main()
{
	/*char text[255] = {};

	cout << "Enter text:";
	cin.getline(text, 255);

	cout << "\nLength of the longest word:" << maxLength(text, 255) << endl;

	string str;
	cout << "\nEnter string:";
	getline(cin, str);

	stringstream ss(str);
	map<string, int> voc;

	while (ss >> str)
	{
		voc[str]++;
	}

	for (auto i : voc)
	{
		if (i.second == 1)
		{
			cout << i.first << endl;
		}
	}

	int n;
	cout << "\Enter number of elements:"; cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	print(array, n);

	countSort(array, n);

	print(array, n);*/

	/*char string[10];
	cin.getline(string, 10);

	char* newstring = replace(string);

	cout << newstring << endl;

	char str[100];
	cin.getline(str, 100);

	printNoA(str);*/

	int m, n;
	cout << "\nEnter sizes of matrix:"; cin >> m; cin >> n;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}

	cout << "\nEnter data to matrix:\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	matrix = deleteZeroLines(matrix, m, n);
	cout << sizeof(matrix);
}