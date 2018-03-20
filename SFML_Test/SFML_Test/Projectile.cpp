#include "Projectile.h"
#include <SFML\Graphics.hpp>

Projectile::Projectile(){}

void Projectile::move_projectile(){
	sf::Vector2f movement;
	movement.x = cos(atan2f(direction_vector.y, direction_vector.x))*veclocity;
	movement.y = sin(atan2f(direction_vector.y, direction_vector.x))*veclocity;
	move(movement);
}
