#include "Fraction.h"
#include "strip.h"
#include "split.h"
#include <string>
#include <vector>
#include <iostream>

Fraction::Fraction(){}

Fraction::Fraction(std::string str) {
	std::vector<std::string> splits;
	if (split(str, '/', splits)) {
		std::cout  << strip(splits[0], "()");
		//num = strip(splits[0],"()");
		//den = strip(splits[1],"()");
	}
	/*else
		num = str;*/
}