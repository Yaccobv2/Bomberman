#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"


Game::Game(unsigned int screen_width, unsigned int screen_height) {
	menu = std::make_unique<Menu>(screen_width, screen_height);
	gameplay = std::make_unique<Gameplay>();
}


void Game::doAction(sf::RenderWindow& window) {
	if (view == 0) { view = menu->displayMenu(window,event); }
	if (view == 1) { view = gameplay->displayGame(window,event); }
	if (view == 3) { window.close(); }
}


void Game::mainLoop(sf::RenderWindow& window) {
	while (window.isOpen())
	{
		window.clear(sf::Color::White);

		doAction(window);

		window.display();
	}
}
