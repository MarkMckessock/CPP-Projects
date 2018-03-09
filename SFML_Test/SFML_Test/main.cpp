#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Game.h"


//Textures should be kept independant of entities to prevent reloading.

int main() {
	Game game;
	game.run();

}