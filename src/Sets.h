#include "Background.h"
#include "Game.h"
#include "Menu.h"
#include "MenuSettings.h"
#include "AudioSettings.h"
#include "GameSettings.h"

class Sets
{
	Background background;
	sf::Music menu_music;

	Game game;
	Menu menu;
	Settings settings;
	AudioSettings audio_settings;
	GameSettings game_settings;
	Switcher switcher; // current set

public:
	Sets(Switcher set = Switcher::menu) : switcher(set) {}
	~Sets() {}
	void load(int WIDTH, int HEIGHT);
	void update(sf::RenderWindow* W);
};
