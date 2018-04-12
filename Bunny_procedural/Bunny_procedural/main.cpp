#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include "Bunny.h"
#include "RandBunny.h"
#include "Names.h"
#include "rand.h"

int cull(std::list<Bunny> &bunnies, std::vector<Bunny*> &mutants, std::map<Sex, std::vector<Bunny*>> &fertility) {
	int death_toll = bunnies.size() / 2;
	auto iter = bunnies.begin();
	for (int i = 0; i < death_toll; i++) {
		std::advance(iter, rand_int(0, 1));
		iter = iter->kill(bunnies, mutants, fertility, iter, true);
	}
	return death_toll;
}

void draw_grid() {
	for (int i = 0; i < 50; i++) {
		std::cout << " _";
	}
	std::cout << std::endl;
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 50; j++) {
			std::cout << "|" << "_";
		}
		std::cout << "|" << std::endl;
	}
}

void reproduce(std::list<Bunny> &bunnies, std::map<Sex,std::vector<Bunny*>> &fertility,Names names,std::vector<Bunny*>& mutants){
	if (fertility[male].size() > 0)
		for (int i = 0; i < fertility[female].size(); i++) {
			if (bunnies.size() > 1000) {
				std::cout << "A food shortage occurred killing " << cull(bunnies, mutants, fertility) << " bunnies." << std::endl;
				return;
			}
			bunnies.push_back(Bunny(names.choose(), (*fertility[female][i]).color));
		}
}

void infect_bunnies(std::list<Bunny> &bunnies,std::vector<Bunny*> &mutants,std::map<Sex,std::vector<Bunny*>> &fertility){
	for (int i = 0; i < mutants.size(); i++) {
		auto iter = bunnies.begin();
		std::advance(iter, rand_int(0, bunnies.size()-1));
		iter->infect(fertility);
	}
}

void gen_original_bunnies(std::list<Bunny> &bunnies,Names names) {
	for (int i = 0; i < 5; i++)
		bunnies.push_back(RandBunny(names.choose()));
}

int main() {
	Names names;
	std::list<Bunny> bunnies;
	gen_original_bunnies(bunnies, names);
	std::map<Sex, std::vector<Bunny*>> fertility;
	std::vector<Bunny*> mutants;
	std::array<std::array<Bunny*, 20>, 50> grid;
	std::vector<std::pair<int, int>> empty_spaces;

	while (bunnies.size()) {
		for (auto iter = bunnies.begin(); iter != bunnies.end();) {
			if (iter->age == 0 && iter->is_radioactive)//add mutants to vector at birth
				mutants.push_back(&(*iter));
			iter->increase_age(1);
			if (iter->age == 2 && !iter->is_radioactive) //bunny becomes fertile
				fertility[iter->sex].push_back(&(*iter));
			else {
				if (iter->age == iter->lifespan)//bunny dies
					//iter = kill_bunny(bunnies, fertility, mutants, iter);
					iter = iter->kill(bunnies,mutants,fertility,iter);
				else
					iter++;
			}
		}			
		std::cout << "Bunnies alive: " << bunnies.size() << " Mutants: " << mutants.size() << " Fertile: " << fertility[female].size() << std::endl;
		draw_grid();
		system("pause");
		reproduce(bunnies,fertility,names,mutants);
		infect_bunnies(bunnies,mutants,fertility);

	}
}