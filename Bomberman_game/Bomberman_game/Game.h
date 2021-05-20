#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "menu.h"
#include "gameplay.h"


class Game {
private:
	std::unique_ptr<Menu> menu;
	std::unique_ptr<Gameplay> gameplay;
	int view = 0;
	sf::Event event;

public:
	Game(unsigned int screen_width, unsigned int screen_height);
	void mainLoop(sf::RenderWindow& window);
	void doAction(sf::RenderWindow& window);





};
