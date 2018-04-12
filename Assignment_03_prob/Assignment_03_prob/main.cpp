#include "Bag.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
using std::cout;
using std::endl;

void calculate_probability() {
	const int sims = 10000;
	int wins = 0;
	Bag bag_template(17, 8, 31, 4);//17 red, 8 blue , 31 green, 4 yellow
	for (int i = 0; i < sims; i++) {
		Bag bag = bag_template;
		if (bag.simulate(9))
			wins++;
	}
	cout << "W/L Ratio: " << (float)wins / (float)sims << endl;
	system("pause");
}

int main() {
	for (int i = 0; i < 100; i++)
		calculate_probability();
}
/*
Bag contains: # marbles
Blue = 8
Red = 17
Green = 31
Yellow = 4
Pick 9 

2R=G
2Y=B
*/