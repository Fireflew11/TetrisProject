#pragma once

#include <cstdlib>
#include <conio.h>
#include "Shape.h"
#include "Board.h"
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
public: 
	//Player(int startingX, int startingY);
	Board& getPlayerBoard();
	//void GameLoop();
	void initializeMoveFunctions();
	void updateScore(int numClearedLines);

	Player(gameConfig::PlayerType); 
};

