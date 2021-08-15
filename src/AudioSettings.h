#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"

class AudioSettings
{
	sf::Font font;

	// texts //
	sf::Text text_volume_number;
	sf::Text text_volume;
	sf::Text text_back;

	// sound icon //
	sf::Texture sound_icon_on;
	sf::Texture sound_icon_off;
	sf::Sprite current_sound_icon_sprite;
	sf::Sprite sound_icon_on_sprite;
	sf::Sprite sound_icon_off_sprite;

	// sound control textures and sprites //
	sf::Texture horizontal_line;
	sf::Sprite horizontal_line_sprite;
	sf::Texture volume_up;
	sf::Texture volume_down;
	sf::Sprite volume_down_sprite;
	sf::Sprite volume_up_sprite;


	// private functions //
	void soundIconUpdate(sf::RenderWindow& W, sf::Music& background_music);
	void musicVolumeChange(sf::Music& background_music, sf::RenderWindow& W);
	void numberVolumeLevelUpdate(sf::Music& background_music);

public:
	void draw(sf::RenderWindow& W);
	void load(int& WIDTH, int& HEIGHT);
	Switcher update(sf::RenderWindow& W, sf::Music& background_music);
	bool isMusicMuted() { return current_sound_icon_sprite.getColor() == sf::Color::Red; }
};
