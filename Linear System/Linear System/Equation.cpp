#include "Equation.h"
#include "split.h"
#include "strip.h"
#include <vector>
#include <string>
#include <stdexcept>
#include "boost\rational.hpp"
#include "rational_to_string.h"

Equation::Equation(){}

boost::rational<int> make_rational(std::string str) {
	int numerator, denominator;
	std::vector<std::string> splits;
	if (split(str, '/', splits)) {
		//interpret negative values
		if (strip(splits[0], "()")[0] == '-') {
			numerator = std::stoi(strip(strip(splits[0], "()"), '-'));
			numerator *= -1;
		}
		else
			numerator = std::stoi(strip(splits[0], "()"));

		if (strip(splits[1], "()")[0] == '-') {
			denominator = std::stoi(strip(strip(splits[1], "()"), '-'));
			numerator *= -1;
		}
		else
			denominator = std::stoi(strip(splits[1], "()"));
	}
	//operand is a single number (not a fraction)
	else {
		if (str[0] == '-') {
			numerator = std::stoi(strip(strip(str, "()"), '-'));
			numerator *= -1;
		}
		else
			try {
			numerator = std::stoi(strip(str, "()"));
		}
		catch (...) {
			throw;
		}
		denominator = 1;
	}
	try {
		return boost::rational<int>(numerator, denominator);
	}
	catch (...) {
		throw std::domain_error("Undefined Expression: Divide by zero");
	}
}

Equation::Equation(std::string str) {
	//remove all spaces
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	//get ls of eqn
	std::vector<std::string> splits;
	if (split(str, '+', splits)) {
		op = '+';
	}
	else {
		op = '-';
		split(str, '-', splits);
	}
	std::vector<std::string> sub_split;
	if (!split(splits[0], ')', sub_split))
		throw std::domain_error("Brackets are required");
	ls_var.push_back(sub_split[1][0]);
	ls_const.push_back(make_rational(sub_split[0]));

	if (!split(splits[1], '=', sub_split))
		throw std::domain_error("Equals sign is required");
	if (!split(sub_split[0], ')', splits))
		throw std::domain_error("Brackets are required");
	ls_var.push_back(splits[1][0]);
	ls_const.push_back(make_rational(splits[0]));
	//get rs of eqn
	if (split(str, '=', splits))
		rs = make_rational(splits[1]);
	else
		throw std::domain_error("Equation must have '='");
	//check for double zero coef
	//check for --
	if (op == '-' && ls_const[1] < 0) {
		op = '+';
		ls_const[1] *= -1;
	}
	//check for +-
	if (op == '+' && ls_const[1] < 0) {
		op = '-';
		ls_const[1] *= -1;
	}
}

Equation::Equation(boost::rational<int> cons_1, char _op, boost::rational<int> cons_2,std::vector<char> vars) {
	op = _op;
	ls_const.push_back(cons_1);
	ls_const.push_back(cons_2);
	ls_var = vars;
}

std::string Equation::get_string() {
	std::string result;
	result = rational_to_string(ls_const[0]) + ls_var[0] + " " + op + " " + rational_to_string(ls_const[1]) + ls_var[1] + " = " + rational_to_string(rs);
	return result;
}
char Equation::get_op() {
	return op;
}

boost::rational<int> Equation::get_rs() {
	return rs;
}

std::vector<boost::rational<int>> Equation::get_ls_const() {
	return ls_const;
}

std::vector<char> Equation::get_ls_var() {
	return ls_var;
}