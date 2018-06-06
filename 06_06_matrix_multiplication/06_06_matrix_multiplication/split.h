#include <vector>
#include <string>
#include <iostream>

#ifndef SPLIT
#define SPLIT

inline std::vector<std::string> split(std::string& s, char delimiter) {
	std::vector<std::string> splits;
	std::string split = "";
	unsigned int i = 0;
	bool empty_split = true;
	while (i < s.size()) {
		while (i < s.size() && (s[i] != delimiter || delimiter == '-' && (s[i - 1] == '(' || s[i - 1] == '/' || s[i - 1] == '='))) {
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
	return splits;
}

#endif