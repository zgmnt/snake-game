#include <SFML/Graphics.hpp>



enum class Direction
{
	down, left, right, up
};


class Algorithm
{
	Direction direction;

	// snake body - single square
	sf::RectangleShape snake_body;

	unsigned short self_eating{ 4 };
	static const int maxLenght{ 100 };
	struct Snake
	{
		unsigned short x;
		unsigned short y;

	}snake[maxLenght];

	//init snake length
	int length{ 8 };

	// board features
	int square_size{ 16 };
	int board_texture_size_x{ 0 };
	int board_texture_size_y{ 0 };
	int board_X_fields{ 43 };
	int board_Y_fields{ 37 };


	// private functions //
	void switchDirectionArrows();
	void snakeHeadMove();
	void tailFollowHead();
	void drawSnake(sf::RenderWindow* W);
	void selfEating();
	void snakeWalls();
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