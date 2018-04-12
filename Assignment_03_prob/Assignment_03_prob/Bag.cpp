#include "Bag.h"
#include "rand.h"
#include <iostream>

Bag::Bag(){}

Bag::Bag(int _r_count, int _b_count, int _g_count, int _y_count) {
	for (int i = 0; i < _r_count; i++)
		marbles.push_back(Marble(Red));
	for (int i = 0; i < _b_count; i++)
		marbles.push_back(Marble(Blue));
	for (int i = 0; i < _g_count; i++)
		marbles.push_back(Marble(Green));
	for (int i = 0; i < _y_count; i++)
		marbles.push_back(Marble(Yellow));
}

Marble Bag::draw() {
	int rand = rand_int(0, marbles.size()-1);
	Marble draw = marbles[rand];
	marbles.erase(marbles.begin() + rand);
	return draw;
}

bool Bag::simulate(int _sim_count) {
	std::map<Color, int> count;
	for (int i = 0; i < _sim_count; i++)
		count[draw().color]++;
	return 2*count[Yellow] == count[Blue] || 2*count[Red] == count[Green];
}