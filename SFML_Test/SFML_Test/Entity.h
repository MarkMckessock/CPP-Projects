#include <SFML\Graphics.hpp>
#include <string>

#ifndef ENTITY
#define ENTITY

class Layer;
class Entity : public sf::Sprite{
public:
	Entity();
	void animate();
	void addTexture(std::string path, int count);
	void reset_animation();
	void set_layer(Layer layer);
	Layer* get_layer();

private:
	sf::Texture texture;
	int current_frame = 0;
	Layer *current_layer;
	int frames;
};

#endif