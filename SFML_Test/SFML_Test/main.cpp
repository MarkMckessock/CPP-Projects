#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Layer.h"
#include "Entity.h"
#include "Player.h"
#include "Game.h"



//Textures should be kept independant of entities to prevent reloading.
//Add camera roate effect
//Add shift ability to move camera

int main() {
	Game game;
	game.run();

}