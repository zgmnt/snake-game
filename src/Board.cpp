#include "Board.h"

void Board::setBoardSize(float fBOARD_SIZEX, float fBOARD_SIZEY)
{
	board_sprite.setScale(fBOARD_SIZEX, fBOARD_SIZEY);
	board_sprite.setPosition(50, 50);
}

Board::Board()
{
	board_texture.loadFromFile("img\\board.jpg");
	board_sprite = sf::Sprite(board_texture);
	board_sprite.setPosition(50, 50);
	board_sprite.setScale(0.5, 0.5);
}