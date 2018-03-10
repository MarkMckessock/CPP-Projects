#include "Player.h"
#include <iostream>

void Player::watch_mouse(sf::Vector2f mouse_pos) {
	sf::Vector2f pos = getPosition();
	double pi = 3.1415;
	double angle = atan2(mouse_pos.y - pos.y, mouse_pos.x - pos.x) * (180 / pi);
	setRotation(angle);
}