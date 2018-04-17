#include <vector>
#include <string>
#include <iostream>

#ifndef SPLIT
#define SPLIT

inline bool split (std::string& s, char delimiter, std::vector<std::string> &split_target){
	std::vector<std::string> splits;
	std::string split = "";
	int i = 0;
	bool empty_split = true;
	while (i < s.size()) {
		while (s[i] != delimiter && i < s.size()) {
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