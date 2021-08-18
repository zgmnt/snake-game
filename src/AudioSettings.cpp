#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "AudioSettings.h"

void AudioSettings::load(int WIDTH, int HEIGHT)
{
	Generator gen{ "fonts\\mrsmonster.ttf" };
	// exit text
	Generator::setText(m_text_volume, 50, sf::Color::Yellow, "VOLUME", std::make_pair(125, 72));
	// text volume as number
	Generator::setText(m_text_volume_number, 30, sf::Color::White, "", std::make_pair(445, 87));
	// text back
	Generator::setText(m_text_back, 50, sf::Color::Yellow, "BACK", std::make_pair(125, 442));

	// volume up/down sprites
	volume_up.loadFromFile("img\\volume_up.png");
	volume_up_sprite = sf::Sprite(volume_up);
	volume_up_sprite.setPosition(m_text_volume_number.getPosition().x - m_text_volume_number.getCharacterSize() * 2, m_text_volume_number.getPosition().y - 26);
	volume_up_sprite.setScale(0.35, 0.35);
	volume_down.loadFromFile("img\\volume_down.png");
	volume_down_sprite = sf::Sprite(volume_down);
	volume_down_sprite.setPosition(m_text_volume_number.getPosition().x - m_text_volume_number.getCharacterSize() * 2, m_text_volume_number.getPosition().y + 21);
	volume_down_sprite.setScale(0.35, 0.35);

	// sound icon sptire
	current_sound_icon_sprite = sf::Sprite(sound_icon_on_sprite);
	sound_icon_on.loadFromFile("img\\sound.png");
	sound_icon_on_sprite = sf::Sprite(sound_icon_on);
	sound_icon_off.loadFromFile("img\\sound.png");
	sound_icon_off_sprite = sf::Sprite(sound_icon_off);

	// horizontal_line //
	horizontal_line.loadFromFile("img\\horizontal_line.png");
	horizontal_line_sprite = sf::Sprite(horizontal_line);
	horizontal_line_sprite.setPosition(m_text_volume_number.getPosition().x - m_text_volume_number.getCharacterSize() * 2, m_text_volume_number.getPosition().y + 15);
	horizontal_line_sprite.setScale(0.15, 0.1);
	horizontal_line_sprite.setColor(sf::Color::White);
}

Switcher AudioSettings::update(sf::RenderWindow* W, sf::Music& background_music)
{
	soundIconUpdate(W, background_music);
	musicVolumeChange(background_music, W);
	numberVolumeLevelUpdate(background_music);

	if (Response::isChecked(W, m_text_back))
		return Switcher::settings;
	
		return Switcher::audio_settings;
}
void AudioSettings::soundIconUpdate(sf::RenderWindow* W, sf::Music& background_music)
{
	// sound icon depends on music on/off
	if (background_music.getStatus() == 2)
	{
		current_sound_icon_sprite = sf::Sprite(sound_icon_on_sprite);
		current_sound_icon_sprite.setColor(sf::Color::Green);
	}
	else
	{
		current_sound_icon_sprite = sf::Sprite(sound_icon_off_sprite);
		current_sound_icon_sprite.setColor(sf::Color::Red);
	}

	current_sound_icon_sprite.setScale(0.15, 0.15);
	current_sound_icon_sprite.setPosition(m_text_volume_number.getPosition().x + 100, m_text_volume_number.getPosition().y - 20);

	// change sound on/off
	if (Response::isChecked(W, current_sound_icon_sprite))
	{
		if (background_music.getStatus() == 2)
			background_music.pause();
		else
			background_music.play();
	}
}
void AudioSettings::musicVolumeChange(sf::Music& background_music, sf::RenderWindow* W)
{
	if (volume_up_sprite.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite.setColor(sf::Color::Green);
		if (background_music.getVolume() < 100)
			background_music.setVolume(background_music.getVolume() + 1);
	}
	else if (volume_down_sprite.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		horizontal_line_sprite.setColor(sf::Color::Red);
		if (background_music.getVolume() > 1)
			background_music.setVolume(background_music.getVolume() - 1);
	}
	else
		horizontal_line_sprite.setColor(sf::Color::White);
}
void AudioSettings::numberVolumeLevelUpdate(sf::Music& background_music)
{
	if (background_music.getVolume() < 100 && background_music.getVolume() > 10)
		m_text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 2));
	else if (background_music.getVolume() > 99)
		m_text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 3));
	else
		m_text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 1));
}
