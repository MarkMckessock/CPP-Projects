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
	std::list<Bunny>::iterator kill(std::list<Bunny>&, std::vector<Bunny*>&, std::map<Sex, std::vector<Bunny*>>&, std::list<Bunny>::iterator,bool suppress_output = false);
	void infect(std::map<Sex, std::vector<Bunny*>>&);

	int age;
	Color color;
	Sex sex;
	bool is_radioactive;
	std::string name;
	int lifespan;
};

#endif