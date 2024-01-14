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
	int playerType; 
	Board playerBoard; 
	int score; 
public: 
	Player(int startingX, int startingY);
	Board& getPlayerBoard();
	void GameLoop();
	void updateScore(int numClearedLines); 
};

