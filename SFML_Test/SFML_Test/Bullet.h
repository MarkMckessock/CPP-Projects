#include <SFML\Graphics.hpp>
#include "Projectile.h"

#ifndef BULLET
#define BULLET
class Bullet : public Projectile{
public:
	Bullet(sf::Texture texture, sf::Vector2f vector);
};

#endif
