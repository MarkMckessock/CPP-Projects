#include "Character.h"
#include "Entity.h"
#include "Bullet.h"
#include "SFML\Graphics.hpp"

Character::Character(){
	setOrigin(16.f, 16.f);
	setTextureRect(sf::IntRect( 0, 0, 32, 32));
}


void Character::reset_animation() {
	setTextureRect(sf::IntRect(0, 0, 32, 32));
	current_frame = 0;
}

void Character::animate() {
	current_frame++;
	if(current_frame > get_frames() - 1)
		current_frame = 0;
	setTextureRect(sf::IntRect(current_frame * 32, 0, 32, 32));
}

float Character::get_move_speed() {
	return move_speed;
}

void Character::set_move_speed(float speed) {
	move_speed = speed;
}

Bullet Character::shoot(sf::Texture texture, sf::Vector2f target_pos, sf::Vector2f origin_pos) {
	Bullet bullet(texture, target_pos - origin_pos);
	return bullet;
}