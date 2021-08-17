#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"

class Settings
{
	sf::Font font;

	sf::Text text_game_settings;
	sf::Text text_audio_settings;
	sf::Text text_back;

public:
	void draw(sf::RenderWindow* W);
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
};
