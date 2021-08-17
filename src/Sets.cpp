#include "Sets.h"

void Sets::update(sf::RenderWindow* W)
{
	if (switcher != Switcher::game)
	{
		background.update();
		background.draw(W);
	}
	else
		menu_music.stop();

	switch (switcher)
	{
	case Switcher::menu:
		switcher = menu.update(W);
		menu.draw(W);
		break;
	case Switcher::game:
		switcher = game.update(W);
		game.draw(W);
		break;
	case Switcher::settings:
		switcher = settings.update(W);
		settings.draw(W);
		break;
	case Switcher::audio_settings:
		switcher = audio_settings.update(W, menu_music);
		audio_settings.draw(W);
		break;
	case Switcher::game_settings:
		switcher = game_settings.update(W);
		game_settings.draw(W);
		break;
	}
}

// init textures of sets //
void Sets::load(int WIDTH, int HEIGHT)
{
	background.load();
	game.load(WIDTH, HEIGHT);
	menu.load(WIDTH, HEIGHT);
	settings.load(WIDTH, HEIGHT);
	audio_settings.load(WIDTH, HEIGHT);
	game_settings.load(WIDTH, HEIGHT);

	// menu music
	menu_music.openFromFile("audio\\menu_music.ogg");
	menu_music.setLoop(true);
	menu_music.play();
}
