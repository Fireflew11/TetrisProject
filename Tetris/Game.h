#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>
#include "Human.h"
#include "Computer.h"
using namespace std;
class player; 
//enum class MenuOption { PVP = '1', PVC = '3', CONTINUE_PAUSED_GAME = '2', CVC = '4', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };
enum class MenuOption { START_NEW_GAME_PVP = '1', START_NEW_GAME_PVC = '2', START_NEW_GAME_CVC='3', CONTINUE_PAUSED_GAME = '4', START_NEW_GAME_WITHOUT_COLORS='5', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };
//enum class MenuOption { START_NEW_GAME_PVP = '1', START_NEW_GAME_WITHOUT_COLORS = '3', CONTINUE_PAUSED_GAME = '2', PRESENT_INSTRUCTIONS = '8', EXIT = '9' };
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


	Shape* currentShapeLeftPlayer;
	Shape* currentShapeRightPlayer;
	

public: 


	/*
	void keyChoice(gameConfig::LeftKeys key);
	void keyChoice(gameConfig::RightKeys key);
	void checkKeyChoice(int keyPressed);
	*/

	Game(bool useColors=true, gameConfig::GameStatus status= gameConfig::GameStatus::Menu,Shape* ShapeLeftPlayer= nullptr, Shape* ShapeRightPlayer= nullptr);
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

	void initializePlayers(char pick, gameConfig::ComputerLevel level = gameConfig::ComputerLevel::BEST);



	bool checkGameValidity(bool& isGameOver);
	bool handleInput();
	bool handleHuman(Player* player);
	bool handleComputer(Player* player);
	bool checkGameConditions(Player& player, Shape*& shape, bool& isGameOver);

	Shape* createRandomShape(const Player& player);
	bool isBombAppearance();
	void Print_No_Colors_Menu();
	void Print_Computer_Level_Menu();
	gameConfig::ComputerLevel Computer_Level_Selection();
	void startGame1();
	void startGame2();
};

