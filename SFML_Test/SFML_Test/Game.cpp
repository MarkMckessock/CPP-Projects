#include "Game.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Collision.h"

Game::Game() : //define constructor
	mWindow(sf::VideoMode().getDesktopMode(), "SFML Application", sf::Style::Fullscreen)
{
	mWindow.setVerticalSyncEnabled(true);
	player.addTexture("../Resources/sprPWalkUnarmed2_strip8.png", 8);
	player.setPosition(100.f, 100.f);
	player.setScale(4.f, 4.f);
	player.set_layer(layer_2);
	player.set_move_speed(250);

	legs.addTexture("../Resources/sprLegs_strip16.png", 16);
	legs.setPosition(100.f, 100.f);
	legs.setScale(4.f, 4.f);
	legs.set_layer(layer_1);

	map.addTexture("../Resources/screen.png", 1);
	map.setPosition(-100.f, 0.f);
	map.set_layer(background);
	map.setScale(5.f, 5.f);

	collision_mask.addTexture("../Resources/collision map.png", 1);
	collision_mask.setPosition(-100.f, 0.f);
	collision_mask.setScale(5.f, 5.f);

	camera.setCenter(sf::Vector2f(100.f, 100.f));
	camera.setSize(sf::Vector2f(1366.f, 768.f));
}

void Game::run() {
	sf::Clock clock;//store time
	sf::Clock animation_timer;
	sf::Time time_since_last_update = sf::Time::Zero;
	sf::Time time_since_last_frame = sf::Time::Zero;
	sf::Clock timer;
	while (mWindow.isOpen()) {
		time_since_last_update += clock.restart();
		while (time_since_last_update > time_per_frame) { //only calls update after time_per_frame has passed
			time_since_last_update -= time_per_frame;
			process_events();
			update(time_per_frame);
		}
		time_since_last_frame += animation_timer.restart();
		while (time_since_last_frame > sf::seconds(1.f / 6.f)) {
			time_since_last_frame -= sf::seconds(1.f / 6.f);
			if (m_is_moving_down || m_is_moving_up || m_is_moving_left || m_is_moving_right) {
				player.animate();
				legs.animate();
			}
			else {
				player.reset_animation();
				legs.reset_animation();
			}
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
	sf::Vector2f mouse_pos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow));
	player.watch_mouse(mouse_pos);
	legs.watch_mouse(mouse_pos);
}

void Game::update(sf::Time delta_time) {
	sf::Vector2f start_pos = player.getPosition();
	sf::Vector2f movement(0.f, 0.f);
	if (m_is_moving_down)
		movement.y += 1.f;
	if (m_is_moving_up)
		movement.y -= 1.f;
	if (m_is_moving_left)
		movement.x -= 1.f;
	if (m_is_moving_right)	
		movement.x += 1.f;
	player.move(player.get_move_speed()*movement*delta_time.asSeconds());

		if (Collision::PixelPerfectTest(player, collision_mask))
			player.setPosition(start_pos);
		else {
			legs.move(player.get_move_speed()*movement*delta_time.asSeconds());
			camera.move(player.get_move_speed()*movement*delta_time.asSeconds());
		}
}

void Game::render() {
	mWindow.clear();
	background.render(mWindow);
	layer_1.render(mWindow);
	layer_2.render(mWindow);
	mWindow.setView(camera);
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