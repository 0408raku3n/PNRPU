#pragma once
#include <string>
#include <iostream>
using namespace std;
class Error
{
	string str;
public:
	Error(string);
	void what();
};

