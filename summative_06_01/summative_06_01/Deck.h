#pragma once
#include "enum_types.h"
#include <vector>
#include "Card.h"
class Deck{
public:
	Deck();
	std::vector<Card> cards;
	std::vector<Card> deal();
};

