#include "Expression.h"
#include "Fraction.h"
#include "is_operator.h"
#include "split.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

Expression::Expression(){}

void Expression::read() {
	std::cout << "Enter your expression" << std::endl;
	std::getline(std::cin,expr_string);
	system("cls");
}

void Expression::parse() {
	//split string by spaces
	std::vector<std::string> splits;
	if (split(expr_string, ' ', splits)) {
		//convert operands to fraction types & strip brackets
		//check for double negatives
		for (int i = 0; i < splits.size(); i++) {
			if (splits[i][0] == '*' || splits[i][0] == '+' || splits[i][0] == '/' || (splits[i][0] == '-' && splits[i].size() == 1))
				operators.push_back(splits[i]);
			else

				operands.push_back(Fraction(splits[i]));
		}
	}
	else
		throw std::domain_error("No Spaces found in expression");

	if (!validate())
		throw std::domain_error("Invalid Expression");
}

void Expression::print() {
	for (int i = 0; i < operands.size(); i++) {
		if (operands[i].den == 1)
			std::cout << operands[i].num;
		else
			std::cout << "(" << operands[i].num << "/" << operands[i].den << ")";
		//Change -- to +
		if (i < operands.size() - 1) {
			if (operands[i + 1].num < 0 && operators[i] == "-") {
				operators[i] = "+";
				operands[i + 1].num *= -1;
			}
			std::cout << operators[i];
		}
	}
	std::cout << std::endl;
}

bool Expression::validate() {
	for (int i = 0; i < expr_string.size(); i++) {
		//check that all + and * operators are surrounded by space
		if (expr_string[i] == '*' || expr_string[i] == '+') {
			if(i > 0)
				if (expr_string[i - 1] != ' ')
					return false;
			if (i < expr_string.size() - 1)
				if (expr_string[i + 1] != ' ')
					return false;
		}
		
		//two operators next to eachother
		if (is_operator(expr_string[i]) && is_operator(expr_string[i + 1]))
			return false;
		//' ' before '/' but char after
		if (expr_string[i] == '/' && expr_string[i + 1] == ' ' && expr_string[i - 1] != ' ')
			return false;
		if (expr_string[i] == '/' && expr_string[i + 1] != ' ' && expr_string[i - 1] == ' ')
			return false;
		//check for letters
		if (expr_string[i] < '0' && expr_string[i] > '9' && !is_operator(expr_string[i]) && expr_string[i] != ' ' && expr_string[i] != ')' && expr_string[i] != '(')
			return false;
	}
	return true;
}