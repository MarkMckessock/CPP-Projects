#ifndef PLAYER
#define PLAYER
#include "Player.h"
#endif // !PLAYER

#ifndef IO_STREAM
#define IO_STREAM
#include <iostream>
#endif // !IO_STREAM



void Player::watch_mouse(sf::Vector2i mouse_pos) {
	sf::Vector2f pos = sprite.getPosition();
	double pi = 3.1415;
	double angle = atan2(mouse_pos.y - pos.y, mouse_pos.x - pos.x) * (180 / pi);
	sprite.setRotation(angle);
	std::cout << "angle: " << angle << std::endl;
}