#include <SFML\Graphics.hpp>
#include "Layer.h"
#include "Entity.h"
#include <vector>
#include <iostream>

Layer::Layer() : elements() {}
Layer::Layer(int _index) : elements(),index(_index) {}

void Layer::add_element(Entity* item) {
	elements.push_back(item);
}

void Layer::render(sf::RenderWindow& window) {
	for (int i = 0; i < elements.size(); i++) {
		window.draw(*elements[i]);
	}
}