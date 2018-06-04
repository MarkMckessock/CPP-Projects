#include "Rank.h"
#include "Color.h"

#ifndef CARD
#define CARD
 
class Card{
public:
	Card(Color::Color _color, Rank::Rank _rank);
	Color::Color color;
	Rank::Rank rank;
};

#endif