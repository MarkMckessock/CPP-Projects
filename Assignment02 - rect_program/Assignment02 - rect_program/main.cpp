#include <string>
#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Rectangle.h"
using namespace std;

void display_rectangles(vector<Rectangle> rects) {
	for (int i = 0; i < rects.size(); i++)
		cout << "Rectangle " << i + 1 << ": (" << rects[i].get_bottom_left().x << ","
		<< rects[i].get_bottom_left().y << ")\t(" << rects[i].get_top_right().x
		<< ", " << rects[i].get_top_right().y << ")" << endl;
}

void display_area(vector<Rectangle> rects) {
	cout << "Area of Rectangles:" << endl << string(20, '=') << endl;
	display_rectangles(rects);
	for (int i = 0; i < rects.size(); i++) {
		cout << "Area of rectangle " << i + 1 << " = " << rects[i].get_area() << " units^2" << endl;
	}
}

void display_perimeter(vector<Rectangle> rects) {
	cout << "Perimeter of Rectangles" << endl << string(24, '=') << endl;
	display_rectangles(rects);
	for (int i = 0; i < rects.size(); i++) {
		cout << "Perimeter of rectangle " << i + 1 << " = " << rects[i].get_perimeter() << " units" << endl;
	}
}

void display_diagonal(vector<Rectangle> rects) {
	cout << "Diagonal length of rectangle" << endl << string(29, '=') << endl;
	display_rectangles(rects);
	for (int i = 0; i < rects.size(); i++) {
		cout << "Diagonal length of rectangle " << i + 1 << " = " << rects[i].get_diagonal() << " units" << endl;
	}
}

Rectangle get_union(Rectangle rect_1, Rectangle rect_2) {
	Rectangle result;
	result.set_bottom_left(Coordinate((rect_1.get_bottom_left().x < rect_2.get_bottom_left().x ? rect_1.get_bottom_left().x : rect_2.get_bottom_left().x),
		(rect_1.get_bottom_left().y < rect_2.get_bottom_left().y ? rect_1.get_bottom_left().y : rect_2.get_bottom_left().y)));
	result.set_top_right(Coordinate((rect_1.get_top_right().x > rect_2.get_top_right().x ? rect_1.get_top_right().x : rect_2.get_top_right().x), 
		(rect_1.get_top_right().y > rect_2.get_top_right().y ? rect_1.get_top_right().y : rect_2.get_top_right().y)));
	return result;
}

void display_union(vector<Rectangle> rects) {
	cout << "Union of two rectangles:" << endl << string(24, '=') << endl;
	display_rectangles(rects);
	Rectangle union_rect;
	union_rect = get_union(rects[0], rects[1]);
	cout << "The union rectangle of rectange 1 & 2 is: (" << union_rect.get_bottom_left().x << ", " << union_rect.get_bottom_left().y
		<< ")\t(" << union_rect.get_top_right().x << ", " << union_rect.get_top_right().y << ")" << endl;
}

bool get_intersection(Rectangle rect_1, Rectangle rect_2,Rectangle &intersect_rect) {
	Rectangle result(Coordinate(((rect_1.get_bottom_left().x > rect_2.get_bottom_left().x && rect_1.get_bottom_left().x < rect_2.get_top_right().x) ? rect_1.get_bottom_left().x : rect_2.get_bottom_left().x), 
		((rect_1.get_bottom_left().y > rect_2.get_bottom_left().y && rect_1.get_bottom_left().y < rect_2.get_top_right().y) ? rect_1.get_bottom_left().y : rect_2.get_bottom_left().y)),
		Coordinate(((rect_1.get_top_right().x > rect_2.get_bottom_left().x && rect_1.get_top_right().x < rect_2.get_top_right().x) ? rect_1.get_top_right().x : rect_2.get_top_right().x),
		((rect_1.get_top_right().y > rect_2.get_bottom_left().y && rect_1.get_top_right().y < rect_2.get_top_right().y) ? rect_1.get_top_right().y : rect_2.get_top_right().y)));
	intersect_rect = result;
	//determine if intersection occurs
	if ((rect_2.get_bottom_left().y >= rect_1.get_bottom_left().y && rect_2.get_bottom_left().y < rect_1.get_top_right().y ||
		rect_1.get_bottom_left().y > rect_2.get_bottom_left().y && rect_1.get_bottom_left().y < rect_2.get_top_right().y) &&
		(rect_1.get_bottom_left().x >= rect_2.get_bottom_left().x && rect_1.get_bottom_left().x < rect_2.get_top_right().x ||
			rect_2.get_bottom_left().x > rect_1.get_bottom_left().x && rect_2.get_bottom_left().x < rect_1.get_top_right().x))
		return true;
	else
		return false;
}

void display_intersect(vector<Rectangle> rects) {
	cout << "Intersection of two rectangles:" << endl << string(32, '=') << endl;
	display_rectangles(rects);
	Rectangle intersect_rect;
	if (get_intersection(rects[0], rects[1], intersect_rect))
		cout << "The intersection rectange 1 & 2 is: (" << intersect_rect.get_bottom_left().x << ", " << intersect_rect.get_bottom_left().y
		<< ")\t(" << intersect_rect.get_top_right().x << ", " << intersect_rect.get_top_right().y << ")" << endl;
	else
		cout << "There is no intersection between rectangles 1 & 2." << endl;
}

int main() {
	vector<Rectangle> rects;
	rects.push_back(Rectangle(1));
	rects.push_back(Rectangle(2));
	for (int i = 0; i < rects.size(); i++) {
		rects[i].set_bottom_left();
		rects[i].set_top_right();
	}

	while (true) {
		int choice = 0;
		system("cls");
		cout << "Rectangle Program:" << endl << string(16, '=') << endl;
		cout << "(1)\tDisplay Rectangles" << endl;
		cout << "(2)\tFind Area" << endl;
		cout << "(3)\tFind Perimeter" << endl;
		cout << "(4)\tFind Diagonal Length" << endl;
		cout << "(5)\tFind Union" << endl;
		cout << "(6)\tFind Intersection" << endl;
		cout << "(7)\tExit" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			display_rectangles(rects);
			break;
		case 2:
			display_area(rects);
			break;
		case 3:
			display_perimeter(rects);
			break;
		case 4:
			display_diagonal(rects);
			break;
		case 5: {
			display_union(rects);
			break;
		}
		case 6: {
			display_intersect(rects);
			break;
		}
		case 7:
			cout << "Output summary:" << endl;
			display_rectangles(rects);
			display_area(rects);
			display_perimeter(rects);
			display_diagonal(rects);
			display_union(rects);
			display_intersect(rects);
			system("pause");
			return 0;
		}
		system("pause");
	}
}