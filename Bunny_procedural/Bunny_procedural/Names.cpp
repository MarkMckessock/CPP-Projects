#include "Names.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "rand.h"



Names::Names(){
	std::ifstream names_file("names.txt");
	std::copy(std::istream_iterator<std::string>(names_file),std::istream_iterator<std::string>(),std::back_inserter(names));
}


std::string Names::choose() {
	return names[rand_int(0, names.size() - 1)];
}