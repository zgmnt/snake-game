#include "Background.h"
#include "SetsSwitcher.h"
#include "Game.h"
#include "Menu.h"

class Sets
{
	Background background;
	Game game;
	Menu menu;
	Switcher switcher; // current set

public:
	Sets() {}
	Sets(Switcher set = Switcher::menu) : switcher(set) {}
	~Sets() {}
	void load(int WIDTH, int HEIGHT);
	void update(sf::RenderWindow* W);
};
