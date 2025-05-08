#include "DataCircle.h"

DataCircle::DataCircle()
{
	this->r = 0;
	this->q = 0;
	this->color = Color(0, 0, 0);
	this->borderColor = Color(0, 0, 0);
	this->pos = Position(0, 0);
}

DataCircle::DataCircle(const string& data) : DataCircle()
{
	this->data = data;
}

DataCircle::DataCircle(const int& data) : DataCircle()
{
	this->data = to_string(data);
}

void DataCircle::setRadius(const int& r)
{
	this->r = r;
}

int DataCircle::getRadius()
{
	return this->r;
}

void DataCircle::setPosition(const int& x, const int& y)
{
	this->pos = Position(x, y);
}

Position DataCircle::getPosition()
{
	return this->pos;
}

void DataCircle::setData(const string& data)
{
	this->data = data;
}

void DataCircle::setData(const int& data)
{
	this->data = to_string(data);
}

string DataCircle::getData()
{
	return this->data;
}

void DataCircle::setColor(byte r, byte g, byte b)
{
	this->color = Color(r, g, b);
}

void DataCircle::setBorderColor(byte r, byte g, byte b)
{
	this->borderColor = Color(r, g, b);
}

