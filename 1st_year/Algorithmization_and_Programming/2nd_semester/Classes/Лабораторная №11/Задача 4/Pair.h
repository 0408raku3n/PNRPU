#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();
	~Pair();
	Pair(int, double);
	Pair(const Pair&);

	Pair& operator=(const Pair&);
	Pair operator+(double);

	Pair operator+(const Pair&);
	Pair operator/(const Pair&);
	Pair operator/(int);

	bool operator>(const Pair&);
	bool operator<(const Pair&);
	bool operator==(const Pair&);
	bool operator!=(const Pair&);

	friend ostream& operator<<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);

private:
	int first;
	double second;
};

