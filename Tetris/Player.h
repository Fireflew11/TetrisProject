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


	using MoveFunction = void (Shape::*)(const Board&);  // Directly define the type of moveFunctions
	MoveFunction moveFunctions[128];  // Use the MoveFunction type directly


	int score; 
	bool isWinner; 


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
};

