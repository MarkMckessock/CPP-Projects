#include "Equation.h"
#include "split.h"
#include "strip.h"
#include <vector>
#include <string>
#include <stdexcept>

Equation::Equation(){}

Equation::Equation(std::string str) {
	std::vector<std::string> splits;
	if (!split(str, ' ', splits))
		throw std::invalid_argument("No spaces in equation");
	try {
	ls_var.push_back(splits[0].back());
	ls_var.push_back(splits[2].back());
	ls_const.push_back(Fraction(strip(splits[0], ls_var[0])));
	ls_const.push_back(Fraction(strip(splits[2], ls_var[1])));
	op = splits[1][0];
	if (op == '-') {
		ls_const[1] = ls_const[1] * -1;
		op = '+';
	}
	rs = Fraction(splits[4]);
	}
	catch (std::invalid_argument& e) {
		throw;
	}
}

Equation::Equation(Fraction cons_1, char _op, Fraction cons_2,std::vector<char> vars) {
	op = _op;
	ls_const.push_back(cons_1);
	ls_const.push_back(cons_2);
	ls_var = vars;
}

std::string Equation::get_string() {
	return ls_const[0].get_string() + ls_var[0] + " " + op + " " + ls_const[1].get_string() + ls_var[1] + " = " + rs.get_string();
}

char Equation::get_op() {
	return op;
}

Fraction Equation::get_rs() {
	return rs;
}

std::vector<Fraction> Equation::get_ls_const() {
	return ls_const;
}

std::vector<char> Equation::get_ls_var() {
	return ls_var;
}