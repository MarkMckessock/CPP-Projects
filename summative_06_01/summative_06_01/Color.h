#include <map>

#ifndef COLOR
#define COLOR

namespace Color {
	enum Color { red, blue, green, yellow, pink, violet, magenta, LAST };
	extern std::map<Color, std::string> lookup;
}

#endif