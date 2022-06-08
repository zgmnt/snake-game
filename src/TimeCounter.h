
#include <../../dependencies/SFML/Graphics.hpp>

class TimeCounter
{
	int minutes = 0;
	sf::Clock clock;
	sf::Font font_time;
	int font_size = 30;
	sf::Text text_seconds;
	sf::Text text_minutes;
	sf::Text colon;

	// private functions //
	void setFont();
	void setOutline();
	void loadFont();
public:

	TimeCounter();
	void setPosition(int WIDTH_PERCENT, int HEIGHT_PERCENT);
	void setFontSize(int FONT_SIZE);
	void setColor(sf::Color COLOR);
	void timeTextUpdate();
	void timeUpdate();
	sf::Text getTextSeconds()	{ return text_seconds; }
	sf::Text getTextMinutes()	{ return text_minutes; }
	sf::Text getTextColon()		{ return colon; }
	void restart();
};
