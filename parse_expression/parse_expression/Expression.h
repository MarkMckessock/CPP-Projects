#include "Fraction.h"
#include <vector>
#include <string>

#ifndef EXPRESSION
#define EXPRESSION

class Expression{
public:
	Expression();
	void read();
	void parse();
	void print();
	bool validate();
private:	
	std::vector<Fraction> operands;
	std::vector<std::string> operators;
	std::string expr_string;
};

#endif
