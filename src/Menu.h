#include <SFML/Graphics.hpp>
#include <utility>
#include "SetsSwitcher.h"

class Menu
{
public:
	void draw(sf::RenderWindow* W) const;
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W) ;
private:
	sf::Text m_text_start;
	sf::Text m_text_settings;
	sf::Text m_text_exit;
};

inline void Menu::draw(sf::RenderWindow* W) const
{
	W->draw(m_text_start);
	W->draw(m_text_settings);
	W->draw(m_text_exit);
}
