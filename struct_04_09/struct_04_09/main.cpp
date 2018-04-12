#include <iostream>
#include <vector>
#include <string>

/*
Write code in which you ask the user how many line segments he or she
wishes to enter.

Now get this many line segments from the user. ALL coordinates must
be between -9 and 9.

Output all of the lines segments one segment per line.
Use my user-defined functions if you wish ... or ignore them and use
no built-in functions ... add some of your own if you wish.

THIS DOES NOT CONSTITUTE TEACHING YOU FUNCTIONS IN C!
Some of you will read my code and figure out alot for yourself while others
will require direct instruction. Do your best today.
*/

typedef struct {
	int x;
	int y;
} pointType;

typedef struct {
	pointType A;
	pointType B;
	int index;
} lineSegType;

bool is_valid_coord(int x, int min, int max) {
	// returns either 1(true) or 0 (false)
	return x >= min && x <= max;
}

bool is_valid_coord(pointType point, int min, int max) {
	return point.x >= min && point.x <= max && point.y >= min && point.y <= max;
}

void output_line(lineSegType line) {
	std::cout << "Line " << line.index << " : (" << line.A.x << "," << line.A.y << "), (" << line.B.x << "," << line.B.y << ")" << std::endl;
}

pointType get_point(int minX, int maxX, int minY, int maxY,int line_index) {
	pointType point;
	std::string input;
	getline(std::cin, input);
	do {
		system("cls");
		std::cout << "Enter the x value of your point(" << minX << "," << maxX << ") for line #" << line_index << std::endl;
		getline(std::cin, input);
	} while (!is_valid_coord(std::stoi(input), minX, maxX));
	point.x = std::stoi(input);

	do {
		system("cls");
		std::cout << "Enter the y value of your point (" << minY << "," << maxY << ") for line #" << line_index << std::endl;
		std::cin >> input;
	} while (!is_valid_coord(std::stoi(input),minY,maxY));
	point.y = std::stoi(input);

	return point;
}

lineSegType get_line_segment(int minX, int maxX, int minY, int maxY, int index) {
	lineSegType line = {get_point(minX, maxX, minY, maxY,index),get_point(minX, maxX, minY, maxY,index),index};
	return line;
}

int main() {
	const int min_coord = -9;
	const int max_coord = 9;
	srand(time(NULL)); // Don't delete this!

	std::cout << "How many line segments do you wish to enter?" << std::endl;
	int line_segment_count;
	std::cin >> line_segment_count;
	std::vector<lineSegType> line_segments;
	for (int i = 0; i < line_segment_count; i++)
		line_segments.push_back(get_line_segment(min_coord, max_coord,min_coord,max_coord,i+1));

	for (int i = 0; i < line_segments.size(); i++)
		output_line(line_segments[i]);

	system("pause");
}
