#include <../../dependencies/SFML/Graphics.hpp>
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
	GameSettings()
	{
		texts = { &m_text_back , &m_text_default, &m_text_snake_speed,
		& m_text_board_sizeX ,& m_text_board_sizeY,& m_text_screen_resolution,
		& m_text_obstacles,& m_text_music, &m_text_control_WSAD };
	}
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void draw(sf::RenderWindow* W) const { Draw::draw(texts, W); }
private:
	std::vector<sf::Text*> texts;

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

	// private functions //
	ScreenResolution getScreenResolution() const;
	void getConfigData();
};
