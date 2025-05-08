#pragma once
class Position
{
public:
	int x;
	int y;

	Position();
	Position(const int&, const int&);

	Position operator+(const Position&);
	Position operator/(const int&);

	void move(const int&, const int&);
};

