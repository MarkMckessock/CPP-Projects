#include "boost\rational.hpp"
#include "rand.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

class Expression {
public:
	boost::rational<int> operand_1;
	boost::rational<int> operand_2;
	char _operator;
	boost::rational<int> evaluate() {
		if (_operator == '/' && operand_2 == 0)
			throw std::domain_error("Divide by zero");
		switch (_operator) {
		case '+':
			return operand_1 + operand_2;
		case '-':
			return operand_1 - operand_2;
		case '*':
			return operand_1 * operand_2;
		case '/':
			return operand_1 / operand_2;
		}
	}
};

int gen_rational_operand(int min_value=0) {
	int n = rand_int(1, 100);
	return rand_int(min_value,n <= 70 ? 9 : (n > 70 && n <= 90 ? 99 : 999));
}

Expression randomize_expression() {
	Expression exp;
	int oper = rand_int(0, 3);
	switch (oper) {
	case 0:
		exp._operator = '+';
		break;
	case 1:
		exp._operator = '-';
		break;
	case 2:
		exp._operator = '*';
		break;
	case 3:
		exp._operator = '/';
		break;
	}
	exp.operand_1 = boost::rational<int>(gen_rational_operand(), gen_rational_operand(1));
	exp.operand_2 = boost::rational<int>(gen_rational_operand(), gen_rational_operand(1));
	return exp;
}

int main() {
	int expr_count;
	std::vector<Expression> expressions;
	cout << "How many expressions do you want to generate?" << endl;
	cin >> expr_count;

	for (int i = 0; i < expr_count; i++) {
		expressions.push_back(randomize_expression());
	}

	std::ofstream file;
	file.open("C:/Users/Mark/Documents/expressions.txt");
	for (auto& exp : expressions) {
		try {
			boost::rational<int> result = exp.evaluate();
			file << exp.operand_1.numerator() << ((exp.operand_1.denominator() == 1) ? "" : "/" + std::to_string(exp.operand_1.denominator())) << " " << exp._operator << " " << exp.operand_2.numerator() << ((exp.operand_2.denominator() == 1) ? "" : "/" + std::to_string(exp.operand_2.denominator())) << " = " << result.numerator() << ((result.denominator() == 1) ? "" : "/" + std::to_string(result.denominator())) << endl << endl;
		}
		catch (std::domain_error& e) {
			file << exp.operand_1.numerator() << ((exp.operand_1.denominator() == 1) ? "" : "/" + std::to_string(exp.operand_1.denominator())) << " " << exp._operator << " " << exp.operand_2.numerator() << ((exp.operand_2.denominator() == 1) ? "" : "/" + std::to_string(exp.operand_2.denominator())) << " = Divide by Zero Error" << endl << endl;
		}
	}
	file.close();
	system("pause");
}