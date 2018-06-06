#pragma once
#include <map>
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include "split.h"

class Matrix{
public:
	Matrix();
	std::map<std::string, std::map<std::string, double>> values;
	void parse(std::string);
	void output();
	Matrix operator*(Matrix&);
};

