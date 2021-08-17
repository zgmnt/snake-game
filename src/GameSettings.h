#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"

struct ScreenResolution
{
	int width = 0;
	int height = 0;
};

class GameSettings
{
	sf::Font font;

	// texts
	sf::Text text_back;
	sf::Text text_default;
	sf::Text text_snake_speed;
	sf::Text text_board_sizeX;
	sf::Text text_board_sizeY;
	sf::Text text_screen_resolution;
	sf::Text text_obstacles;
	sf::Text text_music;
	sf::Text text_control_WSAD;

	// fullscreen icon
	sf::Texture fullscreen_icon_texture;
	sf::Sprite fullscreen_icon_sprite;
	// private functions //
	ScreenResolution getScreenResolution();
	void getConfigData();

public:
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W);
	void draw(sf::RenderWindow* W);
};
