#include <iostream>
#include <string>

using namespace std;

class route
{
	string start;
	string finish;
	float time;

public:
	route();
	route(string, string, float);
	route(const route&);
	~route();

	string getStart();
	string getFinish();
	float getTime();

	void setStart(string);
	void setFinish(string);
	void setTime(float);

	void Show();
};