#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>





class Menu {

private:

	struct Button
	{
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Texture texture_clicked;
		bool clicked = false;
	};
	
	std::map<std::string, std::unique_ptr<Button>> buttons;

	sf::Sprite backgroundImage;
	sf::Texture backgroundTexture;
	int viewVal = 0;


public:
	Menu(unsigned int& width, unsigned int& height);
	Menu();

	void clickOnButton(sf::RenderWindow& window);
	void loadTextures();
	void menuDraw(sf::RenderWindow& window);
	int	 displayMenu(sf::RenderWindow& window, sf::Event& event);
	



};

