#include <map>

#ifndef RANK
#define RANK

namespace Rank {
	enum Rank { two, three, four, five, six, Jack, Queen, King, Ace, LAST };
	extern std::map<Rank, std::string> lookup;
}

#endif