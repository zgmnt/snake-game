#include "Algorithm.h"

void Algorithm::load()
{
	// snake body
	snake_body.setSize(sf::Vector2f(16, 16));
	snake_body.setFillColor(sf::Color(160, 196, 50, 255));
	thick_snake_body_vertical_texture.loadFromFile("img\\thic_snake_vertical.png");
	thick_snake_body_vertical_sprite = sf::Sprite(thick_snake_body_vertical_texture);
	thick_snake_body_horizontal_texture.loadFromFile("img\\thic_snake_horizontal.png");
	thick_snake_body_horizontal_sprite = sf::Sprite(thick_snake_body_horizontal_texture);
	thick_snake_body_horizontal_sprite.setOrigin(5, 0);
	thick_snake_body_horizontal_sprite.setScale(0.85, 0.85);
	thick_snake_body_vertical_sprite.setOrigin(0, 6);
	thick_snake_body_vertical_sprite.setScale(0.85, 0.85);

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

	// rocks/obstacles
	rock_texture.loadFromFile("img\\rock.png");
	rock_sprite = sf::Sprite(rock_texture);
	rock_sprite.setScale(0.18f, 0.18f);
	rock_sprite.setOrigin(8, 8);

	// counter
	counter.setColor(sf::Color::Cyan);
	counter.setFontSize(30);
	counter.setPosition(50, 94);

	// scoreboard
	scoreboard.setColor(sf::Color::Yellow);
	scoreboard.setFontSize(45);
	scoreboard.setPosition(80, 10);

	foodGenerator();
	generateObstacle();
}
void Algorithm::update(float snake_speed , bool& bEndGame, float fBOARD_SIZEX, float fBOARD_SIZEY)
{
	// change board size
	if ((Board::getBoardScaleX() != fBOARD_SIZEX) || (Board::getBoardScaleY() != fBOARD_SIZEY))
	{
		setBoardField(fBOARD_SIZEX, fBOARD_SIZEY);
		food_set.clear();
		final_obstacles_coords.clear();
		obstacles_coords.clear();
		generateObstacle();
		snake[0].x = 1;
		snake[0].y = 1;
	}

	if ((1 / snake_speed) < snake_speed_clock.getElapsedTime().asSeconds() * 4)
	{
		snakeHeadMove();
		tailFollowHead();
		switchDirectionArrows();
		selfEating();
		snakeWalls();
		eatFood(bEndGame);

		if (bObstaclesEnabled)
			checkSnakeOnObstacles(bEndGame);

		snake_speed_clock.restart();
	}

	// scoreboard & counter
	if (score_lenght_clock.getElapsedTime().asSeconds() > 1)
	{
		scoreboard.setScore(score);
		scoreboard.setLenght(length);
		scoreAlgorithm();
		counter.timeUpdate();
		score_lenght_clock.restart();
	}

	// food generate
	if (food_clock.getElapsedTime().asSeconds() > 3.5)
	{
		if (food_set.size() < max_food_amount)
			foodGenerator();

		food_clock.restart();
	}

	// controls type
	if (bArrowsControlType)
		switchDirectionArrows();
	else
		switchDirectionWSAD();
}
void Algorithm::draw(sf::RenderWindow* W)
{
	drawSnake(W);
	drawFood(W);
	drawCounter(W);
	drawScoreboard(W);
	if (bObstaclesEnabled)
		drawObstacles(W);
}

void  Algorithm::drawCounter(sf::RenderWindow* W)
{
	counter.timeTextUpdate();
	W->draw(counter.getTextSeconds());
	W->draw(counter.getTextMinutes());
	W->draw(counter.getTextColon());
}
void  Algorithm::drawScoreboard(sf::RenderWindow* W)
{
	W->draw(scoreboard.getLenght());
	W->draw(scoreboard.getScore());
	W->draw(scoreboard.getScoreText());
	W->draw(scoreboard.getSnakeLenghtText());
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
void Algorithm::switchDirectionWSAD()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != Direction::right)
		direction = Direction::left;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != Direction::left)
		direction = Direction::right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != Direction::down)
		direction = Direction::up;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != Direction::up)
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
		snake_body.setPosition(snake[k].x * square_size + Board::getBoardPositionX(), snake[k].y * square_size + Board::getBoardPositionY());
		W->draw(snake_body);
	}
	W->draw(getSnakeHeadSprite(snake[0].x, snake[0].y));

	W->draw(final_thick_snake_body_sprite);
	if ((final_thick_snake_body_sprite.getPosition().x == snake[length].x * square_size + Board::getBoardPositionX()) &&
		(final_thick_snake_body_sprite.getPosition().y == snake[length].y * square_size + Board::getBoardPositionY()))
		final_thick_snake_body_sprite.setColor((sf::Color(160, 196, 50, 0)));
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
	snake_current_head_sprite.setPosition(offset_x * square_size + Board::getBoardPositionX(), offset_y * square_size + Board::getBoardPositionY());

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
void Algorithm::eatFood(bool& bEndGame)
{
	size_t  i = food_set.size();
	while (i--)
	{
		if (food_set[i].getX() == snake[0].x)
		{
			if (food_set[i].getY() == snake[0].y)
			{
				thickSnakeBody();
				if (food_set[i].getFoodType() == FoodType::double_fruit)
				{
					length += 2;
				}
				else if (food_set[i].getFoodType() == FoodType::mushroom)
				{
					bEndGame = true;
				}
				else if (food_set[i].getFoodType() == FoodType::poisoned)
				{
					if (length > self_eating)
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
void Algorithm::thickSnakeBody()
{
	if (direction == Direction::right || direction == Direction::left)
		final_thick_snake_body_sprite = sf::Sprite(thick_snake_body_vertical_sprite);
	else
		final_thick_snake_body_sprite = sf::Sprite(thick_snake_body_horizontal_sprite);

	final_thick_snake_body_sprite.setPosition(snake[0].x * square_size 
		+ Board::getBoardPositionX(), snake[0].y * square_size + Board::getBoardPositionY());
}
void Algorithm::generateObstacle()
{
	int size = (rand() % obstacles_amount) + 5;
	// create obstacles
	for (int i = 0; i < size; i++)
	{
		ObstaclesCoords* ptr = new ObstaclesCoords;
		ptr->x = rand() % board_X_fields;
		ptr->y = rand() % board_Y_fields;
		ptr->extend_x = (rand() % 10) - (rand() % 10);
		ptr->extend_y = (rand() % 10) - (rand() % 10);
		obstacles_coords.push_back(*ptr);
	}
	// extension obstalces
	for (size_t n = 0; n < obstacles_coords.size(); n++)
	{
		for (int i = 0; i < abs(obstacles_coords[n].extend_x); i++)
		{
			FinalObstaclesCoords* ptr = new FinalObstaclesCoords;
			if ((obstacles_coords[n].extend_x < 0) && (obstacles_coords[n].x - i > 0))
				ptr->x = obstacles_coords[n].x - i;
			else if (obstacles_coords[n].x + i < board_X_fields)
				ptr->x = obstacles_coords[n].x + i;
			ptr->y = obstacles_coords[n].y;
			if ((ptr->x + i < board_X_fields) && (ptr->x + i > 0))
				final_obstacles_coords.push_back(*ptr);
		}

		for (int i = 0; i < abs(obstacles_coords[n].extend_y); i++)
		{
			FinalObstaclesCoords* ptr = new FinalObstaclesCoords;
			ptr->x = obstacles_coords[n].x;
			if (obstacles_coords[n].extend_y < 0 && (obstacles_coords[n].y - i > 0))
				ptr->y = obstacles_coords[n].y - i;
			else if (obstacles_coords[n].y - i < board_Y_fields)
				ptr->y = obstacles_coords[n].y + i;
			if ((ptr->y + i < board_Y_fields) && (ptr->y + i > 0))
				final_obstacles_coords.push_back(*ptr);
		}
	}
}
void Algorithm::checkSnakeOnObstacles(bool& bEndGame)
{
	// whether snake head hit obstacle
	for (size_t n = 0; n < final_obstacles_coords.size(); n++)
	{
		if (final_obstacles_coords[n].x == snake[0].x)
		{
			if (final_obstacles_coords[n].y == snake[0].y)
			{
				bEndGame = true;
				break;
			}
		}
	}
}
void Algorithm::drawObstacles(sf::RenderWindow* WINDOW)
{
	for (size_t n = 0; n < final_obstacles_coords.size(); n++)
	{
		rock_sprite.setPosition(final_obstacles_coords[n].x * square_size 
			+ Board::getBoardPositionX(), final_obstacles_coords[n].y * square_size + Board::getBoardPositionY());
		WINDOW->draw(rock_sprite);
	}
}
void Algorithm::scoreAlgorithm()
{
	score += length; // should be smarter
}

// board
void Algorithm::setBoardFeatures(sf::Texture board_texture, sf::Sprite board_sprite)
{
	setBoardSize(board_texture);;
}
void Algorithm::setBoardSize(const sf::Texture& board_texture)
{
	board_texture_size_x = board_texture.getSize().x;
	board_texture_size_y = board_texture.getSize().y;
}
void Algorithm::setBoardField(float BOARD_SIZEX, float BOARD_SIZEY)
{
	Board::setBoardSize(BOARD_SIZEX, BOARD_SIZEY);
	board_X_fields = int((board_texture_size_x * Board::getBoardScaleX()) / square_size);
	board_Y_fields = int((board_texture_size_y * Board::getBoardScaleY()) / square_size);
}
void Algorithm::restartGame()
{
	score = 0;
	counter.restart();
	snake[0].x = 1;
	snake[0].y = 1;
	final_obstacles_coords.clear();
	obstacles_coords.clear();
	generateObstacle();
	food_set.clear();
	length = self_eating;
}
