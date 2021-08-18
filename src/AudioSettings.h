#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "SetsSwitcher.h"
#include "TextGenResp.h"

class AudioSettings
{
public:
	void draw(sf::RenderWindow* W) const;
	void load(int WIDTH, int HEIGHT);
	Switcher update(sf::RenderWindow* W, sf::Music& background_music);
	bool isMusicMuted() const { return current_sound_icon_sprite.getColor() == sf::Color::Red; }

private:
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

inline void AudioSettings::draw(sf::RenderWindow* W) const
{
	// texts
	W->draw(m_text_volume);
	W->draw(m_text_back);
	W->draw(m_text_volume_number);

	// sprites
	W->draw(volume_up_sprite);
	W->draw(volume_down_sprite);
	W->draw(current_sound_icon_sprite);
	W->draw(horizontal_line_sprite);
}
