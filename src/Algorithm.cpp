#include "Algorithm.h"

void Algorithm::load()
{
	// snake body
	snake_body.setSize(sf::Vector2f(16, 16));
	snake_body.setFillColor(sf::Color(160, 196, 50, 255));

	// snake head
	snake_right.loadFromFile("img\\snake_head_right.png");
	snake_right_sprite = sf::Sprite(snake_right);
	snake_right_sprite.setScale(0.25, 0.25);
	snake_right_sprite.setOrigin(0, 30.0);
	snake_left.loadFromFile("img\\snake_head_left.png");
	snake_left_sprite = sf::Sprite(snake_left);
	snake_left_sprite.setScale(0.25, 0.25);
	snake_left_sprite.setOrigin(60.0, 30.0);
	snake_up.loadFromFile("img\\snake_head_up.png");
	snake_up_sprite = sf::Sprite(snake_up);
	snake_up_sprite.setScale(0.25, 0.25);
	snake_up_sprite.setOrigin(30.0, 60.0);
	snake_down.loadFromFile("img\\snake_head_down.png");
	snake_down_sprite = sf::Sprite(snake_down);
	snake_down_sprite.setScale(0.25, 0.25);
	snake_down_sprite.setOrigin(30.0, 0);

	foodGenerator();
}
void Algorithm::update()
{
	snakeHeadMove();
	tailFollowHead();
	switchDirectionArrows();
	selfEating();
	snakeWalls();
	eatFood();

	// food generate
	if (food_clock.getElapsedTime().asSeconds() > 3.5)
	{
		if (food_set.size() < max_food_amount)
			foodGenerator();

		food_clock.restart();
	}
}
void Algorithm::draw(sf::RenderWindow* W)
{
	drawSnake(W);
	drawFood(W);
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
	W->draw(getSnakeHeadSprite(snake[0].x, snake[0].y));
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
void Algorithm::snakeWalls()
{
	// horizontal //
	if (snake[0].x == board_X_fields)
		snake[0].x = 1;

	else if (snake[0].x == 0)
		snake[0].x = board_X_fields;

	// vertical //
	else if (snake[0].y == board_Y_fields)
		snake[0].y = 1;

	else if (snake[0].y == 0)
		snake[0].y = board_Y_fields;
}
sf::Sprite Algorithm::getSnakeHeadSprite(int offset_x, int offset_y)
{
	// head moves according to direction
	switch (direction)
	{
	case Direction::right:
		snake_current_head_sprite = snake_right_sprite;
		break;
	case Direction::left:
		snake_current_head_sprite = snake_left_sprite;
		break;
	case Direction::down:
		snake_current_head_sprite = snake_down_sprite;
		break;
	case Direction::up:
		snake_current_head_sprite = snake_up_sprite;
		break;
	}
	snake_current_head_sprite.setPosition(offset_x * square_size + 50, offset_y * square_size + 50);

	return snake_current_head_sprite; // return to draw
}
void Algorithm::foodGenerator()
{
	Food* food = new Food(board_X_fields, board_Y_fields);
	food_set.push_back(*food);
}
void Algorithm::drawFood(sf::RenderWindow* WINDOW)
{
	for (size_t z = 0; z < food_set.size(); z++)
	{
		food_set[z].setPosition(food_set[z].getX() * square_size + 50, food_set[z].getY() * square_size + 50);
		WINDOW->draw(food_set[z].getFoodSprite());
	}
}
void Algorithm::eatFood()
{
	size_t  i = food_set.size();
	while (i--)
	{
		if (food_set[i].getX() == snake[0].x)
		{
			if (food_set[i].getY() == snake[0].y)
			{
				if (food_set[i].getFoodType() == FoodType::double_fruit)
				{
					length += 2;
				}
				else if (food_set[i].getFoodType() == FoodType::mushroom)
				{
					// end game
				}
				else if (food_set[i].getFoodType() == FoodType::poisoned)
				{
					if (length > min_lenght_self_eating)
					{
						length--;
					}
				}
				else
				{
					length++;
				}
				food_set.erase(food_set.begin() + i);
				break;
			}
		}
	}
}
