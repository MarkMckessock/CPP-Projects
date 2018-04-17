#include "Expression.h"
#include <string>
#include "split.h"
#include "strip.h"
#include "boost\rational.hpp"

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
	//catch divide by 0
	if (denominator == 0) {
		throw std::domain_error("Divide by zero");
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

Expression::Expression(std::string str){
	for (auto& item : str) {
		if (item ==*(&item + 1) && is_operator(item))
			throw std::domain_error("Invalid expression (Double operator)");
	}
	std::vector<std::string> splits;
	if (split(str, '-', splits)) {
		if (splits.size() > 2)
			throw std::domain_error("Invalid Expression");
		_operator = '-';
		try {
			operand_1 = make_rational(splits[0]);
			operand_2 = make_rational(splits[1]);
		}
		catch (...) {
			throw;
		}
	}
	else if (split(str, '+', splits)) {
		if (splits.size() > 2)
			throw std::domain_error("Invalid Expression");
		_operator = '+';
		try {
			operand_1 = make_rational(splits[0]);
			operand_2 = make_rational(splits[1]);
		}
		catch (...) {
			throw;
		}
	}
	else if (split(str, '*', splits)) {
		if (splits.size() > 2)
			throw std::domain_error("Invalid Expression");
		_operator = '*';
		try {
			operand_1 = make_rational(splits[0]);
			operand_2 = make_rational(splits[1]);
		}
		catch (...) {
			throw;
		}
	}
	else if (split(str, '/', splits)) {
		_operator = '/';
		try {
			operand_1 = make_rational(splits[0] + '/' + splits[1]);
			operand_2 = make_rational(splits[2] + '/' + splits[3]);
		}
		catch (...) {
			throw;
		}
	}
	if (_operator == '-' && operand_2.numerator() < 0) {
		operand_2 *= -1;
		_operator = '+';
	}
	else if (_operator == '+' && operand_2.numerator() < 0) {
		operand_2 *= -1;
		_operator = '-';
	}

}

std::string Expression::get_string() {
	std::string operand_1_str = operand_1.denominator() == 1 ? std::to_string(operand_1.numerator()) : std::to_string(operand_1.numerator()) + "/" + std::to_string(operand_1.denominator());
	std::string operand_2_str = operand_2.denominator() == 1 ? std::to_string(operand_2.numerator()) : std::to_string(operand_2.numerator()) + "/" + std::to_string(operand_2.denominator());
	return operand_1_str + " " + _operator + " " + operand_2_str;
}

