#include "rand.h"
#include "color.h"
#include <map>
#include <iostream>

int main() {
	const int sims = 10000;
	const int trials = 9;
	const int red_count = 17;
	const int blue_count = 8;
	const int green_count = 31;
	const int yellow_count = 4;
	int wins = 0;

	for (int i = 0; i < sims; i++) {
		std::map<Color, int> count;
		for (int j = 0; j < trials; j++) {
			int rand = rand_int(1, (red_count + blue_count + green_count + yellow_count));
			if (rand <= yellow_count)
				count[Yellow]++;
			else if (rand <= yellow_count + blue_count && rand > yellow_count)
				count[Blue]++;
			else if (rand <= yellow_count + blue_count + red_count && rand > yellow_count + blue_count)
				count[Red]++;
			else if (rand <= yellow_count + blue_count + red_count + green_count && rand > yellow_count + blue_count+ red_count)
				count[Green]++;
		}
		if (2 * count[Yellow] == count[Blue] || 2 * count[Red] == count[Green])
			wins++;
	}

	std::cout << "W/L Ratio: " << (float)wins / (float)sims << std::endl;
	system("pause");
}