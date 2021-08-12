#include "Game.h"
#include <iostream>

void Game::load(int& WIDTH, int& HEIGHT)
{
	font.loadFromFile("fonts\\mrsmonster.ttf");
	Algorithm::load();

	// background
	game_background_texture.loadFromFile("img\\game_background.jpg");
	game_background_sprite = sf::Sprite(game_background_texture);

	// main game music
	game_music.openFromFile("audio\\game_music.ogg");
	game_music.setLoop(true);

	// exit icon
	exit_texture.loadFromFile("img\\exit.png");
	exit_sprite = sf::Sprite(exit_texture);
	exit_sprite.setPosition(WIDTH * 0.64, HEIGHT * 0.86);

	// game settings icon
	game_settings.loadFromFile("img\\settings_icon_game.png");
	game_settings_sprite = sf::Sprite(game_settings);
	game_settings_sprite.setPosition(WIDTH * 0.44, HEIGHT * 0.945);
	game_settings_sprite.setScale(0.065, 0.065);

	// game settings window init
	InGameSettings::load(WIDTH, HEIGHT);

	// end game text
	end_game_text.setFont(font);
	end_game_text.setString("END GAME");
	end_game_text.setCharacterSize(40);
	end_game_text.setPosition(WIDTH / 2 - end_game_text.getCharacterSize() * 3, HEIGHT / 2 - end_game_text.getCharacterSize());
	end_game_text.setFillColor(sf::Color::Yellow);
	end_game_text.setOutlineColor(sf::Color::Green);
	dark_effect.setSize(sf::Vector2f(1250, 750));
	dark_effect.setFillColor(sf::Color(1, 1, 1, 155));

	// restart game button //
	outer_restart_game_button.setSize(sf::Vector2f(nsize_restart_game_button_x, nsize_restart_game_button_y));
	outer_restart_game_button.setFillColor(sf::Color(1, 1, 1, 255));
	outer_restart_game_button.setPosition(end_game_text.getPosition().x - 18, end_game_text.getPosition().y + 50);
	outer_restart_game_button.setOrigin(-10, -10);

	inner_restart_game_button.setSize(sf::Vector2f(nsize_restart_game_button_x - 6, nsize_restart_game_button_y - 6));
	inner_restart_game_button.setFillColor(sf::Color(211, 211, 211, 255));
	inner_restart_game_button.setPosition(outer_restart_game_button.getPosition().x + 10, outer_restart_game_button.getPosition().y + 10);

	restart_game_text.setFont(font);
	restart_game_text.setString("RESTART GAME");
	restart_game_text.setCharacterSize(25);
	restart_game_text.setPosition(inner_restart_game_button.getPosition().x + 15, inner_restart_game_button.getPosition().y + 8);
	restart_game_text.setFillColor(sf::Color::Red);
}

Switcher Game::update(sf::RenderWindow* W)
{
	exitIconResponse(W);
	Algorithm::setBoardFeatures(Board::getTexture(), Board::getSprite());

	gameSettingsResponse(W);

	if (!bEndGame)
		Algorithm::update(InGameSettings::getSnakeSpeed(), bEndGame, InGameSettings::getBoardSize());

	if (bShowSettings)
	{
		InGameSettings::update(W, bShowSettings);
	}

	if (bBackToMenu)
		return Switcher::menu;

	return Switcher::game;
}

// music
void Game::musicStop()
{
	game_music.pause();
}
void Game::musicPlay()
{
	if (!game_music.getStatus())
		game_music.play();
}

void Game::draw(sf::RenderWindow* W)
{
	W->draw(game_background_sprite);
	W->draw(exit_sprite);
	W->draw(game_settings_sprite);
	W->draw(Board::getSprite());
	Algorithm::draw(W);

	if (bShowSettings)
	{
		W->draw(dark_effect);
		InGameSettings::draw(W);
	}

	if (bEndGame)
	{
		drawEndGameAlert(W);
	}
}

void Game::exitIconResponse(const sf::RenderWindow* W)
{
	if (exit_sprite.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))))
	{
		exit_sprite.setOrigin(0, 0);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			bBackToMenu = true;
	}
	else
	{
		bBackToMenu = false;
		exit_sprite.setOrigin(-2.0, -2.0);
	}
}
void Game::gameSettingsResponse(const sf::RenderWindow* W)
{
	if (game_settings_sprite.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W)))
		&& (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		bShowSettings = true;
	}

}
void Game::drawEndGameAlert(sf::RenderWindow* WINDOW)
{
	WINDOW->draw(dark_effect);
	WINDOW->draw(end_game_text);
	// restart_game button 
	WINDOW->draw(outer_restart_game_button);
	WINDOW->draw(inner_restart_game_button);
	WINDOW->draw(restart_game_text);

	if (outer_restart_game_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(100);
			Algorithm::restartGame();
			bEndGame = false;
		}

		inner_restart_game_button.setOrigin(2, 2);
		restart_game_text.setOrigin(2, 2);
	}
	else
	{
		inner_restart_game_button.setOrigin(0, 0);
		restart_game_text.setOrigin(0, 0);
	}
}
