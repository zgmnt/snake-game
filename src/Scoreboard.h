#include <SFML/Graphics.hpp>

class Scoreboard
{
	//static
	sf::Text length_text;
	sf::Text score_text;

	//dynamic
	sf::Text length;
	sf::Text score;

	sf::Font font;

	int font_size = 10;

	void setFont();
	void setOutline();
	void loadFont()		 { font.loadFromFile("fonts\\mrsmonster.ttf"); }
	void setScoreText()	 { score_text.setString("SCORE"); }
	void setLenghtText() { length_text.setString("LENGHT"); }
public:

	Scoreboard();

	void setColor(sf::Color Color);
	void setFontSize(int FONT_SIZE);
	void setPosition(int WIDTH_PERCENT, int HEIGHT_PERCENT);
	void setScore(int SCORE)	  {  score.setString(std::to_string(SCORE));}
	void setLenght(int LENGHT)	  {  length.setString(std::to_string(LENGHT));
	}

	sf::Text getSnakeLenghtText() { return length_text; }
	sf::Text getScoreText()		  { return score_text; }
	sf::Text getLenght()		  { return length; }
	sf::Text getScore()			  { return score; }
};
