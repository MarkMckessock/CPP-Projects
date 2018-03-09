#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Game.h"


//Textures should be kept independant of entities to prevent reloading.

//Layers:
//entity.set_layer(5);
//void render(){
//render layer 5,4,3,2,1;
/*class Layer
public:
 void render(){
 for (entity in contents)
	render entity
private:
	std::vector<entity>;
*/

int main() {
	Game game;
	game.run();

}