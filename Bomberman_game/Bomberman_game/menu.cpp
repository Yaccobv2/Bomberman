#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "menu.h"



Menu::Menu(unsigned int& width, unsigned int& height) {

	loadTextures();
	
	buttons["start"]->sprite.setTexture(buttons["start"]->texture);
	buttons["exit"]->sprite.setTexture(buttons["exit"]->texture);
	backgroundImage.setTexture(backgroundTexture);
	backgroundImage.setScale(sf::Vector2f(1.3f, 0.6f));

	buttons["start"]->sprite.setPosition(sf::Vector2f((width/2)-(buttons["start"]->sprite.getTexture()->getSize().x)/2,height/(buttons.size()+1)*1));
	buttons["exit"]->sprite.setPosition(sf::Vector2f((width / 2)- (buttons["exit"]->sprite.getTexture()->getSize().x) / 2, height / (buttons.size() + 1) * 2));


}

Menu::Menu() {}

void Menu::loadTextures() {


	buttons.insert({ "start", std::make_unique<Button>()});
	buttons.insert({ "exit", std::make_unique<Button>() });

	if (!buttons["start"]->texture.loadFromFile("data/start.png"))
	{
		std::cout << "error: cant read texture start.png" << std::endl;
	}

	if (!buttons["start"]->texture_clicked.loadFromFile("data/start_c.png"))
	{
		std::cout << "error: cant read texture start_c.png" << std::endl;
	}

	
	if (!buttons["exit"]->texture.loadFromFile("data/exit.png"))
	{
		std::cout << "error: cant read texture exit.png" << std::endl;
	}

	
	if (!buttons["exit"]->texture_clicked.loadFromFile("data/exit_c.png"))
	{
		std::cout << "error: cant read texture exit_c.png" << std::endl;
	}

	if (!backgroundTexture.loadFromFile("data/rafi.png"))
	{
		std::cout << "error: cant read texture background.png" << std::endl;
	}

	std::cout << "Textue loading finished" << std::endl;
	
	
}


void Menu::clickOnButton(sf::RenderWindow& window) {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

		if (buttons["start"]->sprite.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
		{
			buttons["start"]->sprite.setTexture(buttons["start"]->texture_clicked);
			buttons["start"]->clicked = true;
		}

		if (buttons["exit"]->sprite.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
		{
			buttons["exit"]->sprite.setTexture(buttons["exit"]->texture_clicked);
			buttons["exit"]->clicked = true;
		}

	}
	else
	{
		buttons["start"]->sprite.setTexture(buttons["start"]->texture);
		buttons["exit"]->sprite.setTexture(buttons["exit"]->texture);

		if (buttons["start"]->clicked == true)
		{
			viewVal = 1;
			buttons["exit"]->clicked = false;
		}

		if (buttons["exit"]->clicked == true)
		{
			window.close();
			buttons["exit"]->clicked = false;
		}

	}
	




}

void Menu::menuDraw(sf::RenderWindow& window) {

	window.draw(backgroundImage);

	for (const auto& val : buttons) {
		window.draw(val.second.get()->sprite);
	}
	
}


int Menu::displayMenu(sf::RenderWindow& window, sf::Event& event) {

	//if statements
	//mouseActivityCheck(); //checkCollisionsWithMouse();
	window.clear(sf::Color(184, 184, 184));

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;



		default:

			break;

		}


	}

	

	clickOnButton(window);
	menuDraw(window);
	return viewVal;



}





