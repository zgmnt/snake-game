#include <SFML/Graphics.hpp>
#include <Windows.h>
#pragma once

class Generator
{
	static sf::Font font;
public:
	explicit Generator(std::string path) { font.loadFromFile(path); }
	static void setText(sf::Text& text, int size, sf::Color color, std::string&& val, std::pair<int, int>&& pos)
	{
		text.setString(val);
		text.setFont(font);
		text.setOutlineColor(sf::Color::Green);
		text.setFillColor(color);
		text.setOutlineThickness(2);
		text.setCharacterSize(size);
		text.setPosition(pos.first, pos.second);
	}
};

class Response
{
public:
	static bool isChecked(sf::RenderWindow* W, sf::Text& text)
	{
		if (text.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))))
		{
			text.setCharacterSize(70);
			text.setOrigin(8.0, 8.0);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Sleep(150);
				return true;
			}
		}
		else
		{
			text.setCharacterSize(50);
			text.setOrigin(-5.0, -5.0);
		}
		return false;
	}
};

sf::Font Generator::font;
