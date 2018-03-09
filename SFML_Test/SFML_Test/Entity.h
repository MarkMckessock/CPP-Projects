#include <SFML\Graphics.hpp>
#include <string>
#define ENTITY

class Entity : public sf::Sprite{
public:
	Entity();
	void animate();
	void addTexture(std::string path, int count);
	void reset_animation();
	void set_layer(Layer layer);
	int get_layer();

private:
	sf::Texture texture;
	int current_frame = 0;
	int current_layer;
	int frames;
};