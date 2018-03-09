#include <SFML/Graphics.hpp>
#include "Player.h"

#ifndef GAME
#define GAME

class Game {
public:
	Game();//Constructor
	void run();

private:
	void process_events(); //Get user input
	void update(sf::Time delta_time); //Update game state
	void render(); //Render changes to window
	void handle_player_input(sf::Keyboard::Key key, bool is_pressed);

private:
	sf::RenderWindow mWindow;
	Player player;

	bool m_is_moving_up;
	bool m_is_moving_down;
	bool m_is_moving_left;
	bool m_is_moving_right;
	const sf::Time time_per_frame = sf::seconds(1.f / 60.f);
};

#endif