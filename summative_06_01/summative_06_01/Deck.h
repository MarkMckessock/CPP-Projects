#include "Rank.h"
#include "Color.h"
#include <vector>
#include "Card.h"
#include "Hand.h"

#ifndef DECK
#define DECK

class Deck{
public:
	Deck();
	std::vector<Card> cards;
	Hand deal();
};

#endif
