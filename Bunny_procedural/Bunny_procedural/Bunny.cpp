#include "Bunny.h"
#include "rand.h"
#include "Names.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <array>
#include <list>



Bunny::Bunny(std::string _name){
	sex = rand_int(0, 1) ? male : female;
	age = 0;
	is_radioactive = rand_int(1, 100) <= 2;
	name = _name;
	if (is_radioactive) {
		lifespan = 50;
		std::cout << "Radioactive Mutant Vampire Bunny " << name << " was born." << std::endl;
	}
	else {
		lifespan = 10;
		std::cout << "Bunny " << name << " was born." << std::endl;
	}
}

Bunny::Bunny(std::string _name, Color _color) :Bunny(_name) {
	color = _color;
}


void Bunny::increase_age(int age_years) {
	age += age_years;
}

void Bunny::print() {
	std::cout << "Bunny: " << name << ", Age: " << age << ", Color: " << color << ", Sex: " << sex << std::endl;
}

void Bunny::make_infertile(std::map<Sex, std::vector<Bunny*>> &fertility){
	fertility[sex].erase(std::remove(fertility[sex].begin(), fertility[sex].end(), this), fertility[sex].end());
}

std::list<Bunny>::iterator Bunny::kill(std::list<Bunny>& bunnies, std::vector<Bunny*>& mutants, std::map<Sex,std::vector<Bunny*>>& fertile_bunnies, std::list<Bunny>::iterator iter, std::map<int, std::map<int, bool>>& empty_spaces, bool suppress_output) {
	if (is_radioactive) {
		mutants.erase(std::remove(mutants.begin(), mutants.end(), this), mutants.end());
		if(!suppress_output)
			std::cout << "Radioactive Mutant Vampire Bunny " << name << " has died." << std::endl;
	}
	else {
		//fertile_bunnies.erase(std::remove(fertile_bunnies.begin(), fertile_bunnies.end(), &(*iter)), fertile_bunnies.end());
		make_infertile(fertile_bunnies);
		if(!suppress_output)
			std::cout << "Bunny " << name << " has died." << std::endl;
	}
	empty_spaces[location.first][location.second] = true;
	return bunnies.erase(iter);
}

Bunny* Bunny::infect(std::map<Sex, std::vector<Bunny*>> &fertility) {
	is_radioactive = true;
	lifespan = 50;
	std::cout << "Bunny " << name << " became infected." << std::endl;
	make_infertile(fertility);
	return this;
}

void Bunny::set_grid(std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid) {
	int x, y;
	do {
		x = rand_int(0, empty_spaces.size() - 1);
		y = rand_int(0, empty_spaces[x].size() - 1);
	} while (!empty_spaces[x][y]);
	location.first = x;
	location.second = y;
	grid[x][y] = this;
	empty_spaces[x][y] = false;
}

void Bunny::set_grid(std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid,std::pair<int, int> spawn_location) {
	location = spawn_location;
	grid[spawn_location.first][spawn_location.second] = this;
	empty_spaces[spawn_location.first][spawn_location.second] = false;
}

std::vector<std::pair<int, int>> Bunny::get_surrounding_empty_spaces(std::map<int, std::map<int, bool>>& empty_spaces) {
	std::vector<std::pair<int, int>> result;
	if (empty_spaces[location.first][location.second - 1])
		result.push_back(std::pair<int, int>(location.first, location.second - 1));
	if (empty_spaces[location.first][location.second + 1])
		result.push_back(std::pair<int, int>(location.first, location.second + 1));
	if (empty_spaces[location.first+1][location.second])
		result.push_back(std::pair<int, int>(location.first+1, location.second));
	if (empty_spaces[location.first+1][location.second - 1])
		result.push_back(std::pair<int, int>(location.first+1, location.second - 1));
	if (empty_spaces[location.first+1][location.second + 1])
		result.push_back(std::pair<int, int>(location.first+1, location.second + 1));
	if (empty_spaces[location.first-1][location.second ])
		result.push_back(std::pair<int, int>(location.first-1, location.second));
	if (empty_spaces[location.first-1][location.second - 1])
		result.push_back(std::pair<int, int>(location.first-1, location.second - 1));
	if (empty_spaces[location.first-1][location.second + 1])
		result.push_back(std::pair<int, int>(location.first-1, location.second + 1));
	return result;
}

std::vector<std::pair<int, int>> Bunny::get_surround_uninfected(std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid) {
	std::vector<std::pair<int, int>> result;
	if (location.first > 0) {
		if (!empty_spaces[location.first - 1][location.second] && !grid[location.first - 1][location.second]->is_radioactive)
			result.push_back(std::pair<int, int>(location.first - 1, location.second));
		if(location.second > 0)
			if (!empty_spaces[location.first - 1][location.second - 1] && !grid[location.first - 1][location.second - 1]->is_radioactive)
				result.push_back(std::pair<int, int>(location.first - 1, location.second - 1));
		if(location.second < grid[location.first-1].size()-1)
			if (!empty_spaces[location.first - 1][location.second + 1] && !grid[location.first - 1][location.second + 1]->is_radioactive)
				result.push_back(std::pair<int, int>(location.first - 1, location.second + 1));
	}
	if (location.first < grid.size() - 1) {
		if (!empty_spaces[location.first + 1][location.second] && !grid[location.first + 1][location.second]->is_radioactive)
			result.push_back(std::pair<int, int>(location.first + 1, location.second));
		if(location.second > 0)
			if (!empty_spaces[location.first + 1][location.second - 1] && !grid[location.first + 1][location.second - 1]->is_radioactive)
				result.push_back(std::pair<int, int>(location.first + 1, location.second - 1));
		if(location.second < grid[location.first+1].size()-1)
			if (!empty_spaces[location.first + 1][location.second + 1] && !grid[location.first + 1][location.second + 1]->is_radioactive)
				result.push_back(std::pair<int, int>(location.first + 1, location.second + 1));
	}
	if(location.second < grid[location.first].size()-1)
		if (!empty_spaces[location.first][location.second + 1] && !grid[location.first][location.second + 1]->is_radioactive)
			result.push_back(std::pair<int, int>(location.first, location.second + 1));
	if (location.second > 0)
		if (!empty_spaces[location.first][location.second - 1] && !grid[location.first][location.second - 1]->is_radioactive)
			result.push_back(std::pair<int, int>(location.first, location.second - 1));
	return result;
}

void Bunny::move(std::map<int, std::map<int, bool>>& empty_spaces, std::array<std::array<Bunny*, 20>, 50>& grid) {
	auto possible_moves = get_surrounding_empty_spaces(empty_spaces);
	if (possible_moves.size()) {
		auto move_location = possible_moves[rand_int(0, possible_moves.size() - 1)];
		//std::cout << "Current " << location.first << ", " << location.second << " New " << move_location.first << ", " << move_location.second << std::endl;
		empty_spaces[location.first][location.second] = true;
		empty_spaces[move_location.first][move_location.second] = false;
		grid[move_location.first][move_location.second] = this;
		location = move_location;
	}
}
