#include <SFML\Graphics.hpp>
#include "Character.h"

#ifndef PLAYER
#define PLAYER

class Player : public Character{
public:
	//Player();
	void watch_mouse(sf::Vector2f mouse_pos);
};

#endif