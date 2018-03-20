#ifndef RECTANGLE
#define RECTANGLE
#include "Coordinate.h"

class Rectangle{
public:
	Rectangle();
	Rectangle(Coordinate _bottom_left, Coordinate _top_right);
	float get_area();
	float get_perimeter();
	float get_diagonal();
	void set_bottom_left();
	void set_bottom_left(Coordinate);
	void set_top_right();
	void set_top_right(Coordinate);
	Coordinate get_bottom_left();
	Coordinate get_top_right();
private:
	Coordinate bottom_left;
	Coordinate top_right;	
};

#endif