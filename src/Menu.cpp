#include "Menu.h"
#include "TextGenResp.h"


void Menu::load(int WIDTH , int HEIGHT)
{
	Generator gen{ "fonts\\mrsmonster.ttf" };
	// exit text
	Generator::setText(m_text_exit, 50, sf::Color::Yellow, "EXIT", std::make_pair(125, 322));
	// start text
	Generator::setText(m_text_start, 50, sf::Color::Yellow, "START", std::make_pair(125, 72));
	// settings text
	Generator::setText(m_text_settings, 50, sf::Color::Yellow, "SETTINGS", std::make_pair(125, 142));
}
Switcher Menu::update(sf::RenderWindow* W)
{
	if (Response::isChecked(W, m_text_start))
		return Switcher::game;
	else if (Response::isChecked(W, m_text_settings))
		return Switcher::settings;
	else if (Response::isChecked(W, m_text_exit))
		W->close();
	else
		return Switcher::menu;
}
