#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"



Player::Player( int _w, int _h, int _x, int _y, int _r, int _g, int _b) :Object(_x, _y, _r, _g, _b){
	w = _w;
	h = _h;


	player.setPosition(getX(), getY());

	loadTexture("data/kulka.png");
	player.setTexture(texture);
	player.scale(sf::Vector2f(0.3f, 0.3f));


	
	

}

Player::Player() {}

void Player::loadTexture(std::string name) {
	if (!texture.loadFromFile(name))
	{
		std::cout << "error: cant read texture" << std::endl;
	}

	std::cout << "Texture loaded" << std::endl;

}


void Player::keyboardHandler(sf::Event& event,  unsigned win_x, unsigned win_y)
{
	

	switch (event.key.code)
	{
	case sf::Keyboard::Left:
		if (xVelocity > -speedLimit)
		{
			xVelocity += -speedIncValue;
			yVelocity = 0;
		}
		break;

	case sf::Keyboard::Right:
		if (xVelocity < speedLimit)
		{
			xVelocity += speedIncValue;
			yVelocity = 0;
		}
		break;

	case sf::Keyboard::Up:
		if (yVelocity > -speedLimit)
		{
			yVelocity += -speedIncValue;
			xVelocity = 0;
		}

		break;

	case sf::Keyboard::Down:
		if (yVelocity < speedLimit)
		{
			yVelocity += speedIncValue;
			xVelocity = 0;
		}
	}

	

	/*movementLoop();*/
	/*switch (event.key.code)
	{
	case sf::Keyboard::Left:

		nextPos.left += -stepValue;
		nextPos.top += 0;

		if (!checkCollisionBounds(*boundaries["Left"]))
		{
			if (!checkCollisionBlocks(mapStaticObjects))
			{
				player.move(-stepValue, 0);
			}
		}
		else
		{
			std::cout << boundaries["Left"]->getX() << " " << boundaries["Left"]->getY() << std::endl;
			player.setPosition(stepValue, player.getPosition().y);
		}
		break;

	case sf::Keyboard::Right:

		nextPos.left += stepValue;
		nextPos.top += 0;

		if (!checkCollisionBounds(*boundaries["Right"]))
		{
			if (!checkCollisionBlocks(mapStaticObjects))
			{
				player.move(stepValue, 0);
			}
		}
		else
		{
			std::cout << boundaries["Right"]->getX() << " " << boundaries["Right"]->getY() << std::endl;
			player.setPosition(win_x-player.getGlobalBounds().width- stepValue, player.getPosition().y );
		}
		
		break;

	case sf::Keyboard::Up:

		nextPos.left += 0;
		nextPos.top += -stepValue;

		if (!checkCollisionBounds(*boundaries["Up"]))
		{
			if (!checkCollisionBlocks(mapStaticObjects))
			{
				player.move(0, -stepValue);
			}
		}
		else
		{
			std::cout << boundaries["Up"]->getX() << " " << boundaries["Up"]->getY() << std::endl;
			player.setPosition(player.getPosition().x, stepValue);
		}
		
		break;

	case sf::Keyboard::Down:

		nextPos.left += 0;
		nextPos.top += stepValue;

		if (!checkCollisionBounds(*boundaries["Down"]))
		{
			if (!checkCollisionBlocks(mapStaticObjects))
			{


				player.move(0, stepValue);


			}


		}
		else
		{
			std::cout << boundaries["Down"]->getX() << " " << boundaries["Down"]->getY() << std::endl;
			player.setPosition(player.getPosition().x, win_y - player.getGlobalBounds().height- stepValue);
		}
		
		break;

	}*/

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
}


void Player::setXY() {
	player.setPosition(getX(), getY());
}




//bool Player::checkCollisionBounds(Bound bound) {
//
//	if (player.getGlobalBounds().intersects(bound.getShape().getGlobalBounds())) { std::cout << "Collison" << std::endl; return true; }
//		else { return false; }
//		
//
//}


bool Player::checkCollisions(std::vector<std::unique_ptr<Bound>>& mapStaticObjects, std::vector<std::unique_ptr<Bound>>& boundaries) {

	for (auto& mapStaticObject : mapStaticObjects)
	{
		nextPos = player.getGlobalBounds();
		nextPos.left += xVelocity;
		nextPos.top += yVelocity;

		if (mapStaticObject->getShape().getGlobalBounds().intersects(nextPos)) {

			std::cout << "Collison" << std::endl;
			return true; 
		}
	}

	for (auto& bound : boundaries)
	{
		nextPos = player.getGlobalBounds();
		nextPos.left += xVelocity;
		nextPos.top += yVelocity;

		if (bound->getShape().getGlobalBounds().intersects(nextPos)) {

			std::cout << "Collison" << std::endl;
			return true;
		}
	}
	return false;



	


}

void Player::movementLoop(std::vector<std::unique_ptr<Bound>>& boundaries, std::vector<std::unique_ptr<Bound>>& mapStaticObjects) {

	if (checkCollisions(mapStaticObjects, boundaries))
	{
		std::cout << "collision" << std::endl;
		xVelocity = 0;
		yVelocity = 0;
	}

	player.setPosition(player.getPosition().x + xVelocity, player.getPosition().y + yVelocity);
	
	if (xVelocity != 0 && xVelocity > 0) {
		xVelocity += -speedDecValue;
	}
	if (xVelocity != 0 && xVelocity < 0) {
		xVelocity += speedDecValue;
	}
	if (yVelocity != 0 && yVelocity > 0) {
		yVelocity += -speedDecValue;
	}
	if (yVelocity != 0 && yVelocity < 0) {
		yVelocity += speedDecValue;
	}

}