#include <string>

#ifndef STRIP
#define STRIP

std::string strip(std::string str, char strip_char) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == strip_char)
			str.erase(str[i]);
	}
	return str;
}

std::string strip(std::string str, std::string strip_chars) {
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < strip_chars.size(); j++) {
			if (str[i] == strip_chars[j])
				str.erase(str[i]);
		}
	}
	return str;
}

#endif // !SPLIT
