#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>
#include "Human.h"
#include "Computer.h"
using namespace std;
class player; 
enum class MenuOption { PVP = '1', PVC = '3', CONTINUE_PAUSED_GAME = '2', CVC = '4', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };
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
	Player *players[gameConfig::NUM_OF_PLAYERS];
	gameConfig::GameStatus status;
	bool useColors; 

public: 

	/*
	void keyChoice(gameConfig::LeftKeys key, Shape& shape);
	void keyChoice(gameConfig::RightKeys key , Shape& shape);
	void checkKeyChoice(int keyPressed, Shape& Leftshape, Shape& RightShape);
	*/
	Game(bool useColors=true, gameConfig::GameStatus status= gameConfig::GameStatus::Running);
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
	bool checkGameValidity(const Shape& ShapePlayer1, const Shape& ShapePlayer2, bool& isGameOver);
	bool handleInput(Shape& curShapePlayer1, Shape& curShapePlayer2);
	bool checkGameConditions(Player& player, Shape& shape, bool& isGameOver);
	void initializePlayers(char pick);
};

