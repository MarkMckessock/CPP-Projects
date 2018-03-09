#include <vector>
#include "Entity.h"

#ifndef LAYER
#define LAYER

class Layer {
public:
	Layer();
	void add_element(Entity* item);
	void render(sf::RenderWindow);
private:
	std::vector<Entity*> elements;
};

#endif

