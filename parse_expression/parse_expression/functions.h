#include <string>
#include <algorithm>
#include <vector>

#ifndef FUNC
#define FUNC

inline bool is_operator(char _char) {
	return _char == '+' || _char == '-' || _char == '*' || _char == '/';
}

inline bool is_int(char _char) {
	return _char >= '0' && _char <= '9';
}

inline std::string strip(std::string str, char strip_char) {
	str.erase(std::remove(str.begin(), str.end(), strip_char), str.end());
	return str;
}

inline std::string strip(std::string str, std::string strip_chars) {
	for (int i = 0; i < strip_chars.size(); i++) {
		str.erase(std::remove(str.begin(), str.end(), strip_chars[i]), str.end());
	}
	return str;
}

inline bool split(std::string& s, char delimiter, std::vector<std::string> &split_target) {
	std::vector<std::string> splits;
	std::string split = "";
	int i = 0;
	bool empty_split = true;
	while (i < s.size()) {
		while ((s[i] != delimiter || i == 0 || is_operator(s[i - 1])) && i < s.size()) {
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
