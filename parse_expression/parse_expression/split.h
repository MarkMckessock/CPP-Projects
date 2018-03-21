#include <vector>
#include <string>
#include <iostream>

#ifndef SPLIT
#define SPLIT

std::vector<std::string> split(std::string& s, char delimiter){
	std::vector<std::string> splits;
	std::string split = "";
	int i = 0;
	while (i < s.size()) {
		while (s[i] != delimiter && i < s.size()) {
			split += s[i];
			i++;
		}
		splits.push_back(split);
		split = "";
		i++;
	}
	return splits;
}

#endif