#include "Food.h"

Food::Food(int BOARD_SIZE_X, int BOARD_SIZE_Y)
{
	srand((unsigned)time(NULL));

	x = (rand() % BOARD_SIZE_X-1)+1;
	y = (rand() % BOARD_SIZE_Y-1)+1;

	loadTextures();
	randomFoodSprite();
}

void Food::randomFoodSprite()
{
	srand((unsigned)time(NULL));
	switch (rand() % 7)
	{
	case 0:
		food_type = FoodType::apple;
		food_sprite = sf::Sprite(apple_sprite);
		break;
	case 1:
		food_type = FoodType::pear;
		food_sprite = sf::Sprite(pear_sprite);
		break;
	case 2:
		food_type = FoodType::cherries;
		food_sprite = sf::Sprite(cherries_sprite);
		break;
	case 3:
		food_type = FoodType::grape;
		food_sprite = sf::Sprite(grape_sprite);
		break;
	case 4:
		food_type = FoodType::double_fruit;
		food_sprite = sf::Sprite(double_fruit_sprite);
		break;
	case 5:
		food_type = FoodType::mushroom;
		food_sprite = sf::Sprite(mushroom_sprite);
		break;
	case 6:
		food_type = FoodType::poisoned;
		food_sprite = sf::Sprite(poisoned_apple_sprite);
		break;
	}
}

void Food::loadTextures()
{
	// apple
	apple_texture.loadFromFile("img\\apple.png");
	apple_sprite = sf::Sprite(apple_texture);
	apple_sprite.setScale(0.25, 0.25);
	apple_sprite.setOrigin(18, 40.0);
	//pear
	pear_texture.loadFromFile("img\\pear.png");
	pear_sprite = sf::Sprite(pear_texture);
	pear_sprite.setScale(0.25, 0.25);
	pear_sprite.setOrigin(18, 40.0);
	// cherries
	cherries_texture.loadFromFile("img\\cherries.png");
	cherries_sprite = sf::Sprite(cherries_texture);
	cherries_sprite.setScale(0.23, 0.23);
	cherries_sprite.setOrigin(18, 40.0);
	// grape
	grape_texture.loadFromFile("img\\grape.png");
	grape_sprite = sf::Sprite(grape_texture);
	grape_sprite.setScale(0.3, 0.3);
	grape_sprite.setOrigin(18, 40.0);
	// double_fruit
	double_fruit_texture.loadFromFile("img\\double_fruit.png");
	double_fruit_sprite = sf::Sprite(double_fruit_texture);
	double_fruit_sprite.setScale(0.32, 0.32);
	double_fruit_sprite.setOrigin(18, 40.0);
	// mushroom
	mushroom_texture.loadFromFile("img\\mushroom.png");
	mushroom_sprite = sf::Sprite(mushroom_texture);
	mushroom_sprite.setScale(0.18, 0.18);
	mushroom_sprite.setOrigin(18, 40.0);
	// poisoned
	poisoned_apple_texture.loadFromFile("img\\poisoned_apple.png");
	poisoned_apple_sprite = sf::Sprite(poisoned_apple_texture);
	poisoned_apple_sprite.setScale(0.5, 0.5);
	poisoned_apple_sprite.setOrigin(18, 20);
}
