#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Object{

private:
	int x;
	int y;
	int r;
	int g;
	int b;
	


public:
	Object( int _x, int _y, int _r, int _g, int _b);
	Object();


	
	int getX();
	int getY();
	int getR();
	int getG();
	int getB();
	
	

};
