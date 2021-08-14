#include "Sets.h"

void Sets::update(sf::RenderWindow* W)
{

	if (switcher != Switcher::game)
		background.update(W);

	switch (switcher)
	{
	case Switcher::menu:
		switcher = menu.update(*W);
		menu.draw(*W);
		break;
	case Switcher::game:
		switcher = game.update(W);
		game.draw(W);
	}
}

// init textures of sets //
void Sets::load(int WIDTH, int HEIGHT)
{
	background.load();
	game.load(WIDTH, HEIGHT);
	menu.load(WIDTH, HEIGHT);
}
