#include <map>

#ifndef HANDS
#define HANDS

namespace Hands {
	enum Hands { Straight_flush, Six_of_kind, Flush, Five_of_kind, Two_three_of_kinds, Four_of_kind_pair, Four_of_kind, Straight, Three_pair, Three_kind_pair, Bust, Three_kind, two_pair, pair };
	extern std::map<Hands, std::string> lookup;
}

#endif