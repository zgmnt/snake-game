#pragma once

class Config
{
public:
	// getters
	static int getSnakeLength()		 { return length;			 }
	static bool isObstaclesEnabled() { return bObstaclesEnabled; }
	static int getScore()			 { return score;			 }
	static short getMaxFoodAmount()	 { return max_food_amount;	 }
	static int getObstaclesAmount()	 { return obstacles_amount;	 }
	static int getSquareSize()		 { return square_size;	     }
	static int getBoardXFields()	 { return board_X_fields;	 }
	static int getBoardYFields()	 { return board_Y_fields;    }
	// setters - CHECK INVALID DATA(parameters)
	static void setSnakeLength(int len) { length = len; }
	static void setScore(int p_score) { score = p_score; }
	static void setBoardXFields(int&& val) { board_X_fields = val; }
	static void setBoardYFields(int&& val) { board_Y_fields = val; }
	static void changeSnakeLength(int && len) { length += len; }
	static void changeScore(int&& p_score) { score += p_score; }


private:
	static int length;
	static bool bObstaclesEnabled; // important condiction
	static int score; // just score - int
	static short max_food_amount; // max food at the same time
	static int obstacles_amount; // number of generated obstacles
	static int square_size;
	static int board_X_fields;
	static int board_Y_fields;
};
