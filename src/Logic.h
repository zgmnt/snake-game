#include <SFML/Graphics.hpp>
#include "Food.h"
#include "TimeCounter.h"
#include "Scoreboard.h"
#include "Board.h"
#include <array>


enum class Direction
{
	down, left, right, up
};

struct ObstaclesCoords
{
	short x;
	short y;
	short extend_y;
	short extend_x;
};

struct FinalObstaclesCoords
{
	short x;
	short y;
};

class Logic : public Board
{
	Direction direction;
	TimeCounter counter;
	Scoreboard scoreboard;
	int score{ 0 };

	// snake body - single square
	sf::RectangleShape snake_body;
	sf::Texture thick_snake_body_vertical_texture;
	sf::Texture thick_snake_body_horizontal_texture;
	sf::Sprite thick_snake_body_vertical_sprite;
	sf::Sprite thick_snake_body_horizontal_sprite;
	sf::Sprite final_thick_snake_body_sprite;

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
	std::vector<Food> food_set;
	short max_food_amount{ 8 };

	//init snake length
	int length{ 8 };

	unsigned short self_eating{ 4 };
	static const int maxLenght{ 100 };
	struct Snake
	{
		unsigned short x;
		unsigned short y;
	};

	std::array< Snake, maxLenght> snake;

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
	
	// obstacle coordinates //
	std::vector<FinalObstaclesCoords> final_obstacles_coords;
	std::vector<ObstaclesCoords>  obstacles_coords;
	// max obstacles
	int obstacles_amount{ 8 };

	bool bObstaclesEnabled{ false };
	bool bArrowsControlType{ true };

	// private functions //
	void switchDirectionArrows();
	void switchDirectionWSAD();
	void snakeHeadMove();
	void tailFollowHead();
	void selfEating();
	void snakeWalls();
	sf::Sprite getSnakeHeadSprite(int offset_x, int offset_y);
	void foodGenerator();
	void generateObstacle();
	void checkSnakeOnObstacles(bool& bEndGame);
	void scoreAlgorithm();
	void thickSnakeBody();
	void eatFood(bool& bEndGame);
	// board
	void setBoardSize(const sf::Texture& board_texture);
	void setBoardField(float BOARD_SIZEX, float BOARD_SIZEY);

public:
	Logic(Direction dir, unsigned int&& snake_len) { direction = dir; length = snake_len; }
	explicit Logic(unsigned int&& snake_len) : length(snake_len) {}
	explicit Logic(Direction dir = Direction::right) : direction(dir) { }

	void load();
	void drawSnake(sf::RenderWindow* W);
	void update(float snake_speed , bool& bEndGame, float fBOARD_SIZEX, float fBOARD_SIZEY);
	// board
	void setBoardSize(float fBOARD_SIZE_X, float fBOARD_SIZE_Y) const;
	void setBoardFeatures(sf::Texture board_texture, sf::Sprite board_sprite);
	void restartGame();
	// pass object's sprites outside
	std::vector<sf::Text> getCounterSprite() ;
	std::vector<Food> getFoodSprite();
	std::vector<sf::Text> getScoreboard();
	std::vector<FinalObstaclesCoords> getObstacles();

	bool &isObstaclesEnabled()	    { return bObstaclesEnabled;			  }
	bool & isArrowControlType()	    { return bArrowsControlType;		  }
	int getFoodSize() const			{ return food_set.size();			  }
	sf::Sprite getFoodSprite(int n) { return food_set[n].getFoodSprite(); }
};
