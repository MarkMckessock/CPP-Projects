#include <vector>
#include <map>
#include "Marble.h"

#ifndef BAG
#define BAG

class Bag{
public:
	Bag();
	Bag(int, int, int, int);
	Marble draw();
	bool simulate(int);
private:
	std::vector<Marble> marbles;
};

#endif
