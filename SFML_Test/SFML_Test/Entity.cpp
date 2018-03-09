#include "Entity.h"
#include "Layer.h"

Entity::Entity() :texture(), current_layer() {
	setOrigin(16.f, 16.f);
}

void Entity::addTexture(std::string path, int count) {
	texture.loadFromFile(path);
	frames = count;
	setTexture(texture);
	reset_animation();
}

void Entity::animate() {
	current_frame++;
	//std::cout << current_frame << std::endl;
	if (current_frame > frames - 1)
		current_frame = 0;
	setTextureRect(sf::IntRect(current_frame * 32, 0, 32, 32));
}

void Entity::reset_animation() {
	setTextureRect(sf::IntRect(0, 0, 32, 32));
	current_frame = 0;
}

void Entity::set_layer(Layer layer) {
	current_layer = &layer;
	layer.add_element(this);
}

Layer* Entity::get_layer() {
	return current_layer;
}