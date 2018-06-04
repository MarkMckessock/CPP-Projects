#include "Hand.h"
#include "Card.h"
#include "Color.h"
#include "Rank.h"
#include <map>
#include <algorithm>
#include <iostream>

Hand::Hand(std::vector<Card> _cards):cards(_cards){}

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
		std::cout << Color::lookup[card.color][0] << Rank::lookup[card.rank][0] << " ";
	}
	std::cout << std::endl;
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

	

	std::cout << "Max Rank " << max_rank << " Max Color " << max_color << "color count " << color_count << " Rank Count " << value_count << std::endl;

	//Straight Flush
	bool seq = true;
	if (max_color == 6) {
		for (int i = 0; i < cards.size() - 1; i++)
			seq = seq && cards[i].rank == cards[i + 1].rank + 1;
		if (seq)
			return Hands::Straight_flush;
	}

	//Six of a Kind
	if (max_rank == 6)
		return Hands::Six_of_kind;

	//Flush
	if (max_color == 6)
		return Hands::Flush;

	//Five of a Kind
	if (max_rank == 5)
		return Hands::Five_of_kind;

	//Two x Three of a Kind
	if (max_rank == 3 && color_count == 2)
		return Hands::Two_three_of_kinds;

	//Four of a Kind and a Pair
	if (max_rank == 4 && color_count == 2)
		return Hands::Four_of_kind_pair;

	//Four of a kind
	if (max_rank == 4)
		return Hands::Four_of_kind;

	//Straight
	seq = true;
	for (int i = 0; i < cards.size() - 1; i++)
		seq = seq && cards[i].rank == cards[i + 1].rank + 1;
	if (seq)
		return Hands::Straight_flush;

	//Three Pair
	if (max_rank == 2) {
		for (int i = 0; i < Rank::LAST; i++)
			if (rank_count[static_cast<Rank::Rank>(i)] == 2)
				pair_count++;
		if (pair_count == 3)
			return Hands::Three_pair;
	}

	//Three of a kind and a Pair
	if (max_rank == 3)
		for (int i = 0; i < static_cast<int>(Rank::LAST) - 1; i++) {
			if (rank_count[static_cast<Rank::Rank>(i)] == 2)
				return Hands::Three_kind_pair;
		}

	//Bust
	if (max_rank == 1)
		return Hands::Bust;

	//Three of a Kind
	if (max_rank == 3)
		return Hands::Three_kind;

	//One or Two pairs
	if (max_rank == 2) {
		
		if (pair_count == 2)
			return Hands::two_pair;
		else if (pair_count == 1)
			return Hands::pair;
	}
}

