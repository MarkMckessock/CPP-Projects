#include "Bullet.h"
#include "Collision.h"
#include "Layer.h"

Bullet::Bullet(sf::Texture texture, sf::Vector2f vector){
	setTexture(texture);
	direction_vector = vector;
	setOrigin(8.f, 1.f);
}


