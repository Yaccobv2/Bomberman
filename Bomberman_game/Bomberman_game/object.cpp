

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "object.h"

Object::Object(int _x, int _y, int _r, int _g, int _b) {
	x = _x;
	y = _y;
	r = _r;
	g = _g;
	b = _b;
}
Object::Object() {}

int Object::getX() {
	return x;
}

int Object::getY() {
	return y;
}

int Object::getR() {
	return r;
}

int Object::getG() {
	return g;
}

int Object::getB() {
	return b;
}