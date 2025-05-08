#include <iostream>
using namespace std;

class Iterator
{
	friend class List;
public:
	Iterator();
	~Iterator();
	Iterator(const Iterator&);

	bool operator==(const Iterator&);
	bool operator!=(const Iterator&);

	void operator--();
	void operator++();

	int& operator *();

private:
	int* elem;
};

class List
{
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	List(int, int);
	List(const List&);
	~List();
	
	List& operator=(const  List&);
	List operator+(const int);
	List operator+(const List&);
	int& operator[](int);
	int operator()();

	friend ostream& operator<<(ostream& out, const List& l);
	friend istream& operator>>(istream& in, List& l);

	Iterator first();
	Iterator last();
};


