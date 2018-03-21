#include <vector>
#include <string>
#include <iostream>

#ifndef SPLIT
#define SPLIT

bool split (std::string& s, char delimiter, std::vector<std::string> &split_target){
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
	split_target = splits;
	if (splits.size() > 0)
		return true;
	else
		return false;
}

#endif