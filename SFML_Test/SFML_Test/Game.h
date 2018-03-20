#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Layer.h"
#include "Entity.h"
#include <vector>
#include <string>
#include "Bullet.h"
#include <map>

#ifndef GAME
#define GAME

class Game {
public:
	Game();//Constructor
	void run();

private:
	void process_events(sf::Vector2f mouse_pos); //Get user input
	void update(sf::Time delta_time,sf::Vector2f mouse_pos); //Update game state
	void render(); //Render changes to window
	void handle_player_input(sf::Keyboard::Key key, bool is_pressed);
	void handle_projectiles();

private:
	sf::RenderWindow mWindow;
	Player player;
	Player legs;
	Entity map;
	Entity collision_mask;
	std::map<std::string, Layer> layers;
	std::map<std::string, sf::Texture> textures;

	sf::View camera;

	std::vector<Bullet> bullets;

	bool m_is_moving_up;
	bool m_is_moving_down;
	bool m_is_moving_left;
	bool m_is_moving_right;
	bool m_is_shooting;
	const sf::Time time_per_frame = sf::seconds(1.f / 60.f);
};

#endif