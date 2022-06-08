#include <../../dependencies/SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "SetsSwitcher.h"
#include "TextGenResp.h"


class Menu
{
public:
	Menu() { texts={ &m_text_start , &m_text_settings, &m_text_exit }; }
	void draw(sf::RenderWindow* W) const { Draw::draw(texts, W); }
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W) ;
private:
	std::vector<sf::Text*> texts;
	sf::Text m_text_start;
	sf::Text m_text_settings;
	sf::Text m_text_exit;
};
