#include "SetsSwitcher.h"
#include "Logic.h"
#include "InGameSettingsWindow.h"

class Game : public Logic, InGameSettings
{
	// obstacles //
	sf::Texture rock_texture;
	sf::Sprite rock_sprite;
	sf::Font font;
	// main game music
	sf::Music game_music;

	// background
	sf::Texture game_background_texture;
	sf::Sprite game_background_sprite;

	// exit icon
	sf::Texture exit_texture;
	sf::Sprite exit_sprite;

	// game settings icon
	sf::Texture game_settings;
	sf::Sprite game_settings_sprite;

	bool bBackToMenu{ false };
	bool bEndGame{ false };
	bool bShowSettings{ false };

	// end game alert
	sf::RectangleShape dark_effect;
	sf::Text end_game_text;

	// restart game button
	sf::RectangleShape inner_restart_game_button;
	sf::RectangleShape outer_restart_game_button;
	sf::Text restart_game_text;
	int nsize_restart_game_button_x{ 190 };
	int nsize_restart_game_button_y{ 50 };

	// private functions //
	void exitIconResponse(const sf::RenderWindow* W);
	void gameSettingsResponse(const sf::RenderWindow* W);
	void drawEndGameAlert(sf::RenderWindow* WINDOW);
	void drawCounter(std::vector<sf::Text> vec, sf::RenderWindow* W);
	void drawFood(std::vector<Food> vec, sf::RenderWindow* W);
	void drawScoreboard(std::vector<sf::Text> vec, sf::RenderWindow* W);
	void drawObstacles(std::vector<FinalObstaclesCoords> vec, sf::RenderWindow* W);

public:
	void draw(sf::RenderWindow* W);
	void load(int& WIDTH, int& HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void musicPlay();
	void musicStop();
};
