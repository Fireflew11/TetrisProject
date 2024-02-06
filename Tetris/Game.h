#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>
using namespace std;
class player; 

/**********************************************************************
Class: Game

Description:
    Represents the Tetris game and manages the game loop, player interactions, and game status.

Member Variables:
    - players: An array of Player objects representing the players in the game.
    - status: The current status of the game (gameConfig::GameStatus).
    - useColors: A boolean indicating whether colors are used in the game.

**********************************************************************/
class Game
{
	Player players[gameConfig::NUM_OF_PLAYERS];
	gameConfig::GameStatus status;
	bool useColors; 


	Shape* currentShapeLeftPlayer;
	Shape* currentShapeRightPlayer;
	

public: 


	void keyChoice(gameConfig::LeftKeys key);
	void keyChoice(gameConfig::RightKeys key);
	void checkKeyChoice(int keyPressed);

	Game(bool useColors=true, gameConfig::GameStatus status= gameConfig::GameStatus::Running,Shape* ShapeLeftPlayer= nullptr, Shape* ShapeRightPlayer= nullptr);
	void Print_Menu(); 
	void Present_instructionsand_keys(); 
	void GameLoop();
	bool getIsGamePaused();
	void setIsGamePaused(bool isGamePaused);
	void startGame();
	void printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn);
	void printSeparator();
	bool isMaxHeight();
	void announceWinner();
	bool checkGameValidity(bool& isGameOver);
	bool handleInput();
	bool checkGameConditions(Player& player, Shape*& shape, bool& isGameOver);

	Shape* createRandomShape(const Player& player);
	bool isBombAppearance();
};

