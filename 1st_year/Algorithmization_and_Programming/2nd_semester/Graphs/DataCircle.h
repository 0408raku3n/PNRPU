#include "./Shape.h"
#include "./Color.h"
#include "./Position.h"
#include <Windows.h>
#include <gl/GL.h>
#include <glut.h>
#include <string>
#include <iostream>
using namespace std;
class DataCircle : public Shape
{
protected:
	int r;
	int q;
	string data;
	Color color;
	Color borderColor;
	Position pos;
public:
	DataCircle();
	DataCircle(const string&);
	DataCircle(const int&);

	void setRadius(const int&);
	int getRadius();

	void setPosition(const int&, const int&);
	Position getPosition();

	void setData(const string&);
	void setData(const int&);

	string getData();

	void setColor(byte, byte, byte);
	void setBorderColor(byte, byte, byte);

	virtual void toBuff() override
	{
		glColor3ub(color.r, color.g, color.b);
		glBegin(GL_POLYGON);
		for (int i = 0; i < q; i++)
		{
			double angle = i * 3.14159265358979323846 / 180;
			glVertex2f(this->pos.x + r * cos(angle), this->pos.y + r * sin(angle));
		}
		glEnd();

		glColor3ub(borderColor.r, borderColor.g, borderColor.b);
		glBegin(GL_LINE_LOOP);

		for (int i = 0; i < q; i++)
		{
			double angle = i * 3.14159265358979323846 / 180;
			glVertex2f(this->pos.x + r * cos(angle), this->pos.y + r * sin(angle));
		}
		glEnd();

		glColor3ub(0, 0, 0);
		glRasterPos2i(this->pos.x - data.size() * 4, this->pos.y - 5);
		for (char i : data)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
		}
	}
};

