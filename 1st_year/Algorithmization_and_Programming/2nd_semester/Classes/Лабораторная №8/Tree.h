#pragma once
#include "./Abiturient.h"
#include "./Event.h"
class Tree
{
public:
	Tree();
	Tree(Object*);
	~Tree();

	void addElem(Object*);
	void deleteElem();
	void deleteElem(Tree*);
	void deleteTree();
	void deleteTree(Tree*);
	void showTree();
	void showTree(Tree*);

	double midAge();
	double midAge(Tree*);
	void goTree(Tree*, const TEvent&);

	void HandleEvent(const TEvent& e);
protected:
	Tree* root;
	Tree* left;
	Tree* right;
	Object* element;
};

