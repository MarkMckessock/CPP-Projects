#include "RandBunny.h"
#include "rand.h"
#include <array>



RandBunny::RandBunny(std::string _name): Bunny(_name){
	color = static_cast<Color>(rand_int(0, 3));
}


