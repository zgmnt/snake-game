#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"

class Menu
{
	sf::Font font;

	sf::Text text_start;
	sf::Text text_settings;
	sf::Text text_exit;
public:
	void draw(sf::RenderWindow& W);
	void load(int&WIDTH, int&HEIGHT);
	Switcher update(sf::RenderWindow& W);
};
