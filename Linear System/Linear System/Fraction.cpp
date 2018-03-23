#include "Fraction.h"
#include "strip.h"
#include "split.h"
#include <string>
#include <vector>
#include <algorithm>
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
			try {
			num = std::stoi(strip(str, "()"));
		}
		catch (std::invalid_argument& e) {
			throw;
		}
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

std::string Fraction::get_string() {
	if (den == 1)
		return std::to_string(num);
	else {
		return "(" + std::to_string(num) + "/" + std::to_string(den) + ")";
	}
}

Fraction Fraction::operator/(const Fraction& arg) {
	Fraction frac;
	frac.num = arg.den * this->num;
	frac.den = arg.num * this->den;
	if (frac.num < 0 && frac.den < 0) {
		frac.num *= -1;
		frac.den *= -1;
	}
	else if (frac.den < 0) {
		frac.num *= -1;
		frac.den *= -1;
	}
	return frac;
}

Fraction Fraction::operator*(const int& arg){
	Fraction frac;
	frac.num = this->num * arg;
	frac.den = this->den;
	if (frac.num < 0 && frac.den < 0) {
		frac.num *= -1;
		frac.den *= -1;
	}
	else if (frac.den < 0) {
		frac.num *= -1;
		frac.den *= -1;
	}
	return frac;
}

Fraction Fraction::operator*(const Fraction& arg) {
	Fraction frac;
	frac.num = this->num * arg.num;
	frac.den = this->den * arg.den;
	return frac;
}

Fraction Fraction::operator+(const Fraction& arg) {
	Fraction frac;
	frac.den = this->den * arg.den;
	frac.num = (arg.num*this->den) + (arg.den*this->num);
	return frac;
}

Fraction Fraction::operator-(const Fraction& arg) {
	Fraction frac;
	frac.den = this->den * arg.den;
	frac.num = (arg.den*this->num) - (arg.num*this->den);
	return frac;
}

Fraction Fraction::simplify() {
	for (int i = 2; i < std::min(num, den); i++) {
		if (std::min(num, den) % i == 0 && std::max(num, den) % i == 0) {
			num /= i;
			den /= i;
		}
	}
	return *this;
}