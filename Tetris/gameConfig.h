#pragma once
class gameConfig
{
public: 
	enum class LeftKeys { LEFT = 'A', RIGHT = 'D', ROTATE_CLOCK_WISE = 'S', ROTATE_COUNTER_CLOCK_WISE = 'W', DROP = 'X' , ESC= 27};

	enum class RightKeys {LEFT = 'J', RIGHT = 'L', ROTATE_CLOCK_WISE = 'K', ROTATE_COUNTER_CLOCK_WISE = 'I', DROP = 'M', ESC = 27 };

	enum class ShapeType { I = 1, O, T, S, Z, J, L };

	enum class PlayerType{ LEFT_PLAYER= 1, RIGHT_PLAYER=2};

	enum class Score{ SINGLE_LINE_CLEAR= 100, DOUBLE_LINE_CLEAR=300, TRIPLE_LINE_CLEAR=500, TETRIS_LINE_CLEAR=800};

	enum class MenuOption { START_NEW_GAME = '1', START_NEW_GAME_WITHOUT_COLORS = '3', CONTINUE_PAUSED_GAME = '2', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };

	enum class GameStatus { Running, Paused, NewGame, Ended,Finish };




	static constexpr int ESC = 27;
	static constexpr int GAME_WIDTH = 12; 
	static constexpr int GAME_HEIGHT = 18; 
	static constexpr int NUM_OF_PLAYERS = 2;
	

	static const int COLORS[]; 
	static constexpr int  NUM_OF_COLORS = 8; 
	static constexpr int NUM_OF_SHAPES = 7; 

	static constexpr int MIN_X_LEFT_BOARD = 0;
	static constexpr int MIN_Y_LEFT_BOARD = 1;
	static constexpr int MIN_X_RIGHT_BOARD = 50;
	static constexpr int MIN_Y_RIGHT_BOARD = 1;

	static constexpr int MAX_X_LEFT_BOARD = 0 + GAME_WIDTH * 2 + 2;
	static constexpr int MAX_Y_LEFT_BOARD = 1;
	static constexpr int MAX_X_RIGHT_BOARD = 50 + GAME_WIDTH * 2 + 2;
	static constexpr int MAX_Y_RIGHT_BOARD = 1;
	
	static constexpr int MIDDLE_SCREEN_HEIGHT = 40; 
	static constexpr int MIDDLE_SCREEN_WIDTH = 12;
	
};

