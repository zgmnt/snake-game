#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "MenuSettings.h"

void Settings::load(int& WIDTH, int& HEIGHT)
{
	font.loadFromFile("fonts\\mrsmonster.ttf");

	//// text game settings //
	//text_game_settings.setString("GAME SETTINGS");
	//text_game_settings.setFont(font);
	//text_game_settings.setOutlineColor(sf::Color::Green);
	//text_game_settings.setFillColor(sf::Color::Yellow);
	//text_game_settings.setOutlineThickness(2);
	//text_game_settings.setCharacterSize(50);
	//text_game_settings.setPosition(WIDTH / 10, HEIGHT / 10);

	//// text audio settings //
	//text_audio_settings.setString("AUDIO SETTINGS");
	//text_audio_settings.setFont(font);
	//text_audio_settings.setOutlineColor(sf::Color::Green);
	//text_audio_settings.setFillColor(sf::Color::Yellow);
	//text_audio_settings.setOutlineThickness(2);
	//text_audio_settings.setCharacterSize(50);
	//text_audio_settings.setPosition(WIDTH / 10, HEIGHT / 10 + 70);

	// text back  //
	text_back.setString("BACK");
	text_back.setFont(font);
	text_back.setOutlineColor(sf::Color::Green);
	text_back.setFillColor(sf::Color::Yellow);
	text_back.setOutlineThickness(2);
	text_back.setCharacterSize(50);
	text_back.setPosition(WIDTH / 10, HEIGHT / 10 + 350);
}
Switcher  Settings::update(sf::RenderWindow& W)
{
	//// game settings text response //
	//if (text_game_settings.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	//{
	//	text_game_settings.setCharacterSize(70);
	//	text_game_settings.setOrigin(8.0, 8.0);

	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//	{
	//		Sleep(100);
	//		return Switcher::game_settings;
	//	}

	//}
	//else
	//{
	//	text_game_settings.setCharacterSize(50);
	//	text_game_settings.setOrigin(-5.0, -5.0);
	//}

	//// audio settings text response //
	//if (text_audio_settings.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	//{
	//	text_audio_settings.setCharacterSize(70);
	//	text_audio_settings.setOrigin(8.0, 8.0);

	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//		return Switcher::audio_settings;
	//}
	//else
	//{
	//	text_audio_settings.setCharacterSize(50);
	//	text_audio_settings.setOrigin(-5.0, -5.0);
	//}

	// back text response //
	if (text_back.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	{
		text_back.setCharacterSize(70);
		text_back.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return Switcher::menu;
	}
	else
	{
		text_back.setCharacterSize(50);
		text_back.setOrigin(-5.0, -5.0);
	}

	return Switcher::settings;
}
void Settings::draw(sf::RenderWindow& W)
{
	W.draw(text_game_settings);
	W.draw(text_audio_settings);
	W.draw(text_back);
}
