#include "Types.h"
#include <string>
#include <map>
#include <vector>
#include <list>

#ifndef BUNNY
#define BUNNY

class Bunny {
public:
	Bunny(std::string _name);
	Bunny(std::string _name, Color _color);
	void increase_age(int);
	void print();
	void make_infertile(std::map<Sex,std::vector<Bunny*>>&);
	std::list<Bunny>::iterator kill(std::list<Bunny>&, std::vector<Bunny*>&, std::map<Sex, std::vector<Bunny*>>&, std::list<Bunny>::iterator, std::map<int, std::map<int, bool>>&, bool suppress_output = false);
	Bunny* infect(std::map<Sex, std::vector<Bunny*>>&);
	void set_grid(std::map<int, std::map<int, bool>>&, std::array<std::array<Bunny*, 20>, 50>&);
	void set_grid(std::map<int, std::map<int, bool>>&, std::array<std::array<Bunny*, 20>, 50>&,std::pair<int, int>);
	void move(std::map<int, std::map<int, bool>>&, std::array<std::array<Bunny*, 20>, 50>&);
	std::vector<std::pair<int, int>> get_surrounding_empty_spaces(std::map<int, std::map<int, bool>>&);
	std::vector<std::pair<int, int>> get_surround_uninfected(std::map<int, std::map<int, bool>>&, std::array<std::array<Bunny*, 20>, 50>&);

	int age;
	Color color;
	Sex sex;
	bool is_radioactive;
	std::string name;
	int lifespan;
	std::pair<int, int> location;
};

#endif