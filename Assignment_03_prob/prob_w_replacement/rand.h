#include <random>


#ifndef RANDOM
#define RANDOM

inline int rand_int(int low, int high) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(low, high); // define the range
	return distr(eng);
}

#endif