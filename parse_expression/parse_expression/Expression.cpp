#include <string>
#include <iostream>
#include <algorithm>
#include "functions.h"
#include "boost\rational.hpp"
#include "Expression.h"

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

Expression::Expression(std::string str){
	std::vector<std::string> splits;
	std::string ls, rs;
	//empty string
	if (str.size() == 0)
		throw std::domain_error("Invalid Expression: Empty string");
	//catch invalid chars
	for (auto& item : str) {
		if (item < '0' && item > '9' && (!is_operator(item) && item != ')' && item != '(' && item != ' '))
			throw std::domain_error("Invalid Expression: Invalid character entered");
	}
	//find spaces in between numbers
	if (split(str, ' ', splits)) {
		for (int i = 0; i < splits.size()-1; i++) {
			if (is_int(splits[i].back()) && is_int(splits[i + 1][0]))
				throw std::domain_error("Invalid Expression: Spaces in operand");
		}
	}
	//remove spaces and brackets
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	str = strip(str, "()");

	//operator is '+'
	if (split(str, '+', splits)) {
		if (splits.size() > 2)
			throw std::domain_error("Invalid Expression: More than 1 '+' character");
		_operator = '+';
		ls = splits[0];
		rs = splits[1];
	}
	//operator is '*'
	else if (split(str, '*', splits)) {
		if (splits.size() > 2)
			throw std::domain_error("Invalid Expression: More than 1 '*' character");
		_operator = '*';
		ls = splits[0];
		rs = splits[1];
	}
	//operator is '/'
	else if (split(str, '/', splits) && splits.size() > 3) {
		_operator = '/';
		ls = splits[0] + '/' + splits[1];
		rs = splits[2] + '/' + splits[3];
	}
	//operatir is '-'
	else if (split(str, '-', splits)) {
		_operator = '-';
		ls = splits[0];
		rs = splits[1];
	}
	else
		throw std::domain_error("Invalid Expression: No operator found");
	try {
		operand_1 = make_rational(ls);
		operand_2 = make_rational(rs);
	}
	catch (...) {
		throw;
	}

	//ex 4 - (-4) -> 4 + 4
	if (_operator == '-' && operand_2.numerator() < 0) {
		operand_2 *= -1;
		_operator = '+';
	}
	//ex 4 + (-4) -> 4 - 4
	else if (_operator == '+' && operand_2.numerator() < 0) {
		operand_2 *= -1;
		_operator = '-';
	}

	//Prevent division by 0
	if (_operator == '/' && operand_2 == 0)
		throw std::domain_error("Undefined Expression: Divide by zero");
}

std::string Expression::get_string() {
	std::string operand_1_str = operand_1.denominator() == 1 ? std::to_string(operand_1.numerator()) : std::to_string(operand_1.numerator()) + "/" + std::to_string(operand_1.denominator());
	std::string operand_2_str = operand_2.denominator() == 1 ? std::to_string(operand_2.numerator()) : std::to_string(operand_2.numerator()) + "/" + std::to_string(operand_2.denominator());
	return operand_1_str + " " + _operator + " " + operand_2_str;
}

