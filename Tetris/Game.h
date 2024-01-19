#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class player; 

class Game
{
	Player players[gameConfig::NUM_OF_PLAYERS];
	gameConfig::GameStatus status;
	bool useColors; 

public: 

	void keyChoice(gameConfig::LeftKeys key, Shape& shape);
	void keyChoice(gameConfig::RightKeys key , Shape& shape);
	void checkKeyChoice(int keyPressed, Shape& Leftshape, Shape& RightShape);
	Game(bool useColors=true, gameConfig::GameStatus status= gameConfig::GameStatus::Running);
	void Print_Menu(); 
	void Present_instructionsand_keys(); 
	void GameLoop();
	bool getIsGamePaused();
	void setIsGamePaused(bool isGamePaused);
	void startGame();
	void printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn);
	void printSeparator();
	bool isGameOver();
	void announceWinner();
	bool checkGameValidity(const Shape& ShapePlayer1, const Shape& cShapePlayer2, bool& isGameOver);
};

