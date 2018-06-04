#include "Deck.h"
#include "rand.h"
#include "Hand.h"
#include <map>

Deck::Deck(){
	for(int i = 0; i < static_cast<int>(Color::LAST); i++) {
		for (int j = 0; j < static_cast<int>(Rank::LAST); j++) {
			cards.push_back(Card(static_cast<Color::Color>(i), static_cast<Rank::Rank>(j)));
		}
	}
}

Hand Deck::deal() {
	if (cards.size() < 6)
		throw std::domain_error("Not enough cards to deal all hands.");
	std::vector<Card> hand;
	for (int i = 0; i < 6; i++) {
		int index = rand_int(0, cards.size()-1);
		hand.push_back(cards[index]);
		cards.erase(cards.begin() + index);
	}
	return Hand(hand);
}
