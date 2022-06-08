
#include <../../dependencies/SFML/Graphics.hpp>
#include <Windows.h>

enum class FoodType
{
	apple, pear, grape, cherries, double_fruit, poisoned, mushroom
};

class Food
{
	int x = 0;
	int y = 0;

	FoodType food_type;

	sf::Sprite food_sprite;
	// apple // 
	sf::Texture apple_texture;
	sf::Sprite apple_sprite;
	// pear //
	sf::Texture pear_texture;
	sf::Sprite pear_sprite;
	// cherries //
	sf::Texture cherries_texture;
	sf::Sprite cherries_sprite;
	// grape //
	sf::Texture grape_texture;
	sf::Sprite grape_sprite;
	// double friut //
	sf::Texture double_fruit_texture;
	sf::Sprite  double_fruit_sprite;
	// mushroom //
	sf::Texture mushroom_texture;
	sf::Sprite  mushroom_sprite;
	// poisoned apple //
	sf::Texture poisoned_apple_texture;
	sf::Sprite poisoned_apple_sprite;

	void randomFoodSprite();
public:

	Food(int BOARD_SIZE_X, int BOARD_SIZE_Y);
	void loadTextures();
	void setPosition(int X, int Y)  { food_sprite.setPosition(X, Y); }
	int getX()						{ return x; }
	int getY()						{ return y; }
	FoodType getFoodType()			{ return food_type; }
	sf::Sprite getFoodSprite()		{ return food_sprite; }
};
