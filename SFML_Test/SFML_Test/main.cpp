#include <SFML/Graphics.hpp>

class Game {
public:
	Game();//Constructor
	void run();

private:
	void process_events(); //Get user input
	void update(); //Update game state
	void render(); //Render changes to window

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
};

Game::Game() : //define constructor
	mWindow(sf::VideoMode(640, 480), "SFML Application"),
	mPlayer() 
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run() {
	while (mWindow.isOpen()) {
		process_events();
		update();
		render();
	}
}

void Game::process_events() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) //Closes window when 'x' is clicked
			mWindow.close();
	}
}

void Game::update() {
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

int main() {
	Game game;
	game.run();

}