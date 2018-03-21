#include "Rectangle.h"
#include "Coordinate.h"
#include <iostream>

#define MPW_LT 0
#define MPW_BOT 0
#define MPW_RT 800
#define MPW_TOP 600

Rectangle::Rectangle(){}

Rectangle::Rectangle(int _id) :id(_id) {}

Rectangle::Rectangle(Coordinate _bottom_left,Coordinate _top_right):bottom_left(_bottom_left),top_right(_top_right){}

void Rectangle::set_bottom_left() {
	do {
		std::cout << "Define Rectangle " << id << ":" << std::endl;
		std::cout << "Enter bottom,left x coordinate:" << std::endl;
		std::cin >> bottom_left.x;
		system("cls");
	} while (bottom_left.x < MPW_LT || bottom_left.x > MPW_RT);
	do {
		std::cout << "Define Rectangle " << id << ":" << std::endl;
		std::cout << "Enter bottom, left y coordinate: " << std::endl;
		std::cin >> bottom_left.y;
		system("cls");
	} while (bottom_left.y < MPW_BOT || bottom_left.y > MPW_TOP);
}

void Rectangle::set_bottom_left(Coordinate point) {
	bottom_left = point;
}

void Rectangle::set_top_right() {
	do {
		system("cls");
		std::cout << "Define Rectangle " << id << ":" << std::endl;
		std::cout << "Enter top,right x coordinate: " << std::endl;
		std::cin >> top_right.x;
	} while (top_right.x <= bottom_left.x || top_right.x < MPW_LT || top_right.x > MPW_RT);

	do{
		system("cls");
		std::cout << "Define Rectangle " << id << ":" << std::endl;
		std::cout << "Enter top,right y coordinate: " << std::endl;
		std::cin >> top_right.y;
	} while (top_right.y <= bottom_left.y || top_right.y > MPW_TOP || top_right.y < MPW_BOT);
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

int Rectangle::get_id() {
	return id;
}