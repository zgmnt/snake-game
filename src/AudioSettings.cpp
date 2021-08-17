#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "AudioSettings.h"

void AudioSettings::load(int WIDTH, int HEIGHT)
{
	font.loadFromFile("fonts\\mrsmonster.ttf");

	// text volume
	text_volume.setFont(font);
	text_volume.setString("VOLUME");
	text_volume.setOutlineColor(sf::Color::Green);
	text_volume.setFillColor(sf::Color::Yellow);
	text_volume.setOutlineThickness(2);
	text_volume.setCharacterSize(50);
	text_volume.setPosition(WIDTH / 10, HEIGHT / 10);

	// text back
	text_back.setFont(font);
	text_back.setString("BACK");
	text_back.setOutlineColor(sf::Color::Green);
	text_back.setFillColor(sf::Color::Yellow);
	text_back.setOutlineThickness(2);
	text_back.setCharacterSize(50);
	text_back.setPosition(WIDTH / 10, HEIGHT / 10 + 350);

	// text volume as number
	text_volume_number.setFont(font);
	text_volume_number.setOutlineColor(sf::Color::Red);
	text_volume_number.setFillColor(sf::Color::White);
	text_volume_number.setOutlineThickness(1);
	text_volume_number.setCharacterSize(30);
	text_volume_number.setPosition(text_volume.getPosition().x + 320, text_volume.getPosition().y + 15);

	// volume up/down sprites
	volume_up.loadFromFile("img\\volume_up.png");
	volume_up_sprite = sf::Sprite(volume_up);
	volume_up_sprite.setPosition(text_volume_number.getPosition().x - text_volume_number.getCharacterSize() * 2, text_volume_number.getPosition().y - 26);
	volume_up_sprite.setScale(0.35, 0.35);
	volume_down.loadFromFile("img\\volume_down.png");
	volume_down_sprite = sf::Sprite(volume_down);
	volume_down_sprite.setPosition(text_volume_number.getPosition().x - text_volume_number.getCharacterSize() * 2, text_volume_number.getPosition().y + 21);
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
	horizontal_line_sprite.setPosition(text_volume_number.getPosition().x - text_volume_number.getCharacterSize() * 2, text_volume_number.getPosition().y + 15);
	horizontal_line_sprite.setScale(0.15, 0.1);
	horizontal_line_sprite.setColor(sf::Color::White);
}

Switcher AudioSettings::update(sf::RenderWindow* W, sf::Music& background_music)
{
	soundIconUpdate(W, background_music);
	musicVolumeChange(background_music, W);
	numberVolumeLevelUpdate(background_music);

	// back tekst response //
	if (text_back.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))))
	{
		text_back.setCharacterSize(70);
		text_back.setOrigin(8.0, 8.0);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Sleep(150);
			return Switcher::settings;
		}
	}
	else
	{
		text_back.setCharacterSize(50);
		text_back.setOrigin(-5.0, -5.0);
	}

	return Switcher::audio_settings;
}
void AudioSettings::draw(sf::RenderWindow* W)
{
	// texts
	W->draw(text_volume);
	W->draw(text_back);
	W->draw(text_volume_number);

	// sprites
	W->draw(volume_up_sprite);
	W->draw(volume_down_sprite);
	W->draw(current_sound_icon_sprite);
	W->draw(horizontal_line_sprite);
}
void AudioSettings::soundIconUpdate(sf::RenderWindow* W, sf::Music& background_music)
{
	// sound icon depends on music on/off //
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
	current_sound_icon_sprite.setPosition(text_volume_number.getPosition().x + 100, text_volume_number.getPosition().y - 20);

	// change sound on/off //
	if (current_sound_icon_sprite.getGlobalBounds().contains(W->mapPixelToCoords(sf::Mouse::getPosition(*W))) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Sleep(300);
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
		text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 2));
	else if (background_music.getVolume() > 99)
		text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 3));
	else
		text_volume_number.setString(std::to_string(background_music.getVolume()).substr(0, 1));
}
