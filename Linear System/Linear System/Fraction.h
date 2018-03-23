#include <string>

#ifndef FRACTION
#define FRACTION

class Fraction{
public:
	Fraction();
	Fraction(std::string);
	Fraction operator/(const Fraction&);
	Fraction operator*(const int&);
	Fraction operator*(const Fraction&);
	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	std::string get_string();
	Fraction simplify();
	int num;
	int den;
};

#endif
