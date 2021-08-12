#include "Board.h"

void Board::setBoardSize(float fBOARD_SIZE)
{
	if(fBOARD_SIZE == 0.5)
		board_sprite.setPosition(50, 50);
	else
		board_sprite.setPosition(150, 100);

	board_sprite.setScale(fBOARD_SIZE, fBOARD_SIZE);
}

Board::Board()
{
	board_texture.loadFromFile("img\\board.jpg");
	board_sprite = sf::Sprite(board_texture);
	board_sprite.setPosition(50, 50);
	board_sprite.setScale(0.5, 0.5);
}