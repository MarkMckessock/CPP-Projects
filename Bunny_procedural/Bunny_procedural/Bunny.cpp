#include "Bunny.h"
#include "rand.h"
#include "Names.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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

Bunny::Bunny(std::string _name, Color _color):Bunny(_name){
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

std::list<Bunny>::iterator Bunny::kill(std::list<Bunny>& bunnies, std::vector<Bunny*>& mutants, std::map<Sex,std::vector<Bunny*>>& fertile_bunnies, std::list<Bunny>::iterator iter, bool suppress_output) {
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
	return bunnies.erase(iter);
}

void Bunny::infect(std::map<Sex, std::vector<Bunny*>> &fertility) {
	is_radioactive = true;
	lifespan = 50;
	std::cout << "Bunny " << name << " became infected." << std::endl;
	make_infertile(fertility);
}