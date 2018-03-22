#include "Fraction.h"
#include "strip.h"
#include "split.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

Fraction::Fraction(){}

Fraction::Fraction(std::string str) {
	std::vector<std::string> splits;
	if (split(str, '/', splits)) {
		//interpret negative values
		if (strip(splits[0], "()")[0] == '-') {
			num = std::stoi(strip(strip(splits[0], "()"), '-'));
			num *= -1;
		}
		else
			num = std::stoi(strip(splits[0], "()"));
		if (strip(splits[1], "()")[0] == '-') {
			den = std::stoi(strip(strip(splits[1], "()"), '-'));
			num *= -1;
		}
		else
			den = std::stoi(strip(splits[1], "()"));
	}
	else {
		if (str[0] == '-') {
			num = std::stoi(strip(strip(str, "()"), '-'));
			num *= -1;
		}
		else
			num = std::stoi(strip(str,"()"));
		den = 1;
	}

	if (den == 0){
		std::cout << "Divide by zero error" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
		

	if (num < 0 && den < 0) {
		//eliminate negative/negative
		num *= -1;
		den *= -1;
	}
	else if (num > 0 && den < 0) {
		// always keep negatives in the numerator
		num *= -1;
		den *= -1;
	}
}
