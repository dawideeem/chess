#include "Menu.h"



Menu::Menu(float width, float height)
{
	if(!font.loadFromFile("arial.ttf"))
	{
		//error
	}

	

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("Player vs Player");
	menu[0].setPosition(sf::Vector2f(200, 100));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Player vs Computer");
	menu[1].setPosition(sf::Vector2f(190, 200));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(280, 300));


	selectedItemIndex = 0;
}


Menu::~Menu()
{
}


void Menu::draw(sf::RenderWindow &window)
{
	sf::Texture t;
	t.loadFromFile("images/menu.jpg");
	sf::Sprite s(t);
	window.draw(s);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex-1>=0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}