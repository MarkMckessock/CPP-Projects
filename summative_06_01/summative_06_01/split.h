#include <vector>
#include <string>
#include <iostream>

#ifndef SPLIT
#define SPLIT

inline bool split (std::string& s, char delimiter, std::vector<std::string> &split_target){
	/*Splits a string into a vector of stringss if possible, otherwise returns false.*/
	std::vector<std::string> splits;
	std::string split = "";
	unsigned int i = 0;
	bool empty_split = true;
	while (i < s.size()) {
		while (i < s.size() && s[i] != delimiter ) {
			empty_split = false;
			split += s[i];
			i++;
		}
		if (!empty_split) {
			splits.push_back(split);
			split = "";
			empty_split = true;
		}
		i++;
	}
	split_target = splits;
	if (splits.size() > 1)
		return true;
	else
		return false;
}

#endif