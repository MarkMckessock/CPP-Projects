#include <string>
#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Rectangle.h"
using namespace std;

void display_rectangles(vector<Rectangle> rects) {
	system("cls");
	for (int i = 0; i < rects.size(); i++)
		cout << "Rectangle " << i + 1 << ": (" << rects[i].get_bottom_left().x << ","
		<< rects[i].get_bottom_left().y << ")\t(" << rects[i].get_top_right().x
		<< ", " << rects[i].get_top_right().y << ")" << endl;
}

Rectangle get_union(Rectangle rect_1, Rectangle rect_2) {
	Rectangle result;
	result.set_bottom_left(Coordinate((rect_1.get_bottom_left().x < rect_2.get_bottom_left().x ? rect_1.get_bottom_left().x : rect_2.get_bottom_left().x),
		(rect_1.get_bottom_left().y < rect_2.get_bottom_left().y ? rect_1.get_bottom_left().y : rect_2.get_bottom_left().y)));
	result.set_top_right(Coordinate((rect_1.get_top_right().x > rect_2.get_top_right().x ? rect_1.get_top_right().x : rect_2.get_top_right().x), 
		(rect_1.get_top_right().y > rect_2.get_top_right().y ? rect_1.get_top_right().y : rect_2.get_top_right().y)));
	return result;
}

bool get_intersection(Rectangle rect_1, Rectangle rect_2,Rectangle &intersect_rect) {
	Rectangle result(Coordinate(((rect_1.get_bottom_left().x > rect_2.get_bottom_left().x && rect_1.get_bottom_left().x < rect_2.get_top_right().x) ? rect_1.get_bottom_left().x : rect_2.get_bottom_left().x), 
		((rect_1.get_bottom_left().y > rect_2.get_bottom_left().y && rect_1.get_bottom_left().y < rect_2.get_top_right().y) ? rect_1.get_bottom_left().y : rect_2.get_bottom_left().y)),
		Coordinate(((rect_1.get_top_right().x > rect_2.get_bottom_left().x && rect_1.get_top_right().x < rect_2.get_top_right().x) ? rect_1.get_top_right().x : rect_2.get_top_right().x),
		((rect_1.get_top_right().y > rect_2.get_bottom_left().y && rect_1.get_top_right().y < rect_2.get_top_right().y) ? rect_1.get_top_right().y : rect_2.get_top_right().y)));
	intersect_rect = result;
	//determine if general intersection occurs
	if ((rect_2.get_bottom_left().y >= rect_1.get_bottom_left().y && rect_2.get_bottom_left().y < rect_1.get_top_right().y ||
		rect_1.get_bottom_left().y > rect_2.get_bottom_left().y && rect_1.get_bottom_left().y < rect_2.get_top_right().y) &&
		(rect_1.get_bottom_left().x >= rect_2.get_bottom_left().x && rect_1.get_bottom_left().x < rect_2.get_top_right().x ||
			rect_2.get_bottom_left().x > rect_1.get_bottom_left().x && rect_2.get_bottom_left().x < rect_1.get_top_right().x))
		return true;
	else
		return false;
}

int main() {
	vector<Rectangle> rects;
	rects.push_back(Rectangle());
	rects.push_back(Rectangle());
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

		switch (choice) {
		case 1:
			display_rectangles(rects);
			system("pause");
			break;
		case 2:
			display_rectangles(rects);
			for (int i = 0; i < rects.size(); i++) {
				cout << "Area of rectangle " << i + 1 << " = " << rects[i].get_area() << " units^2" << endl;
			}
			system("pause");
			break;
		case 3:
			display_rectangles(rects);
			for (int i = 0; i < rects.size(); i++) {
				cout << "Perimeter of rectangle " << i + 1 << " = " << rects[i].get_perimeter() << " units" << endl;
			}
			system("pause");
			break;
		case 4:
			display_rectangles(rects);
			for (int i = 0; i < rects.size(); i++) {
				cout << "Diagonal length of rectangle " << i + 1 << "=" << rects[i].get_diagonal() << "units" << endl;
			}
			system("pause");
			break;
		case 5: {
			display_rectangles(rects);
			Rectangle union_rect;
			union_rect = get_union(rects[0], rects[1]);
			cout << "The union rectangle of rectange 1 & 2 is: (" << union_rect.get_bottom_left().x << ", " << union_rect.get_bottom_left().y
				<< ")\t(" << union_rect.get_top_right().x << ", " << union_rect.get_top_right().y << ")" << endl;
			system("pause");
			break;
		}
		case 6: {
			display_rectangles(rects);
			Rectangle intersect_rect;
			if (get_intersection(rects[0], rects[1], intersect_rect))
				cout << "The intersection rectange 1 & 2 is: (" << intersect_rect.get_bottom_left().x << ", " << intersect_rect.get_bottom_left().y
				<< ")\t(" << intersect_rect.get_top_right().x << ", " << intersect_rect.get_top_right().y << ")" << endl;
			else
				cout << "There is no intersection between rectangles 1 & 2." << endl;
			system("pause");
			break;
		}
		case 7:
			return 0;
		}
	}
}