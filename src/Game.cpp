#include "Game.h"

void Game::load(int& WIDTH, int& HEIGHT)
{
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
}

Switcher Game::update(sf::RenderWindow* W)
{
	doorIconResponse(W);

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

// private functions
void Game::draw(sf::RenderWindow* W)
{
	W->draw(game_background_sprite);
	W->draw(exit_sprite);
}

void Game::doorIconResponse(const sf::RenderWindow* W)
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