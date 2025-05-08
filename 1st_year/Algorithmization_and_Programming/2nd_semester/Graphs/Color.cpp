#include "Color.h"

Color::Color()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::Color(const byte& r, const byte& g, const byte& b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}