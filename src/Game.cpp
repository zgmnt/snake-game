#include "Game.h"

void Game::load(int& WIDTH, int& HEIGHT)
{		
	// rocks/obstacles
	rock_texture.loadFromFile("img\\rock.png");
	rock_sprite = sf::Sprite(rock_texture);
	rock_sprite.setScale(0.18f, 0.18f);
	rock_sprite.setOrigin(8, 8);

	font.loadFromFile("fonts\\mrsmonster.ttf");
	Logic::load();

	// background
	game_background_texture.loadFromFile("img\\game_background.jpg");
	game_background_sprite = sf::Sprite(game_background_texture);

	// main game music
	game_music.openFromFile("audio\\game_music.ogg");
	game_music.setLoop(true);

	// exit icon
	exit_texture.loadFromFile("img\\exit.png");
	exit_sprite = sf::Sprite(exit_texture);
	exit_sprite.setPosition(WIDTH * 0.67, HEIGHT * 0.91);

	// game settings icon
	game_settings.loadFromFile("img\\settings_icon_game.png");
	game_settings_sprite = sf::Sprite(game_settings);
	game_settings_sprite.setPosition(WIDTH * 0.74, HEIGHT * 0.93);
	game_settings_sprite.setScale(0.065, 0.065);

	// game settings window init
	InGameSettings::load(WIDTH, HEIGHT,Logic::isObstaclesEnabled(),
		Logic::isArrowControlType());

	Generator gen{ "fonts\\mrsmonster.ttf" };
	// end game text
	Generator::setText(end_game_text, 40, sf::Color::Yellow, "END GAME", 
		std::make_pair(625 - end_game_text.getCharacterSize() * 3, 360 - end_game_text.getCharacterSize()));

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

	Generator::setText(end_game_text, 25, sf::Color::Red, "RESTART GAME",
		std::make_pair(inner_restart_game_button.getPosition().x + 15, inner_restart_game_button.getPosition().y + 8));

	// game music
	game_music.openFromFile("audio\\game_music.ogg");
	game_music.setLoop(true);
}
Switcher Game::update(sf::RenderWindow* W)
{
	exitIconResponse(W);
	Logic::setBoardFeatures(Board::getTexture(), Board::getSprite());

	gameSettingsResponse(W);

	if (!bEndGame)
		Logic::update(InGameSettings::getSnakeSpeed(), bEndGame,
			InGameSettings::getBoardSizeX(), InGameSettings::getBoardSizeY());

	if (bShowSettings)
	{
		InGameSettings::update(W, bShowSettings, Logic::isObstaclesEnabled(),
			Logic::isArrowControlType(), game_music, bEndGame);
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
	Draw::draw(sprites, W);
	W->draw(Board::getSprite());

	Logic::drawSnake(W);
	drawCounter(Logic::getCounterSprite(), W);
	drawFood(Logic::getFoodSprite(), W);
	drawScoreboard(Logic::getScoreboard(), W);

	if (Logic::isObstaclesEnabled())
		drawObstacles(Logic::getObstacles(), W);

	if (bShowSettings)
	{
		W->draw(dark_effect);
		InGameSettings::draw(W);
	}

	if (bEndGame)
	{
		game_music.stop();
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
	Draw::draw(rectangles, WINDOW);
	WINDOW->draw(end_game_text);
	WINDOW->draw(restart_game_text);

	if (outer_restart_game_button.getGlobalBounds().contains((*WINDOW).mapPixelToCoords(sf::Mouse::getPosition(*WINDOW))))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(100);
			Logic::restartGame();
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
void Game::drawCounter(std::vector<sf::Text> vec, sf::RenderWindow* W)
{
	for (auto it : vec)
	{
		W->draw(it);
	}
}
void Game::drawFood(std::vector<Food> vec, sf::RenderWindow * W)
{
	for (size_t z = 0; z < Logic::getFoodSize(); z++)
	{
		W->draw(Logic::getFoodSprite(z));
	}
}
void Game::drawScoreboard(std::vector<sf::Text> vec, sf::RenderWindow * W)
{
	for (auto it : vec)
	{
		W->draw(it);
	}
}
void Game::drawObstacles(std::vector<FinalObstaclesCoords> vec, sf::RenderWindow * W)
{
	for (size_t n = 0; n < vec.size(); n++)
	{
		rock_sprite.setPosition(vec[n].x * 16 + 50, vec[n].y * 16 + 50);
		W->draw(rock_sprite);
	}
}
