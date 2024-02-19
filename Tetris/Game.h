#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>
#include "Human.h"
#include "Computer.h"
using std::cout;
using std::cin;
using std::endl;
using std::string; 
class player; 


/**********************************************************************
The Game class represents the main game engine responsible for managing
the flow of the Tetris-like game. It controls the game loop, player
interactions, shape generation, and game status.

Attributes:
- players: An array of pointers to Player objects representing the
		   players participating in the game.
- status: An enumeration representing the current status of the game,
- useColors: A boolean indicating whether to use colors in the game
			 interface.
- currentShapeLeftPlayer: A pointer to the current shape for the left
						  player.
- currentShapeRightPlayer: A pointer to the current shape for the right
						   player.

Additional enum class:
- MenuOption: Represents the menu options available to the player.

**********************************************************************/

class Game
{
	Player *players[gameConfig::NUM_OF_PLAYERS];
	gameConfig::GameStatus status;
	bool useColors; 
	Shape* currentShapeLeftPlayer;
	Shape* currentShapeRightPlayer;
	
public: 
	enum class MenuOption { START_NEW_GAME_PVP = '1', START_NEW_GAME_PVC = '2', START_NEW_GAME_CVC = '3', CONTINUE_PAUSED_GAME = '4', START_NEW_GAME_WITHOUT_COLORS = '5', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };

	Game(bool useColors=true, gameConfig::GameStatus status= gameConfig::GameStatus::Menu,Shape* ShapeLeftPlayer= nullptr, Shape* ShapeRightPlayer= nullptr);
	void startGame();
private:
	void GameLoop();
	void Print_Menu();
	void Present_instructionsand_keys();
	void printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn);
	void printSeparator();
	bool isMaxHeight();
	void announceWinner();
	void initializePlayers(char pick, gameConfig::Difficulty level = gameConfig::Difficulty::BEST);
	bool checkGameValidity(bool& isGameOver);
	bool handleInput();
	bool checkGameConditions(Player& player, Shape*& shape, bool& isGameOver);
	void moveShapesDown(Shape* shapeLeft, Shape* shapeRight, bool& movedDownPlayer1, bool& movedDownPlayer2);
	Shape* createRandomShape(const Player& player);
	void ResetIfComputer(Player* player);
	bool isBombAppearance();
	void Print_No_Colors_Menu();
	void Print_Computer_Level_Menu();
	gameConfig::Difficulty Computer_Level_Selection();
	void set_UseColor_and_display_board(bool useColors);


};

