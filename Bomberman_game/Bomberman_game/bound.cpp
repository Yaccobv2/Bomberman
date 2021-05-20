#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "bound.h"
#include <iostream>

Bound::Bound(int _x, int _y,int _w, int _h, int _r, int _g, int _b) :Object(_x, _y, _r, _g, _b) {
	w = _w;
	h = _h;
	
	shape.setTextureRect(sf::IntRect(getX(), getY(), _w, _h));
	shape.setPosition(sf::Vector2f(getX(), getY()));
	shape.setColor(sf::Color(getR(), getG(), getB()));
	loadTexture("klocki.png");
	shape.setTexture(texture);

}

void Bound::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Bound::loadTexture(std::string name) {
	if (!texture.loadFromFile(name))
	{
		std::cout << "error: cant read texture" << std::endl;
	}

	std::cout << "Texture loaded" << std::endl;

}

int Bound::getW() {
	return w;
}

int Bound::getH() {
	return h;
}

sf::Sprite Bound::getShape() {
	return shape;
}
