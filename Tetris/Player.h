#pragma once
#include <cstdlib>
#include <conio.h>
#include "Shape.h"
#include "Board.h"
#include "gameConfig.h"
using namespace std;
class Shape; 

/**********************************************************************
Class: Player

Description:
The Player class represents a player in the Tetris-like game, 
managing the player's board, score,and game-related functions.
Each player has a game board, a score that is updated based on the number of cleared lines, and a flag indicating if the player is the winner.

**************************************************************************/
class Player
{
private: 
	gameConfig::PlayerType playerType; 

	Board playerBoard;
	int score; 
	bool isWinner; 
	int startingX;


public: 

	Board& getPlayerBoard(); //צריך לשנות את השם לSET
	void updateScore(int numClearedLines);
	void displayScore();
	void setIsWinner(bool isWinner); 
	const bool getIsWinner()const; 
	Player(gameConfig::PlayerType,int score=0, bool isWinner=false); 
	const int getScore();
};

