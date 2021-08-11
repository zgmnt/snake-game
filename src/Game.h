#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"

// to do background of game and music

class Game
{
	// main game music
	sf::Music game_music;

	// background
	sf::Texture game_background_texture;
	sf::Sprite game_background_sprite;

public:
	void draw(sf::RenderWindow* W);
	void load(int& WIDTH, int& HEIGHT);
	void update(sf::RenderWindow* W);
	void musicPlay();
	void musicStop();
};