#include <vector>
#include "Card.h"
#include "Hands.h"

#ifndef HAND
#define HAND

class Hand{
public:
	Hand(std::vector<Card> _cards);
	std::vector<Card> cards;
	Hands::Hands get_hand_type();
	void sort();
	void output();
};

#endif

