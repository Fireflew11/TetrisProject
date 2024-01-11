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
	int playerType; 
	Board playerBoard; 
	//int score; 
public: 
	//void keyChoice(); 
	Player();
	Board& getPlayerBoard();
};

