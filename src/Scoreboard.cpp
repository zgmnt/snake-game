#include "Scoreboard.h"

void Scoreboard::setFont()
{
	length_text.setFont(font);
	score_text.setFont(font);
	length.setFont(font);
	score.setFont(font);
}

void Scoreboard::setOutline()
{
	length_text.setOutlineThickness(2);
	score_text.setOutlineThickness(2);
	length.setOutlineThickness(2);
	score.setOutlineThickness(2);
}

Scoreboard::Scoreboard()
{
	loadFont();
	setFont();
	setOutline();
	setScoreText();
	setLenghtText();
}

void Scoreboard::setColor(sf::Color COLOR)
{
	length_text.setFillColor(COLOR);
	score_text.setFillColor(COLOR);
	length.setFillColor(COLOR);
	score.setFillColor(COLOR);
}

void Scoreboard::setFontSize(int FONT_SIZE)
{
	font_size = FONT_SIZE;

	length_text.setCharacterSize(font_size);
	score_text.setCharacterSize(font_size);
	length.setCharacterSize(font_size);
	score.setCharacterSize(font_size);
}

void Scoreboard::setPosition(int WIDTH_PERCENT, int HEIGHT_PERCENT)
{
	length_text.setPosition(1250 * WIDTH_PERCENT/100, 700 * HEIGHT_PERCENT/100);
	length.setPosition(length_text.getPosition().x - length_text.getCharacterSize()*3, length_text.getPosition().y);

	score_text.setPosition(length_text.getPosition().x , length_text.getPosition().y+50);
	score.setPosition(score_text.getPosition().x - length_text.getCharacterSize()*3, score_text.getPosition().y);
}
