#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Entity {
public:
	Entity();
	void animate();
	void addTexture(std::string path,int count);
	sf::Sprite sprite;
private:
	sf::Texture texture;
	int current_frame = 0;
	int frames;
};

Entity::Entity() : sprite(),texture(){}

void Entity::addTexture(std::string path,int count) {
	texture.loadFromFile(path);
	frames = count;
	sprite.setTexture(texture);
}

void Entity::animate() {
	current_frame++;
	//std::cout << current_frame << std::endl;
	if (current_frame > frames-1)
		current_frame = 0;
	sprite.setTextureRect(sf::IntRect(current_frame * 32, 0, 32, 32));
}

class Player :public Entity{
public:
	//Player();
};

class Game {
public:
	Game();//Constructor
	void run();

private:
	void process_events(); //Get user input
	void update(sf::Time delta_time); //Update game state
	void render(); //Render changes to window
	void handle_player_input(sf::Keyboard::Key key,bool is_pressed);

private:
	sf::RenderWindow mWindow;
	Player player;

	bool m_is_moving_up;
	bool m_is_moving_down;
	bool m_is_moving_left;
	bool m_is_moving_right;
	const sf::Time time_per_frame = sf::seconds(1.f / 60.f);
};

Game::Game() : //define constructor
	mWindow(sf::VideoMode(640, 480), "SFML Application")
{	
	player.addTexture("../Resources/sprPWalkUnarmed2_strip8.png", 8);
	player.sprite.setPosition(100.f, 100.f);
	player.sprite.setScale(4.f, 4.f);
}

void Game::run() {
	sf::Clock clock;//store time
	sf::Time time_since_last_update = sf::Time::Zero; 
	while (mWindow.isOpen()) {
		process_events();
		time_since_last_update += clock.restart();
		while (time_since_last_update > time_per_frame) { //only calls update after time_per_frame has passed
			time_since_last_update -= time_per_frame;
			process_events();
			update(time_per_frame);
		}
		render();
	}
}

void Game::process_events() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyPressed:
			handle_player_input(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handle_player_input(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time delta_time) {
	sf::Vector2f movement(0.f, 0.f);
	if (m_is_moving_down)
		movement.y += 100.f;
	if (m_is_moving_up)
		movement.y -= 100.f;
	if (m_is_moving_left)
		movement.x -= 100.f;
	if (m_is_moving_right)
		movement.x += 100.f;
	player.animate();
	player.sprite.move(movement*delta_time.asSeconds());
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(player.sprite);
	mWindow.display();
}

void Game::handle_player_input(sf::Keyboard::Key key, bool is_pressed) {
	if (key == sf::Keyboard::W)
		m_is_moving_up = is_pressed;
	else if (key == sf::Keyboard::A)
		m_is_moving_left = is_pressed;
	else if (key == sf::Keyboard::S)
		m_is_moving_down = is_pressed;
	else if (key == sf::Keyboard::D)
		m_is_moving_right = is_pressed;
}

int main() {
	Game game;
	game.run();

}