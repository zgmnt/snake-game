#include "InGameSettingsWindow.h"
#include <Windows.h>

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
	WINDOW->draw(up_sprite_board_size);
	WINDOW->draw(down_sprite_board_size);
	WINDOW->draw(horizontal_line_sprite_board_size);
	WINDOW->draw(text_board_size);

	// fullscreen button 
	WINDOW->draw(outer_fullscreen_button);
	WINDOW->draw(inner_fullscreen_button);
	WINDOW->draw(text_switch_fullscreen);
}
void InGameSettings::load(int WIDTH, int HEIGHT)
{	
	// font
	font.loadFromFile("fonts\\mrsmonster.ttf");
	text_board_size.setFont(font);
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

	// fullscreen
	outer_fullscreen_button.setSize(sf::Vector2f(nsize_fullscreen_button_x, nsize_fullscreen_button_y));
	outer_fullscreen_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_fullscreen_button.setPosition(innerFrame.getPosition().x / 2 + 100, innerFrame.getPosition().y / 2 + 270);
	outer_fullscreen_button.setOrigin(-10, -10);
	inner_fullscreen_button.setSize(sf::Vector2f(nsize_fullscreen_button_x - 6, nsize_fullscreen_button_y - 6));
	inner_fullscreen_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_fullscreen_button.setPosition(outer_fullscreen_button.getPosition().x + 10, outer_fullscreen_button.getPosition().y + 10);
	text_switch_fullscreen.setFont(font);
	text_switch_fullscreen.setString("FULLSCREEN : OFF");
	text_switch_fullscreen.setCharacterSize(25);
	text_switch_fullscreen.setPosition(inner_fullscreen_button.getPosition().x + 55, inner_fullscreen_button.getPosition().y + 8);
	text_switch_fullscreen.setFillColor(sf::Color::Red);

	// board
	text_board_size_string.setOutlineColor(sf::Color::Red);
	text_board_size_string.setFillColor(sf::Color::White);
	text_board_size_string.setOutlineThickness(2);
	text_board_size_string.setCharacterSize(30);
	text_board_size_string.setPosition(outerFrame.getPosition().x - 200, outerFrame.getPosition().y - 220);
	text_board_size_string.setString("BOARD SIZE");
	text_board_size.setOutlineColor(sf::Color::Red);
	text_board_size.setFillColor(sf::Color::White);
	text_board_size.setOutlineThickness(1);
	text_board_size.setCharacterSize(30);
	text_board_size.setPosition(text_board_size_string.getPosition().x + 370, text_board_size_string.getPosition().y + 10);
	horizontal_line_board.loadFromFile("img\\horizontal_line.png");
	horizontal_line_sprite_board_size = sf::Sprite(horizontal_line_board);
	horizontal_line_sprite_board_size.setPosition(text_board_size.getPosition().x - text_board_size.getCharacterSize() * 5, text_board_size.getPosition().y + 15);
	horizontal_line_sprite_board_size.setScale(0.1, 0.1);
	horizontal_line_sprite_board_size.setColor(sf::Color::White);

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
	up_sprite_board_size = sf::Sprite(up_texture);
	up_sprite_board_size.setPosition(horizontal_line_sprite_board_size.getPosition().x, text_board_size.getPosition().y - 13);
	up_sprite_board_size.setScale(0.23, 0.23);
	down_sprite_board_size = sf::Sprite(down_texture);
	down_sprite_board_size.setPosition(horizontal_line_sprite_board_size.getPosition().x, text_board_size.getPosition().y + 23);
	down_sprite_board_size.setScale(0.23, 0.23);
		// snake
	up_sprite_snake_speed = sf::Sprite(up_texture);
	up_sprite_snake_speed.setPosition(horizontal_line_sprite_board_size.getPosition().x, text_snake_speed.getPosition().y - 13);
	up_sprite_snake_speed.setScale(0.23, 0.23);
	down_sprite_snake_speed = sf::Sprite(down_texture);
	down_sprite_snake_speed.setPosition(horizontal_line_sprite_board_size.getPosition().x, text_snake_speed.getPosition().y + 23);
	down_sprite_snake_speed.setScale(0.23, 0.23);
	
	// positioning
	text_snake_speed.setPosition(text_snake_speed_string.getPosition().x + 270, text_snake_speed_string.getPosition().y + 10);
	text_board_size.setPosition(text_board_size_string.getPosition().x + 270, text_board_size_string.getPosition().y + 10);
	text_board_size_string.setOrigin(0, -12);
	text_snake_speed_string.setOrigin(0, -12);
}
void InGameSettings::update(sf::RenderWindow* WINDOW, bool& bShowSettings)
{
	backToGameButtonUpdate(WINDOW, bShowSettings);
	boardSizeUpdate(WINDOW);
	snakeSpeedUpdate(WINDOW);
	snakeSpeedRefresh();
	boardSizeRefresh();
	switchFullscreen(WINDOW);
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
void InGameSettings::switchFullscreen(sf::RenderWindow* WINDOW)
{
	if (outer_fullscreen_button.getGlobalBounds().contains(WINDOW->mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (isFullScreen)
			{
				WINDOW->create(sf::VideoMode(1250, 750), "Zygmunt Latyszewicz snake-game v1.7", sf::Style::Default);
				isFullScreen = false;
			}
			else
			{
				WINDOW->create(sf::VideoMode(1250, 750), "Zygmunt Latyszewicz snake-game v1.7", sf::Style::Fullscreen);
				isFullScreen = true;
			}
			WINDOW->setFramerateLimit(25);
			Sleep(150);
		}

		inner_fullscreen_button.setOrigin(2, 2);
		text_switch_fullscreen.setOrigin(2, 2);
	}
	else
	{
		inner_fullscreen_button.setOrigin(0, 0);
		text_switch_fullscreen.setOrigin(0, 0);
	}

	if(isFullScreen)
		text_switch_fullscreen.setString("FULLSCREEN : ON");
	else
		text_switch_fullscreen.setString("FULLSCREEN : OFF");
}
void InGameSettings::boardSizeUpdate(const sf::RenderWindow* WINDOW)
{
	if (up_sprite_board_size.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_size.setColor(sf::Color::Green);
		fboard_size += 0.3;
	}
	else if (down_sprite_board_size.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition((*WINDOW)))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite_board_size.setColor(sf::Color::Red);
		fboard_size -= 0.3;
	}
	else
		horizontal_line_sprite_board_size.setColor(sf::Color::White);
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
void InGameSettings::boardSizeRefresh()
{
	// sets the value of board size depending on the change
	if (fboard_size < min_board_size)
		fboard_size = min_board_size;
	if (fboard_size > max_board_size)
		fboard_size = max_board_size;

	if (fboard_size < 10)
		text_board_size.setString(std::to_string(fboard_size).substr(0, 1));
	else
		text_board_size.setString(std::to_string(fboard_size).substr(0, 2));
}
