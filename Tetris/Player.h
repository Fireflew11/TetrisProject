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
    Represents a player in the Tetris game, managing player-specific data and actions.

Member Variables:
    - playerType: The type of the player (gameConfig::PlayerType).
    - score: An integer representing the player's current score.
    - isWinner: A boolean indicating whether the player is the winner.
    - playerBoard: An instance of the Board class representing the player's game board.

**********************************************************************/
class Player
{
public:
	using ShapeFunctionType = bool (Shape::*)(const Board&);
private: 
	gameConfig::PlayerType playerType; 
	Board playerBoard;
	int score; 
	bool isWinner; 
	int startingX;
	int startingY; 


public: 

	Board& getPlayerBoard(); 
	void updateScore(int numClearedLines);
	void displayScore();
	void setIsWinner(bool isWinner); 
	const bool getIsWinner()const; 
	Player(gameConfig::PlayerType); 
	const int getScore();
	const gameConfig::PlayerType getPlayerType() const; 
	virtual ~Player() = default;
	virtual void decideMove(Shape& shape, char key) = 0;
	const int getStartingX() const; 
	const int getStartingY() const; 
};

