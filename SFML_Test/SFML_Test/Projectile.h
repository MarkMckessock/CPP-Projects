#include <SFML\Graphics.hpp>

#ifndef PROJECTILE
#define	PROJECTILE
class Projectile : public sf::Sprite {
public:
	Projectile();
	void move_projectile();
	sf::Vector2f direction_vector;
private:
	int veclocity;
};

#endif
