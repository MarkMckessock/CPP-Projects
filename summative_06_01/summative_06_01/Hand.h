#include <vector>
#include "Card.h"
#include "Hands.h"
#include <fstream>
#include <string>

#ifndef HAND
#define HAND

class Hand{
	std::vector<Card> cards;
public:
	Hand(std::vector<Card> _cards);
	Hand(Hands::Hands);
	Hands::Hands get_hand_type();
	Hands::Hands hand_type;
	void sort();
	void output();
	void output(std::ofstream& file);
	void parse_card_string(std::string);
};

#endif

