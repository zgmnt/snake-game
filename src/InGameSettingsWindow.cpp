#include "InGameSettingsWindow.h"
#include <Windows.h>
#include <iostream>
#include <fstream>

// public
void InGameSettings::draw(sf::RenderWindow* WINDOW)
{
	// main window
	WINDOW->draw(outerFrame);
	WINDOW->draw(innerFrame);

	// back to game
	WINDOW->draw(outer_back_to_game_button);
	WINDOW->draw(inner_back_to_game_button);
	WINDOW->draw(back_to_game_text);

	// snake
	WINDOW->draw(up_sprite_snake_speed);
	WINDOW->draw(down_sprite_snake_speed);
	WINDOW->draw(text_snake_speed_string);
	WINDOW->draw(horizontal_line_sprite_snake_speed);
	WINDOW->draw(text_snake_speed);

	// board
	WINDOW->draw(text_board_size_string);
	WINDOW->draw(up_sprite_board_sizeX);
	WINDOW->draw(up_sprite_board_sizeY);
	WINDOW->draw(down_sprite_board_sizeX);
	WINDOW->draw(down_sprite_board_sizeY);
	WINDOW->draw(horizontal_line_sprite_board_sizeX);
	WINDOW->draw(horizontal_line_sprite_board_sizeY);

	// obstacles button
	WINDOW->draw(outer_obstacles_button);
	WINDOW->draw(inner_obstacles_button);
	WINDOW->draw(obstacles_text);

	// control type button
	WINDOW->draw(outer_control_type_button);
	WINDOW->draw(inner_control_type_button);
	WINDOW->draw(control_type_text);

	// music button 
	WINDOW->draw(outer_music_button);
	WINDOW->draw(inner_music_button);
	WINDOW->draw(music_text);

}
void InGameSettings::load(int WIDTH, int HEIGHT,bool& isObstaclesEnabled, bool& isArrowControlType)
{
	getConfigData(isObstaclesEnabled, isArrowControlType);
	// font
	font.loadFromFile("fonts\\mrsmonster.ttf");
	text_snake_speed.setFont(font);
	text_board_size_string.setFont(font);
	text_snake_speed_string.setFont(font);

	// main window
	outerFrame.setSize(sf::Vector2f(outer_frame_size, outer_frame_size));
	outerFrame.setFillColor(sf::Color(0, 255, 255, 255));
	outerFrame.setPosition(WIDTH * 0.5, HEIGHT * 0.5);
	outerFrame.setOrigin(outer_frame_size / 2, outer_frame_size / 2);
	innerFrame.setSize(sf::Vector2f(inner_frame_size, inner_frame_size));
	innerFrame.setFillColor(sf::Color(153, 204, 255, 255));
	innerFrame.setPosition(WIDTH * 0.5, HEIGHT * 0.5);
	innerFrame.setOrigin(inner_frame_size / 2, inner_frame_size / 2);

	// back to game
	outer_back_to_game_button.setSize(sf::Vector2f(nsize_back_to_game_button_x, nsize_back_to_game_button_y));
	outer_back_to_game_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_back_to_game_button.setPosition(innerFrame.getPosition().x - inner_frame_size / 4 - 10, innerFrame.getPosition().y + inner_frame_size / 3 - 10);
	outer_back_to_game_button.setOrigin(-10, -10);
	inner_back_to_game_button.setSize(sf::Vector2f(nsize_back_to_game_button_x - 6, nsize_back_to_game_button_y - 6));
	inner_back_to_game_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_back_to_game_button.setPosition(outer_back_to_game_button.getPosition().x + 10, outer_back_to_game_button.getPosition().y + 10);
	back_to_game_text.setFont(font);
	back_to_game_text.setString("BACK TO GAME");
	back_to_game_text.setCharacterSize(30);
	back_to_game_text.setPosition(inner_back_to_game_button.getPosition().x + back_to_game_text.getCharacterSize() / 2, inner_back_to_game_button.getPosition().y + 8);
	back_to_game_text.setFillColor(sf::Color::Blue);

	// board
	text_board_size_string.setOutlineColor(sf::Color::Red);
	text_board_size_string.setFillColor(sf::Color::White);
	text_board_size_string.setOutlineThickness(2);
	text_board_size_string.setCharacterSize(30);
	text_board_size_string.setPosition(outerFrame.getPosition().x - 200, outerFrame.getPosition().y - 220);
	text_board_size_string.setString("BOARD SIZE");
	horizontal_line_board.loadFromFile("img\\horizontal_line.png");
	horizontal_line_sprite_board_sizeX = sf::Sprite(horizontal_line_board);
	horizontal_line_sprite_board_sizeX.setPosition(text_board_size_string.getPosition().x + 200,
		text_board_size_string.getPosition().y + 12);
	horizontal_line_sprite_board_sizeX.setScale(0.1, 0.1);
	horizontal_line_sprite_board_sizeX.setColor(sf::Color::White);
	horizontal_line_sprite_board_sizeY = sf::Sprite(horizontal_line_board);
	horizontal_line_sprite_board_sizeY.setPosition(text_board_size_string.getPosition().x + 250, 
		text_board_size_string.getPosition().y + 12);
	horizontal_line_sprite_board_sizeY.setScale(0.1, 0.1);
	horizontal_line_sprite_board_sizeY.setColor(sf::Color::White);

	// snake
	text_snake_speed_string.setOutlineColor(sf::Color::Red);
	text_snake_speed_string.setFillColor(sf::Color::White);
	text_snake_speed_string.setOutlineThickness(2);
	text_snake_speed_string.setCharacterSize(30);
	text_snake_speed_string.setPosition(outerFrame.getPosition().x - 200, outerFrame.getPosition().y - 150);
	text_snake_speed_string.setString("SNAKE SPEED");
	text_snake_speed.setOutlineColor(sf::Color::Red);
	text_snake_speed.setFillColor(sf::Color::White);
	text_snake_speed.setOutlineThickness(1);
	text_snake_speed.setCharacterSize(30);
	text_snake_speed.setPosition(text_snake_speed_string.getPosition().x + 370, text_snake_speed_string.getPosition().y + 10);
	horizontal_line_snake.loadFromFile("img\\horizontal_line.png");
	horizontal_line_sprite_snake_speed = sf::Sprite(horizontal_line_snake);
	horizontal_line_sprite_snake_speed.setPosition(text_snake_speed.getPosition().x - text_snake_speed.getCharacterSize() * 5, text_snake_speed.getPosition().y + 15);
	horizontal_line_sprite_snake_speed.setScale(0.1, 0.1);
	horizontal_line_sprite_snake_speed.setColor(sf::Color::White);

	// volumes up/down
	up_texture.loadFromFile("img\\volume_up.png");
	down_texture.loadFromFile("img\\volume_down.png");
		// board
	up_sprite_board_sizeX = sf::Sprite(up_texture);
	up_sprite_board_sizeY = sf::Sprite(up_texture);
	up_sprite_board_sizeX.setPosition(horizontal_line_sprite_board_sizeX.getPosition().x, horizontal_line_sprite_board_sizeX.getPosition().y - 28);
	up_sprite_board_sizeY.setPosition(horizontal_line_sprite_board_sizeY.getPosition().x, horizontal_line_sprite_board_sizeY.getPosition().y - 28);
	up_sprite_board_sizeX.setScale(0.23, 0.23);
	up_sprite_board_sizeY.setScale(0.23, 0.23);
	down_sprite_board_sizeX = sf::Sprite(down_texture);
	down_sprite_board_sizeY = sf::Sprite(down_texture);
	down_sprite_board_sizeX.setPosition(horizontal_line_sprite_board_sizeX.getPosition().x, horizontal_line_sprite_board_sizeX.getPosition().y + 7);
	down_sprite_board_sizeY.setPosition(horizontal_line_sprite_board_sizeY.getPosition().x, horizontal_line_sprite_board_sizeY.getPosition().y + 7);
	down_sprite_board_sizeX.setScale(0.23, 0.23);
	down_sprite_board_sizeY.setScale(0.23, 0.23);
		// snake
	up_sprite_snake_speed = sf::Sprite(up_texture);
	up_sprite_snake_speed.setPosition(horizontal_line_sprite_snake_speed.getPosition().x, text_snake_speed.getPosition().y - 13);
	up_sprite_snake_speed.setScale(0.23, 0.23);
	down_sprite_snake_speed = sf::Sprite(down_texture);
	down_sprite_snake_speed.setPosition(horizontal_line_sprite_snake_speed.getPosition().x, text_snake_speed.getPosition().y + 23);
	down_sprite_snake_speed.setScale(0.23, 0.23);
	
	// positioning
	text_snake_speed.setPosition(text_snake_speed_string.getPosition().x + 270, text_snake_speed_string.getPosition().y + 10);
	text_snake_speed_string.setOrigin(0, -12);

	// obstacles button //
	outer_obstacles_button.setSize(sf::Vector2f(nsize_obstacles_button_x, nsize_obstacles_button_y));
	outer_obstacles_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_obstacles_button.setPosition(innerFrame.getPosition().x / 2 + 100, innerFrame.getPosition().y / 2 + 150);
	outer_obstacles_button.setOrigin(-10, -10);
	inner_obstacles_button.setSize(sf::Vector2f(nsize_obstacles_button_x - 6, nsize_obstacles_button_y - 6));
	inner_obstacles_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_obstacles_button.setPosition(outer_obstacles_button.getPosition().x + 10, outer_obstacles_button.getPosition().y + 10);
	obstacles_text.setFont(font);
	obstacles_text.setString("OBSTACLES : ON");
	obstacles_text.setCharacterSize(25);
	obstacles_text.setPosition(inner_obstacles_button.getPosition().x + 40, inner_obstacles_button.getPosition().y + 8);
	obstacles_text.setFillColor(sf::Color::Red);

	// control type button //
	outer_control_type_button.setSize(sf::Vector2f(nsize_back_control_type_button_x, nsize_back_control_type_button_y));
	outer_control_type_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_control_type_button.setPosition(innerFrame.getPosition().x / 2 + 100, innerFrame.getPosition().y / 2 + 90);
	outer_control_type_button.setOrigin(-10, -10);

	inner_control_type_button.setSize(sf::Vector2f(nsize_back_control_type_button_x - 6, nsize_back_control_type_button_y - 6));
	inner_control_type_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_control_type_button.setPosition(outer_control_type_button.getPosition().x + 10, outer_control_type_button.getPosition().y + 10);

	control_type_text.setFont(font);
	control_type_text.setString("CONTROL TYPE : ARROWS");
	control_type_text.setCharacterSize(25);
	control_type_text.setPosition(inner_control_type_button.getPosition().x + 15, inner_control_type_button.getPosition().y + 8);
	control_type_text.setFillColor(sf::Color::Red);

	// music button //
	outer_music_button.setSize(sf::Vector2f(nsize_music_button_x, nsize_music_button_y));
	outer_music_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_music_button.setPosition(innerFrame.getPosition().x / 2 + 100, innerFrame.getPosition().y / 2 + 210);
	outer_music_button.setOrigin(-10, -10);

	inner_music_button.setSize(sf::Vector2f(nsize_music_button_x - 6, nsize_music_button_y - 6));
	inner_music_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_music_button.setPosition(outer_music_button.getPosition().x + 10, outer_music_button.getPosition().y + 10);

	music_text.setFont(font);
	music_text.setString("MUSIC : ON");
	music_text.setCharacterSize(25);
	music_text.setPosition(inner_music_button.getPosition().x + 55, inner_music_button.getPosition().y + 8);
	music_text.setFillColor(sf::Color::Red);
}
void InGameSettings::update(sf::RenderWindow* WINDOW, bool& bShowSettings, bool& isObstaclesEnabled,
bool& isArrowControlType, sf::Music& isMusicPlaying, bool& bEndGame)
{
	backToGameButtonUpdate(WINDOW, bShowSettings);
	snakeSpeedUpdate(WINDOW);
	snakeSpeedRefresh();
	obstacleEnableUpdate(WINDOW, isObstaclesEnabled);
	// BOARD
	boardSizeRefreshX();
	boardSizeRefreshY();
	boardSizeUpdateX(WINDOW);
	boardSizeUpdateY(WINDOW);
	controlTypeUpdate(WINDOW, isArrowControlType);
	musicEnableUpdate(WINDOW, isMusicPlaying);
}

// private
void InGameSettings::backToGameButtonUpdate(const sf::RenderWindow* WINDOW, bool &bShowSettings)
{
	if (outer_back_to_game_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			bShowSettings = false;

		inner_back_to_game_button.setOrigin(2, 2);
		back_to_game_text.setOrigin(2, 2);
	}
	else
	{
		inner_back_to_game_button.setOrigin(0, 0);
		back_to_game_text.setOrigin(0, 0);
	}
}
void InGameSettings::snakeSpeedUpdate(const sf::RenderWindow* WINDOW)
{
	if (up_sprite_snake_speed.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Sleep(100);
		horizontal_line_sprite_snake_speed.setColor(sf::Color::Green);
		fsnake_speed++;
	}
	else if (down_sprite_snake_speed.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Sleep(100);
		horizontal_line_sprite_snake_speed.setColor(sf::Color::Red);
		fsnake_speed--;
	}
	else
		horizontal_line_sprite_snake_speed.setColor(sf::Color::White);
}
void InGameSettings::snakeSpeedRefresh()
{
	// sets the value of snake speed depending on the change
	if (fsnake_speed < min_snake_speed)
		fsnake_speed = min_snake_speed;
	if (fsnake_speed > max_snake_speed)
		fsnake_speed = max_snake_speed;
	
	text_snake_speed.setString(std::to_string(fsnake_speed).substr(0, 1));
}
void InGameSettings::obstacleEnableUpdate(const sf::RenderWindow* WINDOW, bool& isObstaclesEnabled)
{
	if (isObstaclesEnabled)
		obstacles_text.setString("OBSTACLES : ON");
	else
		obstacles_text.setString("OBSTACLES : OFF");

	if (outer_obstacles_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			if (!isObstaclesEnabled)
				isObstaclesEnabled = true;
			else
				isObstaclesEnabled = false;
		}
		inner_obstacles_button.setOrigin(2, 2);
		obstacles_text.setOrigin(2, 2);
	}
	else
	{
		inner_obstacles_button.setOrigin(0, 0);
		obstacles_text.setOrigin(0, 0);
	}
}

void InGameSettings::boardSizeUpdateX(const sf::RenderWindow* WINDOW)
{
	if (up_sprite_board_sizeX.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_sizeX.setColor(sf::Color::Green);
		fboard_sizeX += 0.3;
	}
	else if (down_sprite_board_sizeX.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_sizeX.setColor(sf::Color::Red);
		fboard_sizeX -= 0.3;
	}
	else
		horizontal_line_sprite_board_sizeX.setColor(sf::Color::White);
}
void InGameSettings::boardSizeRefreshX()
{
	// sets the value of board size depending on the change
	if (fboard_sizeX < min_board_size)
		fboard_sizeX = min_board_size;
	if (fboard_sizeX > max_board_size)
		fboard_sizeX = max_board_size;

}
void InGameSettings::boardSizeUpdateY(const sf::RenderWindow* WINDOW)
{
	if (up_sprite_board_sizeY.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_sizeY.setColor(sf::Color::Green);
		fboard_sizeY += 0.3;
	}
	else if (down_sprite_board_sizeY.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_sizeY.setColor(sf::Color::Red);
		fboard_sizeY -= 0.3;
	}
	else
		horizontal_line_sprite_board_sizeY.setColor(sf::Color::White);
}
void InGameSettings::boardSizeRefreshY()
{
	// sets the value of board size depending on the change
	if (fboard_sizeY < min_board_size)
		fboard_sizeY = min_board_size;
	if (fboard_sizeY > max_board_size)
		fboard_sizeY = max_board_size;
}
void InGameSettings::controlTypeUpdate(const sf::RenderWindow* WINDOW, bool& isArrowControlType)
{
	if (isArrowControlType)
	{
		control_type_text.setString("CONTROL TYPE : ARROWS");
	}
	else
	{
		control_type_text.setString("CONTROL TYPE : WSAD");
	}

	if (outer_control_type_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(100);
			if (!isArrowControlType)
			{
				isArrowControlType = true;
			}
			else
			{
				isArrowControlType = false;
			}
		}

		inner_control_type_button.setOrigin(2, 2);
		control_type_text.setOrigin(2, 2);

	}
	else
	{

		inner_control_type_button.setOrigin(0, 0);
		control_type_text.setOrigin(0, 0);
	}
}
void InGameSettings::musicEnableUpdate(const sf::RenderWindow* WINDOW, sf::Music& isMusicPlaying)
{
	if (isMusicPlaying.getStatus() == 2)
	{
		music_text.setString("MUSIC : ON");
	}
	else
	{
		music_text.setString("MUSIC : OFF");
	}

	if (outer_music_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(100);
			if (!(isMusicPlaying.getStatus() == 2))
				isMusicPlaying.play();
			else
				isMusicPlaying.pause();
		}

		inner_music_button.setOrigin(2, 2);
		music_text.setOrigin(2, 2);

	}
	else
	{
		inner_music_button.setOrigin(0, 0);
		music_text.setOrigin(0, 0);
	}
}
void InGameSettings::getConfigData(bool& isObstaclesEnabled, bool& isArrowControlType)
{
	std::vector<float*> values
	{
		&fboard_sizeX,
		& fboard_sizeY,
		& fsnake_speed,
	};

	std::vector<bool*> config
	{
		&isObstaclesEnabled,
		&isArrowControlType,
	};

	std::fstream file;
	file.open("game_config.txt");
	std::string temp;

	for (auto it : values)
	{
		file >> temp;
		temp = temp.substr(temp.size() - 1, temp.size());
		*it = std::stoi(temp);
	}
	for (auto it : config)
	{
		file >> temp;

		temp = temp.substr(temp.size() - 1, temp.size());
		if (temp == "N") { *it = true; }
		else if (temp == "F") { *it = false; }
	}
	file.close();
}