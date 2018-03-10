#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

#ifndef ENTITY
#define ENTITY

class Layer;
class Entity : public sf::Sprite{
public:
	Entity();
	void addTexture(std::string path, int count);
	void set_layer(Layer& layer);
	int get_frames();
	Layer* get_layer();

private:
	sf::Texture texture;
	Layer *current_layer;
	int frames;
};

#endif