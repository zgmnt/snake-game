#include "GameSettings.h"
#include <fstream>

void GameSettings::load(int WIDTH, int HEIGHT)
{
	Generator gen{ "fonts\\mrsmonster.ttf" };
	// text default
	Generator::setText(m_text_default, 50, sf::Color::Yellow, "- DEFAULT -", std::make_pair(125, 120));
	// text back
	Generator::setText(m_text_back, 50, sf::Color::Yellow, "BACK", std::make_pair(125, 510));
	// text  board size X
	Generator::setText(m_text_board_sizeX, 35, sf::Color::Yellow, "BOARD SIZE X ", std::make_pair(125, 200));
	// text  board size Y
	Generator::setText(m_text_board_sizeY, 35, sf::Color::Yellow, "BOARD SIZE Y ", std::make_pair(125, 250));
	// text  snake speed
	Generator::setText(m_text_snake_speed, 35, sf::Color::Yellow, "SNAKE SPEED ", std::make_pair(125, 300));
	// text screen resolution
	Generator::setText(m_text_screen_resolution, 50, sf::Color::Yellow, "YOUR RESOLUTION : "
		+ std::to_string(getScreenResolution().width) + " " + std::to_string(getScreenResolution().height), std::make_pair(125, 10));
	// text constrol
<<<<<<< HEAD
	text_control_WSAD.setFont(font);
	text_control_WSAD.setString("CONTROL TYPE ARROWS ");
	text_control_WSAD.setOutlineColor(sf::Color::Red);
	text_control_WSAD.setFillColor(sf::Color::Yellow);
	text_control_WSAD.setOutlineThickness(2);
	text_control_WSAD.setCharacterSize(35);
	text_control_WSAD.setPosition(WIDTH / 10, 450);

=======
	Generator::setText(m_text_control_WSAD, 35, sf::Color::Yellow, "CONTROL TYPE ARROWS ", std::make_pair(125, 450));
>>>>>>> c2d2daa421e73043a787e95f0ea1252f0228cf88
	// text music
	Generator::setText(m_text_music, 35, sf::Color::Yellow, "MUSIC ", std::make_pair(125, 400));
	// text obstacles
	Generator::setText(m_text_obstacles, 35, sf::Color::Yellow, "OBSTACLES ", std::make_pair(125, 350));

	getConfigData();
}

Switcher GameSettings::update(sf::RenderWindow* W)
{
	if (Response::isChecked(W, m_text_back))
		return Switcher::settings;
	
	return Switcher::game_settings;
}
ScreenResolution GameSettings::getScreenResolution() const
{
	ScreenResolution screen_resolution;
	RECT handle_screen;
	GetWindowRect(GetDesktopWindow(), &handle_screen);
	screen_resolution.width = handle_screen.right;
	screen_resolution.height = handle_screen.bottom;

	return screen_resolution;
}
void GameSettings::getConfigData()
{
	std::vector<sf::Text*> texts 
	{
		&m_text_board_sizeX ,
		& m_text_board_sizeY,
		& m_text_snake_speed,
		& m_text_obstacles,
		& m_text_music,
		& m_text_control_WSAD

	};
	std::fstream file;
	file.open("game_config.txt");
	std::string temp;

	for (auto it : texts)
	{
		file >> temp;
		temp = temp.substr(temp.size() - 1, temp.size());
		if (temp == "N") { temp = "ON"; }
		else if (temp == "F") { temp = "OFF"; }
		it->setString(it->getString() + temp);
	}
	file.close();
}
