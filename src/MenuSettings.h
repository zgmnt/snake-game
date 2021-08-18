#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "TextGenResp.h"

class Settings
{
public:
	Settings() { texts = { &m_text_game_settings , &m_text_audio_settings, &m_text_back }; }
	void draw(sf::RenderWindow* W) const { Draw::draw(texts, W); }
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
private:
	std::vector<sf::Text*> texts;
	sf::Text m_text_game_settings;
	sf::Text m_text_audio_settings;
	sf::Text m_text_back;
};
