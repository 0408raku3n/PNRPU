#include "./Shape.h"
#include "./Position.h"
#include "./Color.h"
#include <Windows.h>
#include <glut.h>
#include <gl/GL.h>
#include <string>

using namespace std;
class LineText : public Shape
{
protected:
	Position start;
	Position end;
	int w;
	Color color;
	string data;
public:
	LineText();
	LineText(const string&);
	LineText(const int&);

	void setStart(const Position&);
	void setStart(const int&, const int&);

	void setEnd(const Position&);
	void setEnd(const int&, const int&);

	void setData(const string&);
	void setData(const int&);

	string getData() const;
	
	void setW(const int&);
	int getW() const;

	void setColor(byte r, byte g, byte b);

	virtual void toBuff() override;
};

