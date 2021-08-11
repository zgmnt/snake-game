#include "Background.h"

void Background::load()
{
	//system("dir");

	// loading textures and sprites
	background_1.loadFromFile("img\\background_1.png");
	background_1_sprite = sf::Sprite(background_1);

	background_2.loadFromFile("img\\background_2.png");
	background_2_sprite = sf::Sprite(background_2);

	background_3.loadFromFile("img\\background_3.png");
	background_3_sprite = sf::Sprite(background_3);

	// first background
	switchBackground();
}

void Background::update(sf::RenderWindow* W)
{
	if (background_switch_clock.getElapsedTime().asSeconds() > background_switch_time)
		switchBackground();

	transition();
	alpha();

	W->draw(sprite_current_background);
}

void Background::switchBackground()
{
	// background select //

	srand((unsigned)time(NULL));

	choice = rand() % 3;

	if (!choice)
		sprite_current_background = sf::Sprite(background_1);
	else if (choice)
		sprite_current_background = sf::Sprite(background_2);
	else
		sprite_current_background = sf::Sprite(background_3);

	background_switch_clock.restart();
}
void Background::transition()
{
	// background movement //

	if (sprite_current_background.getPosition().x > -730 && !background_change_direction)
		sprite_current_background.setPosition(sprite_current_background.getPosition().x - 2, -340);
	else
		background_change_direction = 1;

	if (background_change_direction)
	{
		if (sprite_current_background.getPosition().x > -230)
			background_change_direction = 0;

		sprite_current_background.setPosition(sprite_current_background.getPosition().x + 2, -340);
	}
}
void Background::alpha()
{	//  background alpha depends on background_alpha_clock  //

	sprite_current_background.setColor(sf::Color(255, 255, 255, 255));

	if (background_alpha_clock.getElapsedTime().asSeconds() > 30)
		background_alpha_clock.restart();

	if (background_alpha_clock.getElapsedTime().asSeconds() < 2.54)
		sprite_current_background.setColor(sf::Color(255, 255, 255, background_alpha_clock.getElapsedTime().asSeconds() * 100));
	else if ((background_alpha_clock.getElapsedTime().asSeconds() < 30) && (background_alpha_clock.getElapsedTime().asSeconds() > 27.45))
		sprite_current_background.setColor(sf::Color(255, 255, 255, 510 - ((background_alpha_clock.getElapsedTime().asSeconds() - 24.9) * 100)));
	else
		sprite_current_background.setColor(sf::Color(255, 255, 255, 255));
}