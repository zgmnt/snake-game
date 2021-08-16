#include "GameSettings.h"
#include <Windows.h>

void GameSettings::load(int& WIDTH, int& HEIGHT)
{
	font.loadFromFile("fonts\\mrsmonster.ttf");
	
	// text default
	text_default.setFont(font);
	text_default.setString("- DEFAULT -");
	text_default.setOutlineColor(sf::Color::Green);
	text_default.setFillColor(sf::Color::Yellow);
	text_default.setOutlineThickness(2);
	text_default.setCharacterSize(50);
	text_default.setPosition(WIDTH / 10,120);

	// text back
	text_back.setFont(font);
	text_back.setString("BACK");
	text_back.setOutlineColor(sf::Color::Green);
	text_back.setFillColor(sf::Color::Yellow);
	text_back.setOutlineThickness(2);
	text_back.setCharacterSize(50);
	text_back.setPosition(WIDTH / 10, 510);


	// text  board size
	text_board_size.setFont(font);
	text_board_size.setString("BOARD SIZE");
	text_board_size.setOutlineColor(sf::Color::Red);
	text_board_size.setFillColor(sf::Color::Yellow);
	text_board_size.setOutlineThickness(2);
	text_board_size.setCharacterSize(35);
	text_board_size.setPosition(WIDTH / 10, 250);

	// text  snake speed
	text_snake_speed.setFont(font); 
	text_snake_speed.setString("SNAKE SPEED");
	text_snake_speed.setOutlineColor(sf::Color::Red);
	text_snake_speed.setFillColor(sf::Color::Yellow);
	text_snake_speed.setOutlineThickness(2);
	text_snake_speed.setCharacterSize(35);
	text_snake_speed.setPosition(WIDTH / 10, 200);

	// text screen resolution
	text_screen_resolution.setFont(font);
	text_screen_resolution.setString("YOUR RESOLUTION : " + std::to_string(getScreenResolution().width) + " " + std::to_string(getScreenResolution().height));
	text_screen_resolution.setOutlineColor(sf::Color::Red);
	text_screen_resolution.setFillColor(sf::Color::Yellow);
	text_screen_resolution.setOutlineThickness(2);
	text_screen_resolution.setCharacterSize(50);
	text_screen_resolution.setPosition(WIDTH / 10, 10);


}

void GameSettings::draw(sf::RenderWindow& W)
{
	W.draw(text_back);
	W.draw(text_default);
	W.draw(text_board_size);
	W.draw(text_snake_speed);
	W.draw(text_screen_resolution);
}
Switcher GameSettings::update(sf::RenderWindow& W)
{
	// back tekst response //
	if (text_back.getGlobalBounds().contains(W.mapPixelToCoords(sf::Mouse::getPosition(W))))
	{
		text_back.setCharacterSize(70);
		text_back.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			return Switcher::settings;
		}
	}
	else
	{
		text_back.setCharacterSize(50);
		text_back.setOrigin(-5.0, -5.0);
	}
	return Switcher::game_settings;

}

ScreenResolution GameSettings::getScreenResolution()
{
	ScreenResolution screen_resolution;

	RECT handle_screen;
	GetWindowRect(GetDesktopWindow(), &handle_screen);

	screen_resolution.width = handle_screen.right;
	screen_resolution.height = handle_screen.bottom;

	return screen_resolution;
}