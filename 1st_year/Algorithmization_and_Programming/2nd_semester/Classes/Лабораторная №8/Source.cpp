#include <iostream>
#include "./Tree.h"
#include "./Event.h"
#include "./Dialog.h"
using namespace std;

int main()
{
	Person* a = new Person;
	a->Input();
	a->Show();
	cout << endl;

	Abiturient* b = new Abiturient;
	b->Input();
	b->Show();

	Object* obj1 = a;
	Object* obj2 = b;
	Tree tree(a);
	tree.addElem(b);
	tree.showTree(&tree);
	tree.deleteElem();
	tree.showTree(&tree);

	Dialog D;
	D.Execute();
}