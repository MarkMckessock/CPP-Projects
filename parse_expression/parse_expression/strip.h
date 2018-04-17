#include <string>
#include <algorithm>
#ifndef STRIP
#define STRIP

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

#endif // !SPLIT
