#include "TimeCounter.h"

TimeCounter::TimeCounter()
{
	loadFont();
	setFont();
	setOutline();
}

void TimeCounter::loadFont()
{
	font_time.loadFromFile("fonts\\mrsmonster.ttf");
}
void TimeCounter::setFont()
{
	colon.setString(" : ");
	colon.setFont(font_time);
	text_minutes.setFont(font_time);
	text_seconds.setFont(font_time);
}
void TimeCounter::setOutline()
{
	text_minutes.setOutlineThickness(2);
	text_seconds.setOutlineThickness(2);
	colon.setOutlineThickness(2);
}

void TimeCounter::restart()
{
	minutes = 0;
	clock.restart();
	text_seconds.setString("0");
}

void TimeCounter::timeUpdate()
{
	if (clock.getElapsedTime().asSeconds() > 59)
	{
		minutes++;
		clock.restart();
	}
}
void TimeCounter::timeTextUpdate()
{
	if (clock.getElapsedTime().asSeconds() < 10)
		text_seconds.setString(std::to_string(clock.getElapsedTime().asSeconds()).substr(0, 1));
	else
		text_seconds.setString(std::to_string(clock.getElapsedTime().asSeconds()).substr(0, 2));

	text_minutes.setString(std::to_string(minutes));
}

void TimeCounter::setColor(sf::Color COLOR)
{
	text_seconds.setFillColor(COLOR);
	text_minutes.setFillColor(COLOR);
	colon.setFillColor(COLOR);
}
void TimeCounter::setFontSize(int FONT_SIZE)
{
	font_size = FONT_SIZE;

	text_minutes.setCharacterSize(font_size);
	text_seconds.setCharacterSize(font_size);
	colon.setCharacterSize(font_size);
}
void TimeCounter::setPosition(int WIDTH_PERCENT, int HEIGHT_PERCENT)
{
	colon.setOrigin(colon.getPosition().x + colon.getCharacterSize() / 5, colon.getPosition().y);
	colon.setPosition(1250 * WIDTH_PERCENT/100, 700 * HEIGHT_PERCENT/100);
	text_seconds.setPosition(colon.getPosition().x + colon.getCharacterSize(), colon.getPosition().y);
	text_minutes.setPosition(colon.getPosition().x - colon.getCharacterSize(), colon.getPosition().y);
}
