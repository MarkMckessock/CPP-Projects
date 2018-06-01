#include "Card.h"
#include "Deck.h"
#include <iostream>

int main() {
	Deck deck;
	int hand_count;
	std::cout << "How many hands to you want to deal?";
	std::cin >> hand_count;
	std::vector<Card> hand_1 = deck.deal();
}