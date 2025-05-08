#include <iostream>

using namespace std;

struct ListElem
{
	int data;
	ListElem* next;
};

ListElem* createList(int n)
{
	ListElem* start;
	ListElem* p, *c;

	start = new ListElem;
	cin >> start->data;

	start->next = nullptr;
	p = start;
	for (int i = 0; i < n - 1; i++)
	{
		c = new ListElem;
		cin >> c->data;
		c->next = nullptr;
		p->next = c;
		p = c;
	}
	return start;
}

void addElem(ListElem*& start, int place, int k, int& size)
{
	size++;
	ListElem* first = start;

	for (int i = 1; i < place - 1; i++)
	{
		first = first->next;
	}

	ListElem* new_elem = new ListElem;

	cout << "¬ведите значение дл€ добавлени€: \n";
	cin >> new_elem->data;

	if (place == 1)
	{
		new_elem->next = first;
		start = new_elem;
	}
	else
	{
		new_elem->next = first->next;
		first->next = new_elem;
	}
}

void addElems(ListElem*& Elements, int place, int k, int& size)
{
	for (int i = 0; i < k; i++)
	{
		addElem(Elements, place + i, k, size);
	}
}

void deleteElem(ListElem*& start, int place, int k, int& size)
{
	size--;

	ListElem* first = start;
	ListElem* last;

	for (int i = 1; i < place - 1; i++)
	{
		first = first->next;
	}


	if (place == 1)
	{
		start = first->next;
		first->next = start;
	}
	else
	{
		last = first->next->next;
		first->next = last;
	}
}

void deleteElems(ListElem*& start, int place, int k, int& size)
{
	size -= k;

	ListElem* first = start;
	ListElem* last;

	for (int i = 1; i < place - 1; i++)
	{
		first = first->next;
	}

	last = first;

	for (int i = 0; i < k; i++)
	{
		last = last->next;
	}

	if (place == 1)
	{
		start = last;
	}
	else
	{
		first->next = last->next;
	}
}

void searchElem(ListElem* start, int key)
{
	ListElem* point = start;
	int position = 0;

	while (point->data != key && point->next != nullptr)
	{
		point = point->next;
		position++;
	}

	if (point->data == key)
	{
		cout << "Ёлемент найден! \n";
	}
	else
	{
		cout << "Ёлемент не найден! \n";
	}
}

void printElem(ListElem* start, int size)
{
	ListElem* point = start;
	for (int i = 0; i < size; i++)
	{
		cout << point->data << ' ';
		point = point->next;
	}
	cout << endl;
}

void deleteList(ListElem* Elems)
{
	delete Elems;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int N, position, iter, key_elem;

	cout << "¬ведите количество чисел: \n";
	cin >> N;
	cout << "¬ведите элементы: \n";
	ListElem* Elements = createList(N);
	printElem(Elements, N);

	cout << "¬ведите позицию, куда добавить элемент: \n";
	cin >> position;
	addElem(Elements, position, 1, N);
	cout << "—писок элементов: \n";
	printElem(Elements, N);

	cout << "¬ведите количество добавл€емых элементов: \n";
	cin >> iter;
	cout << "¬ведите позицию, с которой добавить элементы: \n";
	cin >> position;
	addElems(Elements, position, iter, N);
	cout << "—писок элементов: \n";
	printElem(Elements, N);

	cout << "¬ведите позицию, с которой удалить элемент: \n";
	cin >> position;
	deleteElem(Elements, position, 1, N);
	cout << "—писок элементов: \n";
	printElem(Elements, N);

	cout << "¬ведите количество удал€емых элементов: \n";
	cin >> iter;
	cout << "¬ведите позицию, с которой удалить элементы: \n";
	cin >> position;
	deleteElems(Elements, position, iter, N);
	cout << "—писок элементов: \n";
	printElem(Elements, N);

	cout << "¬ведите элемент дл€ поиска: \n";
	cin >> key_elem;
	searchElem(Elements, key_elem);
	deleteList(Elements);
}
