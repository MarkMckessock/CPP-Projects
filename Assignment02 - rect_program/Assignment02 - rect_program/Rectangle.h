#ifndef RECTANGLE
#define RECTANGLE
#include "Coordinate.h"

class Rectangle{
public:
	//Constructors
	Rectangle();
	Rectangle(int id);
	Rectangle(Coordinate _bottom_left, Coordinate _top_right);

	//Rect functions
	float get_area();
	float get_perimeter();
	float get_diagonal();

	//Overloaded operators for point assignment
	void set_bottom_left();
	void set_bottom_left(Coordinate);
	void set_top_right();
	void set_top_right(Coordinate);

	//Access functions
	Coordinate get_bottom_left();
	Coordinate get_top_right();
	int get_id();
private:
	Coordinate bottom_left;
	Coordinate top_right;
	int id;
};

#endif