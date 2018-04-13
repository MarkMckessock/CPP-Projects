#ifndef RANDBUNNY
#define RANDBUNNY

#include "Bunny.h"
class RandBunny : public Bunny{
public:
	RandBunny(std::string, bool supress_output=false);
};

#endif