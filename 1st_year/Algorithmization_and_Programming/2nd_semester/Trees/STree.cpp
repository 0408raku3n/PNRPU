#include "STree.h"

STree::STree()
{
	this->left = this->right = this->parent = nullptr;
	this->data = 0;
}

STree::STree(int data)
{
	this->data = data;
	left = right = parent = nullptr;
}


STree::~STree()
{
	if (left) delete left;
	if (right) delete right;
}


STree* STree::findElement(int data)
{
	if ((this || (data == this->data))) return this;
	if (data < this->data) return left->findElement(data);
	else return right->findElement(data);
}


STree* STree::findMin()
{
	if (!left) return this;
	return left->findMin();
}


STree* STree::findMax()
{
	if (!right) return this;
	return right->findMax();
}


int STree::getData()
{
	return this->data;
}


STree* STree::getLeft()
{
	return this->left;
}


STree* STree::getRight()
{
	return this->right;
}

int STree::getHeight()
{
	if (this == nullptr) {
		return 0;
	}

	return 1 + max(this->left->getHeight(), this->right->getHeight());
}


void STree::setLeft(STree* tmp)
{
	this->left = tmp;
}


void STree::setRight(STree* tmp)
{
	this->right = tmp;
}


void STree::insertNode(int data)
{
	STree* tree = this;
	while (tree)
	{
		if (data >= tree->data)
		{
			if (tree->right)
			{
				tree = tree->right;
			}
			else
			{
				STree* tmp = new STree(data);
				tmp->parent = tree;
				tree->right = tmp;
				break;
			}
		}
		else if (data < tree->data)
		{
			if (tree->left)
			{
				tree = tree->left;
			}
			else
			{
				STree* tmp = new STree(data);
				tmp->parent = tree;
				tree->left = tmp;
				break;
			}
		}
	}
}

STree* STree::next()
{
	STree* cur = this;
	if (cur->right == nullptr)
	{
		return cur->right->findMin();
	}
	STree* tmp = cur->parent;
	while (tmp != nullptr && cur == tmp->right)
	{
		cur = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

void STree::deleteNode(int data)
{
	STree* to_erase = this->findElement(data);
	STree* to_erase_parent = to_erase->parent;
	if (to_erase->left == nullptr && to_erase->right == nullptr)
	{
		if (to_erase_parent->left == to_erase)
		{
			to_erase_parent->left = nullptr;
			delete to_erase;
		}
		else
		{
			to_erase_parent->right = nullptr;
			delete to_erase;
		}
	}
	else if ((to_erase->left != nullptr && to_erase->right == nullptr) ||
		(to_erase->right != nullptr && to_erase->left == nullptr))
	{
		if (to_erase->left == nullptr)
		{
			if (to_erase == to_erase_parent->left)
			{
				to_erase_parent->left = to_erase->right;
			}
			else
			{
				to_erase_parent->right = to_erase->right;
			}
			to_erase->right->parent = to_erase_parent;
		}
		else
		{
			if (to_erase_parent->left == to_erase)
			{
				to_erase_parent->left = to_erase->left;
			}
			else
			{
				to_erase_parent->right = to_erase->left;
			}
			to_erase->left->parent = to_erase_parent;
		}
	}
	else
	{
		STree* next = to_erase->next();
		to_erase->data = next->data;
		if (next == next->parent->left)
		{
			next->parent->left = next->right;
			if (next->right != nullptr)
			{
				next->right->parent = next->parent;
			}
		}
		else
		{
			next->parent->right = next->right;
			if (next->right != nullptr)
			{
				next->right->parent = next->parent;
			}
		}
		delete next;
	}
}


STree* STree::balanced(int count)
{
	if (count <= 0)
	{
		return nullptr;
	}
	int data;
	cout << "\nEnter data to balance tree:"; cin >> data;
	STree* tmp = new STree(data);
	tmp->setLeft(balanced(count / 2));
	tmp->setRight(balanced(count - count / 2 - 1));
	return tmp;
}

void STree::inOrder(STree* current)
{
	if (current == nullptr)
	{
		return;
	}
	else
	{
		cout << current->getData() << " ";
		inOrder(current->getLeft());
		inOrder(current->getRight());
	}
}


void STree::printTree(int lvl)
{
	if (this != nullptr)
	{
		this->left->printTree(lvl + 1);
		for (int i = 1; i < lvl; i++) cout << "   ";
		cout << this->getData() << "\n";
		this->right->printTree(lvl + 1);
	}
}

