#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	
	Pair& operator=(const Pair&);
	Pair operator+(double);

	friend ostream& operator<<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
public:
	virtual ~Pair() {};
private:
	int first;
	double second;
};

