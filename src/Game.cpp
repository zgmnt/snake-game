#include "Game.h"

void Game::load(int& WIDTH, int& HEIGHT)
{
	// background
	game_background_texture.loadFromFile("img\\game_background.jpg");
	game_background_sprite = sf::Sprite(game_background_texture);

	// main game music
	game_music.openFromFile("audio\\game_music.ogg");
	game_music.setLoop(true);
}

void Game::update(sf::RenderWindow* W)
{
	//return Sets_switcher::game;
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
}