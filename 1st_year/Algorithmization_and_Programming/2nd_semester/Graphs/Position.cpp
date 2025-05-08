#include "Position.h"

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

Position::Position(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}

Position Position::operator+(const Position& r)
{
	Position& l = *this;
	return Position(l.x + r.x, l.y + r.y);
}

Position Position::operator/(const int& r)
{
	Position& l = *this;
	return Position(l.x / r, l.y / r);
}

void Position::move(const int& x, const int& y)
{
	this->x += x;
	this->y += y;
}