#pragma once

/**********************************************************************
Class: gameConfig

Description:
	Holds configuration constants and enums for the Tetris game.
**********************************************************************/
class gameConfig
{
public: 
	enum class LeftKeys { LEFT = 'A', RIGHT = 'D', ROTATE_CLOCK_WISE = 'S', ROTATE_COUNTER_CLOCK_WISE = 'W', DROP = 'X'};

	enum class RightKeys {LEFT = 'J', RIGHT = 'L', ROTATE_CLOCK_WISE = 'K', ROTATE_COUNTER_CLOCK_WISE = 'I', DROP = 'M'};

	enum class ShapeType { I = 1, O, T, S, Z, J, L};

	enum class PlayerType{ LEFT_PLAYER= 1, RIGHT_PLAYER=2};

	enum class Score{ SINGLE_LINE_CLEAR= 100, DOUBLE_LINE_CLEAR=300, TRIPLE_LINE_CLEAR=500, TETRIS_LINE_CLEAR=800};


	enum class GameStatus { Running, Paused, NewGame, Ended, Finished, Menu, MenuWithoutColors}; // Ended is for if the program is over, Finished is for if the current game is over

	enum class Difficulty { BEST = 'a', GOOD = 'b', NOVICE = 'c' };


	static constexpr int ESC = 27;
	static constexpr int GAME_WIDTH = 12; 
	static constexpr int GAME_HEIGHT = 18; 
	static constexpr int NUM_OF_PLAYERS = 2;
	

	static const unsigned short COLORS[]; 
	static constexpr int  NUM_OF_COLORS = 9; 
	static constexpr int NUM_OF_SHAPES = 7; 
	
	static constexpr int MIN_X_LEFT_BOARD = 1;
	static constexpr int MIN_Y_LEFT_BOARD = 1;
	static constexpr int MIN_X_RIGHT_BOARD = 40;
	static constexpr int MIN_Y_RIGHT_BOARD = 1;

	static constexpr int MAX_X_LEFT_BOARD = 0 + GAME_WIDTH + 2;
	static constexpr int MAX_Y_LEFT_BOARD = 1 + GAME_HEIGHT + 2;
	static constexpr int MAX_X_RIGHT_BOARD = 40 + GAME_WIDTH + 2;
	static constexpr int MAX_Y_RIGHT_BOARD = 1 + GAME_HEIGHT + 2;
	
	static constexpr int WINNDER_ANNOUNCEMENT_POS_X = 20; 
	static constexpr int WINNDER_ANNOUNCEMENT_POS_Y = 12;
	
};

