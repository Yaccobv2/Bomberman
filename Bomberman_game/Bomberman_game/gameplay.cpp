#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "object.h"
#include "player.h"
#include "bound.h"
#include "gameplay.h"




Gameplay::Gameplay() {
	player = std::make_unique<Player>(20, 20, 20, 20, 220, 10, 10);
	setBoundaries();
}



void Gameplay::setBoundaries() {
	//boundaries.insert({ "Up", std::make_unique<Bound>(0, 0, 800, BOUND_SIZE, 128, 128, 128) });
	//boundaries.insert({ "Down", std::make_unique<Bound>(0, 585, 800, BOUND_SIZE, 128, 128, 128) });
	//boundaries.insert({ "Left", std::make_unique<Bound>(0, 15, BOUND_SIZE, 600-2*BOUND_SIZE, 128, 128, 128) });
	//boundaries.insert({ "Right", std::make_unique<Bound>(785, 15, BOUND_SIZE, 600 - 2 * BOUND_SIZE, 128, 128, 128) });

	boundaries.push_back(std::make_unique<Bound>(0, 0, 800, BOUND_SIZE, 128, 128, 128));
	boundaries.push_back(std::make_unique<Bound>(0, 585, 800, BOUND_SIZE, 128, 128, 128));
	boundaries.push_back(std::make_unique<Bound>(0, 15, BOUND_SIZE, 600 - 2 * BOUND_SIZE, 128, 128, 128));
	boundaries.push_back(std::make_unique<Bound>(785, 15, BOUND_SIZE, 600 - 2 * BOUND_SIZE, 128, 128, 128));

	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 5; y++)
		{

			mapStaticObjects.push_back(std::make_unique<Bound>(BOUND_SIZE+(BLOCK_SIZE_W*x)+(MAP_BLOCK_SIZE*(x+1)), BOUND_SIZE+(BLOCK_SIZE_H*y)+ (MAP_BLOCK_SIZE * (y + 1)), 64, 48, 128, 128, 128));

		}

	}
	
	
}




void Gameplay::eventLoop(sf::RenderWindow& window, sf::Event& event) {

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:

			player->keyboardHandler(event ,window.getSize().x, window.getSize().y);

			break;

		default:

			break;

		}


	}


}

void Gameplay::drawObjects(sf::RenderWindow& window) {
	player->draw(window);

	for (auto& val : boundaries) {
		val->draw(window);
	}

	for (auto& val : mapStaticObjects) {
		val->draw(window);
	}


}

int Gameplay::displayGame(sf::RenderWindow& window, sf::Event& event) {
	
	eventLoop(window,event);
	drawObjects(window);
	player->movementLoop(mapStaticObjects, boundaries);
		
	return 1;
	
}


