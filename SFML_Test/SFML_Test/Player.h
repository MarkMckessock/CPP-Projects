#ifndef SFML_GRAPHICS
#define SFML_GRAPHICS
#include <SFML\Graphics.hpp>
#endif // !SFML_GRAPHICS
#ifndef ENTITY
#define ENTITY
#include "Entity.h"
#endif // !ENTITY
#define PLAYER



class Player : public Entity{
public:
	//Player();
	void watch_mouse(sf::Vector2i mouse_pos);
};