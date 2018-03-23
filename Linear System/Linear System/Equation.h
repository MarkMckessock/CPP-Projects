#include <string>
#include <vector>
#include "boost\rational.hpp"

#ifndef EQUATION
#define EQUATION

class Equation{
public:
	Equation();
	Equation(std::string);
	Equation(boost::rational<int>, char, boost::rational<int>,std::vector<char>);
	std::string get_string();
	char get_op();
	boost::rational<int> get_rs();
	std::vector<boost::rational<int>> get_ls_const();
	std::vector<char> get_ls_var();
private:
	boost::rational<int> rs;
	std::vector<boost::rational<int>> ls_const;
	std::vector<char> ls_var;
	char op;
};

#endif