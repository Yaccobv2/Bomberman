#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "object.h"
#include "player.h"
#include "bound.h"

#include <map>
#include <vector>
#include <string>

static int BOUND_SIZE = 15;
static int BLOCK_SIZE_W = 64;
static int BLOCK_SIZE_H = 48;
static int MAP_BLOCK_SIZE = 55;

class Gameplay {
private:
	//std::map<std::string, std::unique_ptr<Bound>> boundaries;
	std::vector<std::unique_ptr<Bound>> boundaries;
	std::vector<std::unique_ptr<Bound>> mapStaticObjects;
	std::unique_ptr<Player> player;
	//std::vector<Bomb> BombVector;
public:

	Gameplay();

	int displayGame(sf::RenderWindow& window, sf::Event& event);
	void eventLoop(sf::RenderWindow& window, sf::Event& event);
	void setBoundaries();
	void drawObjects(sf::RenderWindow& window);





};


