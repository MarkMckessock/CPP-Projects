#include "Entity.h"
#include "Bullet.h"
#include "SFML\Graphics.hpp"
#include "Layer.h"

#ifndef CHARACTER
#define CHARACTER

class Character : public Entity {
public:
	Character();
	void reset_animation();
	void animate();
	float get_move_speed();
	void set_move_speed(float speed);
	Bullet shoot(sf::Texture, sf::Vector2f target_pos, sf::Vector2f origin_pos,Layer layer);
private:
	int current_frame = 0;
	float move_speed = 100;
};
#endif