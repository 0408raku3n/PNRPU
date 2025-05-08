#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(Object* obj)
{

	left = right = NULL;
	this->element = obj;
	root = this;
}

Tree::Tree()
{
	left = right = root = NULL;
	element = NULL;
}
Tree::~Tree()
{
}

void Tree::addElem(Object* obj)
{
	Tree* ptr = new Tree(obj);

start:
	cout << "\nWhich side of tree? Enter 'left' or 'right': ";
	string side;
	cin >> side;

	if (side == "left")
	{
		left = ptr;
	}
	else if (side == "right")
	{
		right = ptr;
	}
	else
	{
		cout << "\nYou entered wrong side! Try again!";
		goto start;
	}
}

void Tree::deleteElem(Tree* t)
{
	if (t == NULL) return;
	deleteElem(t->right);
	deleteElem(t->left);

	cout << "\nDeleted element:";
	t->element->Show();
	delete t;
}

void Tree::deleteElem()
{
	if (this == NULL) return;
	deleteElem(this->right);
	deleteElem(this->left);

	cout << "\nDeleted element:";
	this->element->Show();
	delete this;
}

void Tree::deleteTree(Tree* t)
{
	if (t == NULL) return;
	deleteElem(t->right);
	deleteElem(t->left);
	t->left = t->right = NULL;

	cout << "\nTree is deleted";
}

void Tree::deleteTree()
{
	if (this == NULL) return;
	deleteElem(this->right);
	deleteElem(this->left);
	this->left = this->right = NULL;

	cout << "\nTree is deleted";
}

void Tree::showTree()
{
	if (root = NULL) return;
	root->element->Show();
	cout << endl;
	showTree(this->left);
	showTree(this->right);
}

void Tree::showTree(Tree* t)
{
	if (root = NULL) return;
	root->element->Show();
	cout << endl;
	showTree(t->left);
	showTree(t->right);
}


double Tree::midAge()
{
	int sum = 0;
	int count = 0;
	if (root = NULL) return (sum / count);
	sum += root->element->getAge();
	count += 1;
	midAge(this->left);
	midAge(this->right);
}

double Tree::midAge(Tree* t)
{
	int sum = 0;
	int count = 0;
	if (root = NULL) return (sum / count);
	sum += root->element->getAge();
	count += 1;
	midAge(t->left);
	midAge(t->right);
}

void Tree::goTree(Tree* t, const TEvent& e)
{
	if (root = NULL) t->HandleEvent(e);
	else
	{
		goTree(t->left, e);
		goTree(t->right, e);
	}

}

void Tree::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Tree* p = root;
		goTree(p->left, e);
		goTree(p->right, e);
	}
}

