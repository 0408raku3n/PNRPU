#pragma once
typedef unsigned char byte;
class Color
{
public:
	byte r;
	byte g;
	byte b;
	Color();
	Color(const byte&, const byte&, const byte&);
};

