#include <string>
#include <vector>
#include "Fraction.h"

#ifndef EQUATION
#define EQUATION

class Equation{
public:
	Equation();
	Equation(std::string);
	Equation(Fraction, char, Fraction,std::vector<char>);
	std::string get_string();
	char get_op();
	Fraction get_rs();
	std::vector<Fraction> get_ls_const();
	std::vector<char> get_ls_var();
private:
	Fraction rs;
	std::vector<Fraction> ls_const;
	std::vector<char> ls_var;
	char op;
};

#endif