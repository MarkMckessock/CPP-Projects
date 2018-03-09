#include "Entity.h"

Entity::Entity() : sprite(), texture() {
	sprite.setOrigin(16.f, 16.f);
}

void Entity::addTexture(std::string path, int count) {
	texture.loadFromFile(path);
	frames = count;
	sprite.setTexture(texture);
	reset_animation();
}

void Entity::animate() {
	current_frame++;
	//std::cout << current_frame << std::endl;
	if (current_frame > frames - 1)
		current_frame = 0;
	sprite.setTextureRect(sf::IntRect(current_frame * 32, 0, 32, 32));
}

void Entity::reset_animation() {
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	current_frame = 0;
}