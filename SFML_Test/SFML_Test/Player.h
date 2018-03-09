#include <SFML\Graphics.hpp>
#include "Entity.h"

#ifndef PLAYER
#define PLAYER

class Player : public Entity{
public:
	//Player();
	void watch_mouse(sf::Vector2i mouse_pos);
};

#endif