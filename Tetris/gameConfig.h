#pragma once
class gameConfig
{
public: 
	enum class keys{ LP_LEFT= 'A', LP_RIGHT ='D', LP_ROTATE_CLOCK_WISE= 'S', LP_ROTATE_COUNTER_CLOCK_WISE= 'W', LP_DROP= 'X' ,
		RP_LEFT = 'J', RP_RIGHT = 'L', RP_ROTATE_CLOCK_WISE = 'K', RP_ROTATE_COUNTER_CLOCK_WISE = 'I', RP_DROP = 'M',ESC= 27};

	enum class ShapeType { I = 1, O, T, S, Z, J, L };

	enum class PlayerType{ LEFT_PLAYER= 1, RIGHT_PLAYER=2};


	static constexpr int GAME_WIDTH = 12; 
	static constexpr int GAME_HEIGHT = 18; 

	

	static const int COLORS[]; 
	static constexpr int  NUM_OF_COLORS = 8; 
	static constexpr int NUM_OF_SHAPES = 7; 

	static constexpr int MIN_X_LEFT_BOARD = 0;
	static constexpr int MIN_Y_LEFT_BOARD = 5;
	static constexpr int MIN_X_RIGHT_BOARD = 50;
	static constexpr int MIN_Y_RIGHT_BOARD = 5;

	static constexpr int NUM_OF_PLAYERS = 2; 
};

