#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Hands.h"
#include <iostream>
#include <string>
#include <fstream>

void hands_to_file(std::vector<Hand>& hands,std::string path) {

}

int main() {
	Deck deck;
	int hand_count;
	std::vector<Hand> hands;
	std::cout << "How many hands to you want to deal?";
	std::cin >> hand_count;
	try {
		for (int i = 0; i < hand_count; i++) {
			hands.push_back(deck.deal());
		}
		system("cls");
		for (auto& hand : hands) {
			hand.output();
			std::cout << Hands::lookup[hand.get_hand_type()]  << std::endl << std::endl;
		}
	}
	catch (std::domain_error& e) {
		std::cout << e.what() <<  std::endl;
	}
	system("pause");
}