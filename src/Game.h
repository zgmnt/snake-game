#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "Algorithm.h"

class Game : public Algorithm
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

	bool bBackToMenu{ false };

	// private functions //
	void doorIconResponse(const sf::RenderWindow* W);

public:
	void draw(sf::RenderWindow* W);
	void load(int& WIDTH, int& HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void musicPlay();
	void musicStop();
};