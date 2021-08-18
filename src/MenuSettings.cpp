#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "MenuSettings.h"

void Settings::load(int WIDTH, int HEIGHT)
{
	Generator gen{ "fonts\\mrsmonster.ttf" };
	// text game
	Generator::setText(m_text_game_settings, 50, sf::Color::Yellow, "GAME SETTINGS", std::make_pair(125, 72));
	// text audio settings
	Generator::setText(m_text_audio_settings, 50, sf::Color::Yellow, "AUDIO SETTINGS", std::make_pair(125, 142));
	// text back
	Generator::setText(m_text_back, 50, sf::Color::Yellow, "BACK", std::make_pair(125, 422));
}
Switcher  Settings::update(sf::RenderWindow* W)
{
	if (Response::isChecked(W, m_text_game_settings))
		return Switcher::game_settings;
	else if (Response::isChecked(W, m_text_audio_settings))
		return Switcher::audio_settings;
	else if (Response::isChecked(W, m_text_back))
		return Switcher::menu;
	
	return Switcher::settings;
}
