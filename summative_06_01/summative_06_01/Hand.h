#include <vector>
#include "Card.h"
#include "Hands.h"
#include <fstream>
#include <string>

#ifndef HAND
#define HAND

class Hand{
public:
	Hand(std::vector<Card> _cards);
	Hand(Hands::Hands);
	std::vector<Card> cards;
	Hands::Hands get_hand_type();
	Hands::Hands hand_type;
	void sort();
	void output();
	void output(std::ofstream& file);
	void generate_cards(std::string);
};

#endif

