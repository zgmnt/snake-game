#include "GameSettings.h"
#include <Windows.h>
#include <fstream>
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


	// text  board size X
	text_board_sizeX.setFont(font);
	text_board_sizeX.setString("BOARD SIZE X ");
	text_board_sizeX.setOutlineColor(sf::Color::Red);
	text_board_sizeX.setFillColor(sf::Color::Yellow);
	text_board_sizeX.setOutlineThickness(2);
	text_board_sizeX.setCharacterSize(35);
	text_board_sizeX.setPosition(WIDTH / 10, 200);
	// text  board size Y
	text_board_sizeY.setFont(font);
	text_board_sizeY.setString("BOARD SIZE Y ");
	text_board_sizeY.setOutlineColor(sf::Color::Red);
	text_board_sizeY.setFillColor(sf::Color::Yellow);
	text_board_sizeY.setOutlineThickness(2);
	text_board_sizeY.setCharacterSize(35);
	text_board_sizeY.setPosition(WIDTH / 10, 250);
	

	// text  snake speed
	text_snake_speed.setFont(font); 
	text_snake_speed.setString("SNAKE SPEED ");
	text_snake_speed.setOutlineColor(sf::Color::Red);
	text_snake_speed.setFillColor(sf::Color::Yellow);
	text_snake_speed.setOutlineThickness(2);
	text_snake_speed.setCharacterSize(35);
	text_snake_speed.setPosition(WIDTH / 10, 300);

	// text screen resolution
	text_screen_resolution.setFont(font);
	text_screen_resolution.setString("YOUR RESOLUTION : " + std::to_string(getScreenResolution().width) + " " + std::to_string(getScreenResolution().height));
	text_screen_resolution.setOutlineColor(sf::Color::Red);
	text_screen_resolution.setFillColor(sf::Color::Yellow);
	text_screen_resolution.setOutlineThickness(2);
	text_screen_resolution.setCharacterSize(50);
	text_screen_resolution.setPosition(WIDTH / 10, 10);

	// text constrol
	text_control_WSAD.setFont(font);
	text_control_WSAD.setString("CONTROL TYPE WSAD ");
	text_control_WSAD.setOutlineColor(sf::Color::Red);
	text_control_WSAD.setFillColor(sf::Color::Yellow);
	text_control_WSAD.setOutlineThickness(2);
	text_control_WSAD.setCharacterSize(35);
	text_control_WSAD.setPosition(WIDTH / 10, 450);

	// text music
	text_music.setFont(font);
	text_music.setString("MUSIC ");
	text_music.setOutlineColor(sf::Color::Red);
	text_music.setFillColor(sf::Color::Yellow);
	text_music.setOutlineThickness(2);
	text_music.setCharacterSize(35);
	text_music.setPosition(WIDTH / 10, 400);

	// text obstacles
	text_obstacles.setFont(font);
	text_obstacles.setString("OBSTACLES " );
	text_obstacles.setOutlineColor(sf::Color::Red);
	text_obstacles.setFillColor(sf::Color::Yellow);
	text_obstacles.setOutlineThickness(2);
	text_obstacles.setCharacterSize(35);
	text_obstacles.setPosition(WIDTH / 10, 350);

	getConfigData();
}

void GameSettings::draw(sf::RenderWindow& W)
{
	W.draw(text_back);
	W.draw(text_default);
	W.draw(text_board_sizeX);
	W.draw(text_board_sizeY);
	W.draw(text_snake_speed);
	W.draw(text_screen_resolution);
	W.draw(text_obstacles);
	W.draw(text_music);
	W.draw(text_control_WSAD);

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

void GameSettings::getConfigData()
{
	std::vector<sf::Text*> texts 
	{
		& text_board_sizeX ,
		& text_board_sizeY, 
		&text_snake_speed,
		&text_obstacles,
		&text_music,
		& text_control_WSAD

	};
	std::fstream file;
	file.open("game_config.txt");
	std::string temp;

	for (auto it : texts)
	{
		file >> temp;
		temp = temp.substr(temp.size() - 1, temp.size());
		if (temp == "N") { temp = "ON"; }
		else if (temp == "F") { temp = "OFF"; }
		it->setString(it->getString() + temp);
	}
}
