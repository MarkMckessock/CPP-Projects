#include "boost\rational.hpp"
#include <string>

class Expression{
public:
	Expression(std::string str);
	std::string get_string();
private:
	boost::rational<int> operand_1;
	boost::rational<int> operand_2;
	char _operator;

};

