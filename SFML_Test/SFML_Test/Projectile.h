#include <SFML\Graphics.hpp>
#include "Entity.h"

#ifndef PROJECTILE
#define	PROJECTILE
class Projectile : public Entity{
public:
	Projectile();
	void move_projectile();
	sf::Vector2f direction_vector;
private:
	int veclocity;
};

#endif
