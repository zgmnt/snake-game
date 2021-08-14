#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <Windows.h>


void Menu::load(int& WIDTH , int& HEIGHT)
{
	font.loadFromFile("fonts\\mrsmonster.ttf");

	// exit text //
	text_exit.setString("EXIT");
	text_exit.setFont(font);
	text_exit.setOutlineColor(sf::Color::Green);
	text_exit.setFillColor(sf::Color::Yellow);
	text_exit.setOutlineThickness(2);
	text_exit.setCharacterSize(50);
	text_exit.setPosition(WIDTH / 10, HEIGHT / 10 + 250);

	// start text //
	text_start.setString("START");
	text_start.setFont(font);
	text_start.setOutlineColor(sf::Color::Green);
	text_start.setFillColor(sf::Color::Yellow);
	text_start.setOutlineThickness(2);
	text_start.setCharacterSize(50);
	text_start.setPosition(WIDTH / 10, HEIGHT / 10);

	// settings text //
	text_settings.setString("SETTINGS");
	text_settings.setFont(font);
	text_settings.setOutlineColor(sf::Color::Green);
	text_settings.setFillColor(sf::Color::Yellow);
	text_settings.setOutlineThickness(2);
	text_settings.setCharacterSize(50);
	text_settings.setPosition(WIDTH / 10, HEIGHT / 10 + 70);
}

Switcher Menu::update(sf::RenderWindow& W)
{
	// start game response //
	if (text_start.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	{
		text_start.setCharacterSize(70);
		text_start.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			return Switcher::game;
		}
	}
	else
	{
		text_start.setCharacterSize(50);
		text_start.setOrigin(-5.0, -5.0);
	}

	// settings response  //
	if (text_settings.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	{
		text_settings.setCharacterSize(70);
		text_settings.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			return Switcher::settings;
		}
	}
	else
	{
		text_settings.setCharacterSize(50);
		text_settings.setOrigin(-5.0, -5.0);
	}

	// exit game response  //
	if (text_exit.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	{
		text_exit.setCharacterSize(70);
		text_exit.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			W.close();
	}
	else
	{
		text_exit.setCharacterSize(50);
		text_exit.setOrigin(-5.0, -5.0);
	}
	return Switcher::menu;
}
void Menu::draw(sf::RenderWindow& W)
{
	W.draw(text_start);
	W.draw(text_settings);
	W.draw(text_exit);
}
