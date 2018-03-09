#include <SFML\Graphics.hpp>
#include "Layer.h"
#include "Entity.h"
#include <vector>

Layer::Layer() : elements() {}

void Layer::add_element(Entity* item) {
	elements.push_back(item);
}

void Layer::render(sf::RenderWindow window) {
	for (int i = 0; i < elements.size(); i++) {
		window.draw(*elements[i]);
	}
}