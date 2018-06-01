#include "Deck.h"
#include "rand.h"
#include <map>

Deck::Deck(){
	for(int i = 0; i < static_cast<int>(Color::LAST)-1; i++) {
		for (int j = 0; j < static_cast<int>(Rank::LAST)-1; j++) {
			cards.push_back(Card(static_cast<Color>(i), static_cast<Rank>(j)));
		}
	}
}

std::vector<Card> Deck::deal() {
	if (cards.size() < 6)
		throw std::domain_error("Not enough cards remaining");
	std::vector<Card> hand;
	for (int i = 0; i < 6; i++) {
		int index = rand_int(0, cards.size());
		hand.push_back(cards[index]);
		cards.erase(cards.begin() + index);
	}
}
