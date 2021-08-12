#include "SetsSwitcher.h"
#include "Algorithm.h"
#include "InGameSettingsWindow.h"

class Game : public Algorithm, InGameSettings
{
	// main game music
	sf::Music game_music;

	// background
	sf::Texture game_background_texture;
	sf::Sprite game_background_sprite;

	// board texture & sprite
	sf::Texture board_texture;
	sf::Sprite board_sprite;

	// exit icon
	sf::Texture exit_texture;
	sf::Sprite exit_sprite;

	// game settings icon
	sf::Texture game_settings;
	sf::Sprite game_settings_sprite;

	bool bBackToMenu{ false };
	bool bShowSettings{ false };

	// private functions //
	void exitIconResponse(const sf::RenderWindow* W);
	void gameSettingsResponse(const sf::RenderWindow* W);

public:
	void draw(sf::RenderWindow* W);
	void load(int& WIDTH, int& HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void musicPlay();
	void musicStop();
};
