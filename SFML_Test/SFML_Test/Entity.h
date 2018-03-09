#include <SFML\Graphics.hpp>
#include <string>
#define ENTITY

class Entity {
public:
	Entity();
	void animate();
	void addTexture(std::string path, int count);
	void reset_animation();
	sf::Sprite sprite;
private:
	sf::Texture texture;
	int current_frame = 0;
	int frames;
};