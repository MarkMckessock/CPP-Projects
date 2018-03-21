#include "Expression.h"
#include "Fraction.h"
#include "split.h"
#include <iostream>
#include <vector>
#include <string>

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
		for (int i = 0; i < splits.size(); i++)
			if (splits[i].size() > 1)
				operands.push_back(Fraction(splits[i]));
			else
				operators.push_back(splits[i]);
		std::cout << std::endl;
		system("pause");
	}
}