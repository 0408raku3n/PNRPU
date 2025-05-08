#include <iostream>
#include "./route.h"

using namespace std;

route::route()
{
	start = "";
	finish = "";
	time = 0;
	cout << "An empty class using a constructor with no parameters: \n" << this << endl;
}

route::route(string s, string f, float t)
{
	start = s;
	finish = f;
	time = t;
	cout << "Class using a constructor with parameters: \n" << this << endl;
}

route::route(const route& r)
{
	start = r.start;
	finish = r.finish;
	time = r.time;
	cout << "Class using a copy constructor: \n" << this << endl;
}

route::~route()
{
	cout << "Destructor of class: \n" << this << endl;
}

string route::getStart()
{
	return start;
}

string route::getFinish()
{
	return finish;
}

float route::getTime()
{
	return time;
}

void route::setStart(string s)
{
	start = s;
}

void route::setFinish(string f)
{
	finish = f;
}

void route::setTime(float t)
{
	time = t;
}

void route::Show()
{
	cout << "Start name: " << start << endl;
	cout << "Finish name: " << finish << endl;
	cout << "Time of route: " << time << endl;
}