#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "object.h"

class Bound:public Object{

private:
	sf::Sprite shape;
	int w;
	int h;
	sf::Texture texture;


public:
	Bound(int _x, int _y, int _w, int _h, int _r, int _g, int _b);

	void draw(sf::RenderWindow& window);

	int getW();
	int getH();
	sf::Sprite getShape();
	void loadTexture(std::string name);
	
	

};
