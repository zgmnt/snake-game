#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "TextGenResp.h"

struct ScreenResolution
{
	int width = 0;
	int height = 0;
};

class GameSettings
{
public:
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void draw(sf::RenderWindow* W) const;
private:
	// texts
	sf::Text m_text_back;
	sf::Text m_text_default;
	sf::Text m_text_snake_speed;
	sf::Text m_text_board_sizeX;
	sf::Text m_text_board_sizeY;
	sf::Text m_text_screen_resolution;
	sf::Text m_text_obstacles;
	sf::Text m_text_music;
	sf::Text m_text_control_WSAD;
	// fullscreen icon
	sf::Texture fullscreen_icon_texture;
	sf::Sprite fullscreen_icon_sprite;

	// private functions //
	ScreenResolution getScreenResolution() const;
	void getConfigData();
};

inline void GameSettings::draw(sf::RenderWindow* W) const
{
	W->draw(m_text_back);
	W->draw(m_text_default);
	W->draw(m_text_board_sizeX);
	W->draw(m_text_board_sizeY);
	W->draw(m_text_snake_speed);
	W->draw(m_text_screen_resolution);
	W->draw(m_text_obstacles);
	W->draw(m_text_music);
	W->draw(m_text_control_WSAD);
}
