#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "TextGenResp.h"

class Settings
{
public:
	void draw(sf::RenderWindow* W) const;
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
private:
	sf::Text m_text_game_settings;
	sf::Text m_text_audio_settings;
	sf::Text m_text_back;
};

inline void Settings::draw(sf::RenderWindow* W) const
{
	W->draw(m_text_game_settings);
	W->draw(m_text_audio_settings);
	W->draw(m_text_back);
}
