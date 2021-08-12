#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class InGameSettings
{
	sf::Font font;

	// board
	sf::Text text_board_size_string;

	float max_board_size{ 5.3 };
	int min_board_size{ 3 };
	float fboard_sizeX{ 5 }; // init
	float fboard_sizeY{ 5 }; // init

	// snake
	sf::Text text_snake_speed_string;
	sf::Text text_snake_speed;
	int min_snake_speed{ 1 };
	int max_snake_speed{ 8 };
	float fsnake_speed{ 2 }; // init

	sf::Texture up_texture;
	sf::Texture down_texture;
	sf::Texture horizontal_line_board;
	sf::Texture horizontal_line_snake;
	sf::Sprite up_sprite_board_sizeX;
	sf::Sprite up_sprite_board_sizeY;
	sf::Sprite down_sprite_board_sizeX;
	sf::Sprite down_sprite_board_sizeY;
	sf::Sprite up_sprite_snake_speed;
	sf::Sprite down_sprite_snake_speed;
	sf::Sprite horizontal_line_sprite_board_sizeX;
	sf::Sprite horizontal_line_sprite_board_sizeY;
	sf::Sprite horizontal_line_sprite_snake_speed;

	 // back button
	sf::RectangleShape inner_back_to_game_button;
	sf::RectangleShape outer_back_to_game_button;
	sf::Text back_to_game_text;
	int nsize_back_to_game_button_x{ 241 };
	int nsize_back_to_game_button_y{ 60 };

	// obstacles button
	sf::RectangleShape inner_obstacles_button;
	sf::RectangleShape outer_obstacles_button;
	sf::Text obstacles_text;
	int nsize_obstacles_button_x{ 250 };
	int nsize_obstacles_button_y{ 50 };

	// control type button
	sf::RectangleShape inner_control_type_button;
	sf::RectangleShape outer_control_type_button;
	sf::Text control_type_text;
	int nsize_back_control_type_button_x = 310;
	int nsize_back_control_type_button_y = 50;

	// main window size
	int outer_frame_size{ 500 };
	int inner_frame_size{ 480 };
	sf::RectangleShape outerFrame;
	sf::RectangleShape innerFrame;

	void snakeSpeedRefresh();
	void boardSizeRefreshX();
	void boardSizeRefreshY();
	void boardSizeUpdateX(const sf::RenderWindow* WINDOW);
	void boardSizeUpdateY(const sf::RenderWindow* WINDOW);
	void snakeSpeedUpdate(const sf::RenderWindow* WINDOW);
	void backToGameButtonUpdate(const sf::RenderWindow* WINDOW, bool &bShowSettings);
	void obstacleEnableUpdate(const sf::RenderWindow* WINDOW, bool& isObstaclesEnabled);
	void controlTypeUpdate(const sf::RenderWindow* WINDOW, bool& isArrowControlType);
public:
	InGameSettings() {};
	~InGameSettings() {};
	void draw(sf::RenderWindow* WINDOW);
	void update(sf::RenderWindow* WINDOW, bool& bShowSettings, bool& isObstaclesEnabled, bool& isArrowControlType);
	void load(int WIDTH, int HEIGHT);
	float getSnakeSpeed() { return fsnake_speed; }
	float getBoardSizeX() { return (fboard_sizeX / 10); }
	float getBoardSizeY() { return (fboard_sizeY / 10); }
};
