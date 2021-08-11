#include "Sets.h"

void Sets::update(sf::RenderWindow* W)
{
	if (switcher == Switcher::menu)
		background.update(W);
}

// init textures of sets //
void Sets::load(int WIDTH, int HEIGHT)
{
	background.load();
}