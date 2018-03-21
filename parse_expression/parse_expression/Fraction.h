#include <string>

#ifndef FRACTION
#define FRACTION

class Fraction{
public:
	Fraction();
	Fraction(std::string);
private:
	int num;
	int div;
};

#endif
