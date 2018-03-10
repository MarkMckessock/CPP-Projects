#include <vector>
#include "Entity.h"

#ifndef LAYER
#define LAYER

class Layer {
public:
	Layer();
	Layer(int _index);
	void add_element(Entity* item);
	void render(sf::RenderWindow& window);
private:
	std::vector<Entity*> elements;
	int index;
};

#endif

