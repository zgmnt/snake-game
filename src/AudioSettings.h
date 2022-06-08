#include <../../dependencies/SFML/Audio.hpp>
#include <../../dependencies/SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "TextGenResp.h"

class AudioSettings
{
public:
	AudioSettings()
	{ 
		texts = { 
			&m_text_volume_number , & m_text_volume, & m_text_back
		};	
		sprites = {
			&volume_up_sprite , & volume_down_sprite, & current_sound_icon_sprite,
			&horizontal_line_sprite
		};

	}

	void draw(sf::RenderWindow* W) const
	{
		Draw::draw(texts, W);
		Draw::draw(sprites, W);
	}
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W, sf::Music& background_music);
	bool isMusicMuted() const { return current_sound_icon_sprite.getColor() == sf::Color::Red; }

private:
	std::vector<sf::Text*> texts;
	std::vector<sf::Sprite*> sprites;

	// texts //
	sf::Text m_text_volume_number;
	sf::Text m_text_volume;
	sf::Text m_text_back;

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
	void soundIconUpdate(sf::RenderWindow* W, sf::Music& background_music);
	void musicVolumeChange(sf::Music& background_music, sf::RenderWindow* W);
	void numberVolumeLevelUpdate(sf::Music& background_music);
};
