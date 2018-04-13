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

int cull(std::list<Bunny> &bunnies, std::vector<Bunny*> &mutants, std::map<Sex, std::vector<Bunny*>> &fertility, std::map<int, std::map<int,bool>>& empty_spaces) {
	int death_toll = bunnies.size() / 2;
	auto iter = bunnies.begin();
	for (int i = 0; i < death_toll; i++) {
		std::advance(iter, rand_int(0, 1));
		iter = iter->kill(bunnies, mutants, fertility, iter,empty_spaces, true);
	}
	return death_toll;
}

void draw_grid(std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid) {
	for (int i = 0; i < 50; i++) {
		std::cout << " _";
	}
	std::cout << std::endl;
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 50; x++) {
			std::cout << "|";
			if (!empty_spaces[x][y]) {
				if (grid[x][y]->is_radioactive)
					std::cout << "V";
				else if ((grid[x][y])->sex == male) {
					if (grid[x][y]->age >= 2)
						std::cout << "M";
					else
						std::cout << "m";
				}
				else {
					if (grid[x][y]->age >= 2)
						std::cout << "F";
					else
						std::cout << "f";
				}
			}
			else
				std::cout << "_";
		}
		std::cout << "|" << std::endl;
	}
}

void reproduce(std::list<Bunny> &bunnies, std::map<Sex,std::vector<Bunny*>> &fertility,Names names,std::vector<Bunny*>& mutants,std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid,bool show_births,bool show_deaths){
	if (fertility[male].size() > 0)
		for (int i = 0; i < fertility[female].size(); i++) {
			if (bunnies.size() > 999) {
				if(show_deaths)
					std::cout << "A food shortage occurred killing " << cull(bunnies, mutants, fertility,empty_spaces) << " bunnies." << std::endl;
				return;
			}
			auto possible_spawns = fertility[female][i]->get_surrounding_empty_spaces(empty_spaces);
			if (possible_spawns.size()) {
				bunnies.push_back(Bunny(names.choose(), (*fertility[female][i]).color,!show_births));
				auto iter = bunnies.end();
				--iter;
				iter->set_grid(empty_spaces,grid,possible_spawns[rand_int(0,possible_spawns.size()-1)]);
			}
		}
}

void infect_bunnies(std::list<Bunny> &bunnies,std::vector<Bunny*> &mutants,std::map<Sex,std::vector<Bunny*>> &fertility, std::array<std::array<Bunny*, 20>, 50>& grid, std::map<int, std::map<int, bool>>& empty_spaces,bool show_infections){
	int mutant_count = mutants.size();
	std::vector<std::pair<int,int>> surrounding_bunnies;
	for (int i = 0; i < mutant_count; i++) {
		surrounding_bunnies = mutants[i]->get_surround_uninfected(empty_spaces,grid);
		if (surrounding_bunnies.size()) {
			std::pair<int, int> target = surrounding_bunnies[rand_int(0, surrounding_bunnies.size() - 1)];
			mutants.push_back(grid[target.first][target.second]->infect(fertility,!show_infections));
		}
	}
}

void gen_original_bunnies(std::list<Bunny> &bunnies,Names names, std::map<int, std::map<int, bool>>& empty_spaces,std::array<std::array<Bunny*, 20>, 50>& grid,bool supress_output) {
	for (int i = 0; i < 5; i++) {
		bunnies.push_back(RandBunny(names.choose(),!supress_output));
		auto iter = bunnies.end();
		--iter;
		iter->set_grid(empty_spaces,grid);
	}
}

int main() {
	Names names;
	std::list<Bunny> bunnies;
	std::array<std::array<Bunny*, 20>, 50> grid;
	std::map<int,std::map<int,bool>> empty_spaces;
	for (int x = 0; x < 50; x++)
		for (int y = 0; y < 20; y++)
			empty_spaces[x][y] = true;
	std::map<Sex, std::vector<Bunny*>> fertility;
	std::vector<Bunny*> mutants;
	const bool show_births = false;
	const bool show_deaths = false;
	const bool show_infections = false;
	const bool show_grid = true;
	const bool show_stats = false;

	gen_original_bunnies(bunnies, names,empty_spaces,grid,show_births);

	while (bunnies.size()) {
		reproduce(bunnies, fertility, names, mutants, empty_spaces, grid,show_births,show_deaths);
		for (auto iter = bunnies.begin(); iter != bunnies.end();) {
			//add mutants to vector at birth
			if (iter->age == 0 && iter->is_radioactive)
				mutants.push_back(&(*iter));

			iter->increase_age(1);

			//bunnies move randomly 1 space in any direction
			if(iter->age != 1)
				iter->move(empty_spaces, grid);

			//bunny becomes fertile at 2 years
			if (iter->age == 2 && !iter->is_radioactive) 
				fertility[iter->sex].push_back(&(*iter));

			//bunny dies @ 10 years and mutants die @ 50 years
			if (iter->age == iter->lifespan)
				iter = iter->kill(bunnies,mutants,fertility,iter,empty_spaces,!show_deaths);
			else
				iter++;
		}			
		infect_bunnies(bunnies,mutants,fertility,grid,empty_spaces,show_infections);
		if(show_stats)
			std::cout << "Bunnies alive: " << bunnies.size() << " Mutants: " << mutants.size() << " Fertile: " << fertility[female].size() << std::endl;
		system("cls");
		if(show_grid)
			draw_grid(empty_spaces, grid);
	}
	std::cout << "All bunnies have died. Simulation terminated." << std::endl;
	system("pause");
}