
#include <../../dependencies/SFML/Graphics.hpp>

class Board
{
	sf::Texture board_texture;
	sf::Sprite board_sprite;

public:
	Board();
	~Board() {}
	void setBoardSize(float fBOARD_SIZEX,  float fBOARD_SIZEY);
	sf::Texture getTexture() { return board_texture; }
	sf::Sprite getSprite() { return board_sprite; }
	unsigned short getBoardPositionX() { return board_sprite.getPosition().x; }
	unsigned short getBoardPositionY() { return board_sprite.getPosition().y; }
	float getBoardScaleX() { return board_sprite.getScale().x; }
	float getBoardScaleY() { return board_sprite.getScale().y; }
};
