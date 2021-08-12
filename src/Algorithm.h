#include <SFML/Graphics.hpp>
#include "Food.h"

enum class Direction
{
	down, left, right, up
};

class Algorithm
{
	Direction direction;

	// snake body - single square
	sf::RectangleShape snake_body;

	// snake head
	sf::Texture snake_right;
	sf::Sprite snake_right_sprite;
	sf::Texture snake_left;
	sf::Sprite snake_left_sprite;
	sf::Texture snake_up;
	sf::Sprite snake_up_sprite;
	sf::Texture snake_down;
	sf::Sprite snake_down_sprite;
	sf::Sprite snake_current_head_sprite;

	// food
	std::vector<Food> food_set{};
	short max_food_amount{ 8 };

	unsigned short self_eating{ 4 };
	static const int maxLenght{ 100 };
	struct Snake
	{
		unsigned short x;
		unsigned short y;

	}snake[maxLenght];

	//init snake length
	int length{ 8 };
	const int min_lenght_self_eating{ 4 };

	// board features
	int square_size{ 16 };
	int board_texture_size_x{ 0 };
	int board_texture_size_y{ 0 };
	int board_X_fields{ 43 };
	int board_Y_fields{ 37 };

	// clocks //
	sf::Clock food_clock;

	// private functions //
	void switchDirectionArrows();
	void snakeHeadMove();
	void tailFollowHead();
	void drawSnake(sf::RenderWindow* W);
	void selfEating();
	void snakeWalls();
	sf::Sprite getSnakeHeadSprite(int offset_x, int offset_y);
	void foodGenerator();
	void drawFood(sf::RenderWindow* WINDOW);
	void eatFood();
public:
	Algorithm(Direction dir, unsigned int&& snake_len)
	{
		direction = dir;
		length = snake_len;
	}
	explicit Algorithm(unsigned int&& snake_len) : length(snake_len) {}
	explicit Algorithm(Direction dir = Direction::right) : direction(dir) { }
	void load();
	void update();
	void draw(sf::RenderWindow* W);
};