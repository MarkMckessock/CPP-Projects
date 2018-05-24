#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <array>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_COLOUR 0
#define MAX_COLOUR 3
#define NUM_COLOURS 4
#define MIN_VALUE 0
#define MAX_VALUE 9



const char COLOURS[NUM_COLOURS][12] = { "blue", "yellow", "red", "green" };

enum color { blue, yellow, red, green };
enum status { incomplete, inprogress, complete };
enum suit { clubs, diamonds, hearts, spades };

class cell{
public:
	cell() {}
	color color;
	int value;
	bool opened;
};


class board{
public:
	board(int rows,int columns) {
		grid = new std::array<std::array<cell, columns>, rows>;
	};
	~board(){
		delete grid;
	}
	std::<std::vector<cell>> grid;
};

int rb(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	board gb(2,3);

	gb.grid[1][1].color = green;
	gb.grid[1][1].value = 6;
	gb.grid[1][1].opened = 0;	// set to closed

	gb.grid[1][2].color = red;
	gb.grid[1][2].value = 3;
	gb.grid[1][2].opened = 1;	// set to open

	gb.grid[1][3].color = yellow;
	gb.grid[1][3].value = 0;
	gb.grid[1][3].opened = 0;

	/*
	Your Turn
	=========
	Save as version 02 and delete my demo code.

	Call a function to randomly initialize the gameboard. During initialization, set
	all cells to closed (opened is 0)

	Output your game board to the screens as follows:
	R6C B7C	G0C Y2C
	G9C B1C	B2C R0C

	In the above output, you had a gameboard with 2 rows and 4 columns.
	Feel free to change COLOURS if you think it might make this job easier.

	*/

	srand(time(NULL));//required for "randomness"
	system("pause");
}
