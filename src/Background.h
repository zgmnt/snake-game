#include <SFML/Graphics.hpp>

class Background
{
	// clocks //
	sf::Clock background_switch_clock;
	sf::Clock background_alpha_clock;

	// background config //
	short choice = 0;
	bool background_change_direction{ false };
	const short max_left_background_offset{ -730 };
	const short background_switch_time{ 30 };

	//background textures & sprites //
	sf::Texture background_1;
	sf::Texture background_2;
	sf::Texture background_3;

	sf::Sprite background_1_sprite;
	sf::Sprite background_2_sprite;
	sf::Sprite background_3_sprite;
	sf::Sprite sprite_current_background;

	// private functions //
	void switchBackground();
	void transition();
	void alpha();

public:
	void update(sf::RenderWindow* W);
	void load();
};