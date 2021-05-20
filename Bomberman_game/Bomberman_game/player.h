#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "object.h"
#include "bound.h"
#include <vector>
#include <map>
#include <iostream>

static int speedLimit = 3;


class Player :public Object {

private:
	sf::Sprite player;
	int w;
	int h;
	sf::Texture texture;
	int texturesSizeX[4] = { 62,81,48,61 };
	int textureSizeY = 69;
	sf::FloatRect nextPos;
	float speedIncValue = 1.5;
	float speedDecValue = 0.25;
	float xVelocity = 0;
	float yVelocity = 0;
	
	



public:
	Player( int _w, int _h, int _x, int _y, int _r, int _g, int _b);
	Player();


	void keyboardHandler(sf::Event& event,  unsigned win_x, unsigned win_y);
	
	void draw(sf::RenderWindow& window);

	void setXY();

	int getRad();

	void loadTexture(std::string name);

	//bool checkCollisionBounds(Bound boundaries);

	bool checkCollisions(std::vector<std::unique_ptr<Bound>>& mapStaticObjects, std::vector<std::unique_ptr<Bound>>& boundaries);

	void movementLoop(std::vector<std::unique_ptr<Bound>>& boundaries, std::vector<std::unique_ptr<Bound>>& mapStaticObjects);





};