#include <SFML/Graphics.hpp>
#include "Food.h"
#include "TimeCounter.h"
#include "Scoreboard.h"
#include "Board.h"


enum class Direction
{
	down, left, right, up
};

struct ObstaclesCoords
{
	short x = 5;
	short y = 5;
	short extend_y = 5;
	short extend_x = 5;
};

struct FinalObstaclesCoords
{
	short x = 5;
	short y = 5;
};

class Algorithm : public Board
{
	Direction direction;
	TimeCounter counter;
	Scoreboard scoreboard;
	int score = 0;

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
	sf::Clock score_lenght_clock;
	sf::Clock snake_speed_clock;

	// obstacles //
	sf::Texture rock_texture;
	sf::Sprite rock_sprite;

	// obstacle coordinates //
	std::vector<FinalObstaclesCoords> final_obstacles_coords{};
	std::vector<ObstaclesCoords>  obstacles_coords = {};
	// max obstacles
	int obstacles_amount = 8;

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
	void eatFood(bool& bEndGame);
	void generateObstacle();
	void checkSnakeOnObstacles(bool& bEndGame);
	void drawObstacles(sf::RenderWindow* WINDOW);
	void drawCounter(sf::RenderWindow* W);
	void drawScoreboard(sf::RenderWindow* W);
	void scoreAlgorithm();
	// board
	void setBoardSize(const sf::Texture& board_texture);
	void setBoardField(float BOARD_SIZE);
public:
	Algorithm(Direction dir, unsigned int&& snake_len)
	{
		direction = dir;
		length = snake_len;
	}
	explicit Algorithm(unsigned int&& snake_len) : length(snake_len) {}
	explicit Algorithm(Direction dir = Direction::right) : direction(dir) { }
	void load();
	void update(float snake_speed , bool& bEndGame, float fBOARD_SIZE);
	void draw(sf::RenderWindow* W);
	// board
	void setBoardSize(float fBOARD_SIZE_X, float fBOARD_SIZE_Y);
	void setBoardFeatures(sf::Texture board_texture, sf::Sprite board_sprite);
};