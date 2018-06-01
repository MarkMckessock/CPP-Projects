#include <vector>
#include <array>
#include "rand.h"
#include <map>
#include <string>
#include <iostream>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_COLOUR 0
#define MAX_COLOUR 3
#define NUM_COLOURS 4
#define MIN_VALUE 0
#define MAX_VALUE 9

enum color { blue, yellow, red, green };
std::map<color, std::string> color_lookup = { {blue,"Blue"},{yellow,"Yellow"},{red,"Red"},{green,"Green"} };

class cell {
public:
	cell() {
		opened = false;
		value = rand_int(0, 9);
		_color = static_cast<color>(rand_int(0, 3));
	}
	void output() {
		opened ? std::cout << color_lookup[_color][0] << value << "O" : std::cout << color_lookup[_color][0] << value << "C ";
	}
	color _color;
	int value;
	bool opened;
};


class board {
public:
	std::vector<std::vector<cell>> grid;

	board(int columns, int rows) :rows(rows),columns(columns){
		grid.resize(columns);
		for (int i = 0; i < columns; i++)
			grid[i].resize(rows);
	}

	void output() {
		int x = 0,y=0;
		while (y < rows) {
			while (x < columns) {
				grid[x][y].output();
				x++;
			}
			std::cout << std::endl;
			y++;
			x = 0;
		}
	}
private:
	int rows;
	int columns;
};

int main() {
	board gb(2, 3);
	gb.output();
	system("pause");
}
