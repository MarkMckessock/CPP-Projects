#include "Rectangle.h"
#include "Coordinate.h"
#include <iostream>

Rectangle::Rectangle() {}

Rectangle::Rectangle(Coordinate _bottom_left,Coordinate _top_right):bottom_left(_bottom_left),top_right(_top_right){}

void Rectangle::set_bottom_left() {
	std::cout << "Enter bottom,left x coordinate:" << std::endl;
	std::cin >> bottom_left.x;
	std::cout << "Enter bottom, left y coordinate: " << std::endl;
	std::cin >> bottom_left.y;
	system("cls");
}

void Rectangle::set_bottom_left(Coordinate point) {
	bottom_left = point;
}

void Rectangle::set_top_right() {
	do {
		system("cls");
		std::cout << "Enter top,right x coordinate: " << std::endl;
		std::cin >> top_right.x;
	} while (top_right.x <= bottom_left.x);

	do{
		system("cls");
		std::cout << "Enter top,right y coordinate: " << std::endl;
		std::cin >> top_right.y;
	} while (top_right.y <= bottom_left.y);
	system("cls");
}

void Rectangle::set_top_right(Coordinate point) {
	top_right = point;
}

Coordinate Rectangle::get_bottom_left() {
	return bottom_left;
}

Coordinate Rectangle::get_top_right() {
	return top_right;
}

float Rectangle::get_area() {
	return (top_right.x - bottom_left.x)*(top_right.y - bottom_left.y);
}

float Rectangle::get_diagonal() {
	return sqrt(pow(top_right.x-bottom_left.x,2)+pow(top_right.y-bottom_left.y,2));
}

float Rectangle::get_perimeter() {
	return (top_right.x - bottom_left.x) * 2 + (top_right.y - bottom_left.y) * 2;
}