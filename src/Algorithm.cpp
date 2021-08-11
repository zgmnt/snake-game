#include "Algorithm.h"

void Algorithm::load()
{
	// snake body
	snake_body.setSize(sf::Vector2f(16, 16));
	snake_body.setFillColor(sf::Color(160, 196, 50, 255));
}
void Algorithm::update()
{
	snakeHeadMove();
	tailFollowHead();
	switchDirectionArrows();
	selfEating();
}
void Algorithm::draw(sf::RenderWindow* W)
{
	drawSnake(W);
}

void Algorithm::switchDirectionArrows()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && direction != Direction::right)
		direction = Direction::left;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction != Direction::left)
		direction = Direction::right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction != Direction::down)
		direction = Direction::up;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction != Direction::up)
		direction = Direction::down;
}
void Algorithm::tailFollowHead()
{
	for (int i = length; i > 0; --i)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
}
void Algorithm::snakeHeadMove()
{
	if (direction == Direction::right) { snake[0].x++; }
	else if (direction == Direction::left) { snake[0].x--; }
	else if (direction == Direction::up) { snake[0].y--; }
	else { snake[0].y++; }
}
void Algorithm::drawSnake(sf::RenderWindow* W)
{
	for (short k = length; k > 0; --k)
	{
		snake_body.setPosition(snake[k].x * square_size + 50, snake[k].y * square_size + 50);
		W->draw(snake_body);
	}
}
void Algorithm::selfEating()
{
	for (short i = self_eating; i < length; i++)
	{
		if (snake[0].x == snake[i].x)
		{
			if (snake[0].y == snake[i].y)
			{
				length = i;
				break;
			}
		}
	}
}