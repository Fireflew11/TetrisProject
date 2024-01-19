#pragma once

#include <cstdlib>
#include <conio.h>
#include "Shape.h"
#include "Board.h"
#include "gameConfig.h"
using namespace std;
class Shape; 

class Player
{
private: 
	gameConfig::PlayerType playerType; 

	Board playerBoard;
	int score; 
	bool isWinner; 
	int startingX;


public: 
	//Player(int startingX, int startingY);
	Board& getPlayerBoard();
	//void GameLoop();
	void initializeMoveFunctions();
	void updateScore(int numClearedLines);
	void displayScore();
	void setIsWinner(bool isWinner); 
	bool getIsWinner(); 
	Player(gameConfig::PlayerType,int score=0, bool isWinner=false); 
	const int getScore();
};

