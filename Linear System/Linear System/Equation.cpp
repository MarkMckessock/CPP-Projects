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
	else {
		if (str[0] == '-') {
			numerator = std::stoi(strip(strip(str, "()"), '-'));
			numerator *= -1;
		}
		else
			try {
			numerator = std::stoi(strip(str, "()"));
		}
		catch (std::invalid_argument& e) {
			throw;
		}
		denominator = 1;
	}

	if (denominator== 0) {
		std::cout << "Divide by zero error" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}


	if (numerator < 0 && denominator < 0) {
		//eliminate negative/negative
		numerator *= -1;
		denominator *= -1;
	}
	else if (numerator > 0 && denominator < 0) {
		// always keep negatives in the numerator
		numerator *= -1;
		denominator *= -1;
	}
	return boost::rational<int>(numerator, denominator);
}
Equation::Equation(std::string str) {
	std::vector<std::string> splits;
	if (!split(str, ' ', splits))
		throw std::invalid_argument("No spaces in equation");
	try {
	ls_var.push_back(splits[0].back());
	ls_var.push_back(splits[2].back());
	ls_const.push_back(make_rational(strip(splits[0], ls_var[0])));
	ls_const.push_back(make_rational(strip(splits[2], ls_var[1])));
	//check for double zero coefs
	if (ls_const[0].numerator() == 0 && ls_const[1].numerator() == 0 && rs.numerator() != 0)
		throw(std::domain_error("Invalid Equation"));
	op = splits[1][0];
	if (op == '-') {
		ls_const[1] = ls_const[1] * -1;
		op = '+';
	}
	rs = make_rational(splits[4]);
	}
	catch (std::invalid_argument& e) {
		throw;
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