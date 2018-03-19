#include "Entity.h"
#include "Layer.h"
#include "Collision.h"

Entity::Entity() :texture(), current_layer() {
}

void Entity::addTexture(std::string path, int count) {
	Collision::CreateTextureAndBitmask(texture, path);
	frames = count;
	setTexture(texture);
}

void Entity::set_layer(Layer& layer) {
	current_layer = &layer;
	layer.add_element(this);
}

Layer* Entity::get_layer() {
	return current_layer;
}

int Entity::get_frames() {
	return frames;
}