#include <string>
#include <cinttypes>

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
	int64_t num;
	int64_t den;
};

#endif
