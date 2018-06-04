#include "Hand.h"
#include "Card.h"
#include "Color.h"
#include "Rank.h"
#include "split.h"
#include <map>
#include <algorithm>
#include <iostream>

Hand::Hand(std::vector<Card> _cards):cards(_cards){}

Hand::Hand(Hands::Hands hand_type) {
	switch (hand_type) {
	case Hands::Straight_flush:
		generate_cards("R2,R3,R4,R5,R6,RJ");
		break;
	case Hands::Six_of_kind:
		generate_cards("R1,G1,B1,V1,M1,Y1");
		break;
	case Hands::Flush:
		generate_cards("R2,R4,R5,R6,RK,RA");
		break;
	case Hands::Five_of_kind:
		generate_cards("R2,R3,B2,G2,Y2,V2");
		break;
	case Hands::Two_three_of_kinds:
		generate_cards("BQ,RQ,YQ,G4,Y4,R4");
		break;
	case Hands::Four_of_kind_pair:
		generate_cards("R5,B5,Y5,G5,YQ,RQ");
		break;
	case Hands::Four_of_kind:
		generate_cards("R4,B4,Y4,G4,Y2,BK");
		break;
	case Hands::Straight:
		generate_cards("Y2,G3,R4,B5,G6,VJ");
		break;
	case Hands::Three_pair:
		generate_cards("Y3,G3,B4,R4,V6,M6");
		break;
	case Hands::Three_kind_pair:
		generate_cards("R2,B2,G2,Y4,G4,BK");
		break;
	case Hands::Bust:
		generate_cards("B2,YK,GJ,VA,B6,RQ");
		break;
	case Hands::Three_kind:
		generate_cards("B2,G2,R2,G6,MK,Y3");
		break;
	case Hands::two_pair:
		generate_cards("B2,G2,R3,B3,MK,V5");
		break;
	case Hands::pair:
		generate_cards("B2,R2,G5,R6,YK,VA");
		break;
	}
}

void Hand::generate_cards(std::string card_string) {
	std::map<char, Rank::Rank> ranks = { {'2',Rank::two},{'3',Rank::three},{'4',Rank::four},{'5',Rank::five},{'6',Rank::six},{'J',Rank::Jack},{'Q',Rank::Queen},{'K',Rank::King},{'A',Rank::Ace} };
	std::map<char, Color::Color> colors = { {'R',Color::red},{'B',Color::blue},{'G',Color::green},{'Y',Color::yellow},{'P',Color::pink},{'M',Color::magenta},{'V',Color::violet} };
	std::vector<std::string> card_str;
	split(card_string, ',', card_str);
	for (auto& card : card_str)
		cards.push_back(Card(colors[card[0]], ranks[card[1]]));
}

void Hand::sort() {
	for(unsigned int i = 0;i<cards.size()-1;i++)
		for (unsigned int j = 0; j < cards.size()-i-1; j++) {
			if (cards[j].rank > cards[j+1].rank) {
				Card temp = cards[j];
				cards[j] = cards[j+1];
				cards[j+1] = temp;
			}
		}
}

void Hand::output() {
	for (auto& card : cards) {
		std::cout << static_cast<char>(toupper(Color::lookup[card.color][0])) << Rank::lookup[card.rank][0] << " ";
	}
	std::cout << std::endl;
}

void Hand::output(std::ofstream& file) {
	for (auto& card : cards) {
		file << static_cast<char>(toupper(Color::lookup[card.color][0])) << Rank::lookup[card.rank][0] << " ";
	}
	file << std::endl;
}
Hands::Hands Hand::get_hand_type(){
	std::map<Color::Color, int> suit_count;
	std::map<Rank::Rank, int> rank_count;
	int pair_count = 0;
	sort();
	for (auto& card : cards) {
		suit_count[card.color]++;
		rank_count[card.rank]++;
	}

	int color_count = suit_count.size();
	int value_count = rank_count.size();

	int max_rank = 0;
	for (int i = 0; i < static_cast<int>(Rank::LAST);i++) {
		max_rank = std::max(max_rank, rank_count[static_cast<Rank::Rank>(i)]);
	}

	int max_color = 0;
	for (int i = 0; i < static_cast<int>(Color::LAST); i++) {
		max_color = std::max(max_color, suit_count[static_cast<Color::Color>(i)]);
	}

	//std::cout << "Max Rank " << max_rank << " Max Color " << max_color << "color count " << color_count << " Rank Count " << value_count << std::endl;

	//Straight Flush
	bool seq = true;
	if (max_color == 6) {
		for (unsigned int i = 0; i < cards.size() - 1; i++)
			seq = seq && cards[i].rank == cards[i + 1].rank - 1;
		if (seq) {
			hand_type = Hands::Straight_flush;
			return hand_type;
		}
	}

	//Six of a Kind
	if (max_rank == 6) {
		hand_type = Hands::Six_of_kind;
		return hand_type;
	}

	//Flush
	if (max_color == 6) {
		hand_type = Hands::Flush;
		return hand_type;
	}

	//Five of a Kind
	if (max_rank == 5) {
		hand_type = Hands::Five_of_kind;
		return hand_type;
	}

	//Two x Three of a Kind
	if (max_rank == 3 && value_count == 2) {
		hand_type = Hands::Two_three_of_kinds;
		return hand_type;
	}

	//Four of a Kind and a Pair
	if (max_rank == 4 && value_count == 2) {
		hand_type = Hands::Four_of_kind_pair;
		return hand_type;
	}

	//Four of a kind
	if (max_rank == 4) {
		hand_type = Hands::Four_of_kind;
		return hand_type;
	}
	//Straight
	seq = true;
	for (unsigned int i = 0; i < cards.size() - 1; i++)
		seq = seq && cards[i].rank == cards[i + 1].rank - 1;
	if (seq) {
		hand_type = Hands::Straight;
		return hand_type;
	}

	//Three Pair
	if (max_rank == 2) {
		for (int i = 0; i < Rank::LAST; i++)
			if (rank_count[static_cast<Rank::Rank>(i)] == 2)
				pair_count++;
		if (pair_count == 3) {
			hand_type = Hands::Three_pair;
			return hand_type;
		}
	}

	//Three of a kind and a Pair
	if (max_rank == 3)
		for (int i = 0; i < static_cast<int>(Rank::LAST) - 1; i++) {
			if (rank_count[static_cast<Rank::Rank>(i)] == 2) {
				hand_type = Hands::Three_kind_pair;
				return hand_type;
			}
		}

	//Bust
	if (max_rank == 1) {
		hand_type = Hands::Bust;
		return hand_type;
	}

	//Three of a Kind
	if (max_rank == 3) {
		hand_type = Hands::Three_kind;
		return hand_type;
	}

	//One or Two pairs
	if (max_rank == 2) {

		if (pair_count == 2) {
			hand_type = Hands::two_pair;
			return hand_type;
		}
		else if (pair_count == 1) {
			hand_type = Hands::pair;
			return hand_type;
		}
	}
	throw std::logic_error("No hand type found");
}

