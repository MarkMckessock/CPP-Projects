#include "Equation.h"
#include <string>
#include "boost\rational.hpp"

#ifndef SYSTEM
#define SYSTEM

class System{
public:
	System();
	System(std::string, std::string);
	std::string get_string();
	std::string solve();
private:
	Equation eqn_1;
	Equation eqn_2;
};

#endif
