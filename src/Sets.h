#include "Background.h"
#include "SetsSwitcher.h"

class Sets
{
	Background background;
	Switcher switcher; // current set

public:
	Sets() {}
	Sets(Switcher set = Switcher::menu) : switcher(set) {}
	~Sets() {}
	void load(int WIDTH, int HEIGHT);
	void update(sf::RenderWindow* W);
};