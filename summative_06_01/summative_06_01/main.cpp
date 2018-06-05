#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Hands.h"
#include <iostream>
#include <string>
#include <fstream>

void hands_to_file(std::vector<Hand>& hands,std::string path,bool sorted = false) {
	std::ofstream file;
	
	if (sorted) {
		file.open(path, std::ios_base::app);//append to file when adding sorted hands
		file << "Sorting hands based on value:" << std::endl;
	}
	else {
		file.open(path);
		file << "Generated " << hands.size() << " hands." << std::endl;
	}
	file << "----------------------------------------------------" << std::endl << std::endl;
	for (unsigned int i = 1; i <= hands.size();i++) {
		file << "Hand #" << i << ":" << std::endl;
		hands[i-1].output(file);
		file << Hands::lookup[hands[i - 1].hand_type] << std::endl;
		file << std::endl;
	}
	file.close();
}

void sort_hands(std::vector<Hand>& hands) {
	/*Sort hands based on their relative value/rarity. */
	for (unsigned int i = 0; i<hands.size() - 1; i++)
		for (unsigned int j = 0; j < hands.size() - i - 1; j++) {
			if (hands[j].hand_type > hands[j + 1].hand_type) {
				Hand temp = hands[j];
				hands[j] = hands[j + 1];
				hands[j + 1] = temp;
			}
		}
}

void random_deal_hands() {
	system("cls");
	Deck deck;
	std::string hand_count_s;
	std::vector<Hand> hands;
	std::cout << "How many hands to you want to deal?" << std::endl;
	std::cin >> hand_count_s;
	try {
		int hand_count_i = std::stoi(hand_count_s);
		try {
			for (int i = 0; i < hand_count_i; i++)
				hands.push_back(deck.deal());
			for (auto& hand : hands)
				hand.get_hand_type();
		}
		catch (std::domain_error& e) {
			std::cout << e.what() << std::endl;
			return;
		}
		std::string path = "C:/Users/Mark/Documents/hands.txt";
		hands_to_file(hands, path);
		sort_hands(hands);
		hands_to_file(hands, path, true);
		std::cout << "Printed " << hand_count_i << " hands to \"" << path << "\"." << std::endl;
		system("pause");
	}
	catch (...) {
		std::cout << "Invalid number of hands entered." << std::endl;
		system("pause");
	}
}

void choose_hands() {
	system("cls");
	std::cout << "Please choose a hand to generate:" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (int i = 1; i < Hands::LAST; i++)
		std::cout << "(" << i << ") - " << Hands::lookup[static_cast<Hands::Hands>(i-1)] << std::endl;

	std::cout << std::endl;
	std::string choice_s;
	std::cin >> choice_s;

	try {
		int choice_i = std::stoi(choice_s);
		if (choice_i < Hands::LAST) {
			Hand hand(static_cast<Hands::Hands>(choice_i-1));
			std::cout << "Generated " << Hands::lookup[static_cast<Hands::Hands>(choice_i-1)] << std::endl;
			hand.output();
			std::cout << "Program determined type: " << Hands::lookup[static_cast<Hands::Hands>(hand.get_hand_type())] << std::endl;
			system("pause");
		}
		else {
			throw std::domain_error("Invalid choice");
		}
	}
	catch (...) {
		std::cout << "Invalid selection entered." << std::endl;
		system("pause");
	}
}

int main() {
	while (true) {
		system("cls");
		std::string choice;
		std::cout << "(1) - Select a number of hands to generate." << std::endl;
		std::cout << "(2) - Manually generate a specific hand." << std::endl;
		std::cout << "(3) - Quit" << std::endl;
		std::cout << "Make a selection: ";
		std::cin >> choice;
		try {
			int choice_i = std::stoi(choice);
			switch (choice_i) {
			case 1:
				random_deal_hands();
				break;
			case 2:
				choose_hands();
				break;
			case 3:
				exit(EXIT_SUCCESS);
				break;
			}
		}
		catch(...){
			system("cls");
			std::cout << "Invalid selection." << std::endl << std::endl;
			continue;
		}
	}
}