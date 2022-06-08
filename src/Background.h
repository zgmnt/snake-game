
#include <../../dependencies/SFML/Graphics.hpp>

class Background
{
public:
	Background(const int time = 30) : background_switch_time(time)
	{
		background_change_direction = false;
	}
	~Background(){}
	void update();
	void load();
	void draw(sf::RenderWindow* W)const { W->draw(sprite_current_background); }
private:	
	// clocks //
	sf::Clock background_switch_clock;
	sf::Clock background_alpha_clock;

	// background config //
	bool background_change_direction;
	const short background_switch_time;

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
};
