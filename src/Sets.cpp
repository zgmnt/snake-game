#include "Sets.h"

void Sets::update(sf::RenderWindow* W)
{
	if (switcher == Switcher::menu)
		background.update(W);
	else if (switcher == Switcher::game)
	{
		switcher = game.update(W);
		game.draw(W);
		//game.musicPlay();
	}
}

// init textures of sets //
void Sets::load(int WIDTH, int HEIGHT)
{
	background.load();
	game.load(WIDTH, HEIGHT);
}