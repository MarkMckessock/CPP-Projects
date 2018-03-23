#pragma once
#include <string>
#include "boost\rational.hpp"
#include <algorithm>

#ifndef RAT2STRING
#define RAT2STRING

inline std::string rational_to_string(boost::rational<int> rational) {
	std::string str;
	str = "(" + std::to_string(rational.numerator()) + "/" + std::to_string(rational.denominator()) + ")";
	return str;
 }

#endif