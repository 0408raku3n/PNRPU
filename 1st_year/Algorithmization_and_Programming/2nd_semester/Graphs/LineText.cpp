#include "LineText.h"

LineText::LineText()
{
	this->color = Color(0, 0, 0);
	this->w = 2;
}

LineText::LineText(const string& data) :LineText()
{
	this->data = data;
}

LineText::LineText(const int& data) : LineText()
{
	this->w = data;
}

void LineText::setStart(const Position& start)
{
	this->start = start;
}

void LineText::setStart(const int& x, const int& y)
{
	this->start = Position(x, y);
}

void LineText::setEnd(const Position& end)
{
	this->end = end;
}

void LineText::setEnd(const int& x, const int& y)
{
	this->end = Position(x, y);
}

void LineText::setData(const string& data)
{
	this->data = data;
}

void LineText::setData(const int& data)
{
	this->data = to_string(data);
}

string LineText::getData() const
{
	return this->data;
}

void LineText::setW(const int& w)
{
	this->w = w;
}

int LineText::getW() const
{
	return this->w;
}

void LineText::setColor(byte r, byte g, byte b)
{
	this->color = Color(r, g, b);
}

void LineText::toBuff()
{
	glColor3ub(color.r, color.g, color.b);
	glLineWidth(w);
	glBegin(GL_LINES);
	glVertex2i(start.x, start.y);
	glVertex2i(end.x, end.y);
	glEnd();

	Position textPos = (start + end) / 2;
	textPos.move(5, 5);
	glColor3ub(0, 0, 0);
	glRasterPos2i(textPos.x - data.size() * 4, textPos.y - 20);
	for (char i : data)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
	}
	
	
}