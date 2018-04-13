#include "RandBunny.h"
#include "rand.h"
#include <array>



RandBunny::RandBunny(std::string _name,bool supress_output): Bunny(_name,supress_output){
	color = static_cast<Color>(rand_int(0, 3));
}


