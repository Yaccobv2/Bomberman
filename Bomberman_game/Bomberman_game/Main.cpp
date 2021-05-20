#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <typeinfo>

#include "Game.h"




int main()
{
	sf::RenderWindow window{ sf::VideoMode{800,600}, "Bomberman" };
	window.setFramerateLimit(60);
	Game game(window.getSize().x, window.getSize().y);
	game.mainLoop(window);
	return 0;
}


