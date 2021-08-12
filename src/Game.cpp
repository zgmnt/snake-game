#include "Game.h"

void Game::load(int& WIDTH, int& HEIGHT)
{
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

	// board texture & sprite
	board_texture.loadFromFile("img\\board.jpg");
	board_sprite = sf::Sprite(board_texture);
	board_sprite.setPosition(50, 50);
	board_sprite.setScale(0.5, 0.5);

	// game settings icon
	game_settings.loadFromFile("img\\settings_icon_game.png");
	game_settings_sprite = sf::Sprite(game_settings);
	game_settings_sprite.setPosition(WIDTH * 0.44, HEIGHT * 0.945);
	game_settings_sprite.setScale(0.065, 0.065);

	// game settings window init
	InGameSettings::load(WIDTH, HEIGHT);
}

Switcher Game::update(sf::RenderWindow* W)
{
	gameSettingsResponse(W);

	if (bShowSettings)
		InGameSettings::update(W, bShowSettings);
	else
		Algorithm::update();

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
	W->draw(board_sprite);
	W->draw(exit_sprite);
	W->draw(game_settings_sprite);
	Algorithm::draw(W);

	if (bShowSettings)
		InGameSettings::draw(W);
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
