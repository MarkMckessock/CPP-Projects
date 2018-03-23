#include <string>
#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Rectangle.h"
#include "rect_func.h"
using namespace std;


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
		default:
			cout << "Invalid choice";
			break;
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