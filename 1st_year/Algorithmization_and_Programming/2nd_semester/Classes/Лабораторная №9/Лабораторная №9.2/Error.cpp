#include "Error.h"

Error::Error(string s)
{
	str = s;
}

void Error::what()
{
	cout << str << endl;
}