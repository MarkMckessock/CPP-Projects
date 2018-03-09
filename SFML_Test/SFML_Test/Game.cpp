#ifndef GAME
#define GAME
#include "Game.h"
#endif // !GAME
#ifndef SFML_GRAPHICS
#define SFML_GRAPHICS
#include <SFML\Graphics.hpp>
#endif // !SFML_GRAPHICS
#ifndef IO_STREAM
#define IO_STREAM
#include<iostream>
#endif // !IO_STREAM
#ifndef PLAYER
#define PLAYER
#include"Player.h"
#endif // 




Game::Game() : //define constructor
	mWindow(sf::VideoMode(640, 480), "SFML Application")
{
	player.addTexture("../Resources/sprPWalkUnarmed2_strip8.png", 8);
	player.sprite.setPosition(100.f, 100.f);
	player.sprite.setScale(4.f, 4.f);
}

void Game::run() {
	sf::Clock clock;//store time
	sf::Clock animation_timer;
	sf::Time time_since_last_update = sf::Time::Zero;
	sf::Time time_since_last_frame = sf::Time::Zero;
	while (mWindow.isOpen()) {
		process_events();
		time_since_last_update += clock.restart();
		while (time_since_last_update > time_per_frame) { //only calls update after time_per_frame has passed
			time_since_last_update -= time_per_frame;
			process_events();
			update(time_per_frame);
		}
		time_since_last_frame += animation_timer.restart();
		while (time_since_last_frame > sf::seconds(1.f / 6.f)) {
			time_since_last_frame -= sf::seconds(1.f / 6.f);
			if (m_is_moving_down || m_is_moving_up || m_is_moving_left || m_is_moving_right)
				player.animate();
			else
				player.reset_animation();
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
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(mWindow);
	player.watch_mouse(mouse_pos);
	std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;
	std::cout << "Origin " << player.sprite.getOrigin().x << " " << player.sprite.getOrigin().y << std::endl;
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