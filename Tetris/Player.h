#pragma once
#include <cstdlib>
#include <conio.h>
#include "Shape.h"
#include "Board.h"
#include "gameConfig.h"
using std::cout;
using std::cin;
using std::endl;
class Shape; 
/**********************************************************************
The Player class represents a player in the game. It serves as a base
class for both human and computer players.

Attributes:
- playerType: The type of player (left player or right player).
- playerBoard: The game board associated with the player.
- score: The player's score in the game.
- isWinner: A flag indicating whether the player has won the game.
- startingX: The starting X coordinate of the player's board.
- startingY: The starting Y coordinate of the player's board.

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
	Player(gameConfig::PlayerType);
	Board& getPlayerBoard(); 
	void updateScore(int numClearedLines);
	void setIsWinner(bool isWinner); 
	const bool getIsWinner()const; 
	const int getScore();
	const gameConfig::PlayerType getPlayerType() const; 
	virtual void decideMove(Shape& shape, char key) = 0;
	const int getStartingX() const; 
	const int getStartingY() const; 
	void displayScore();
	virtual ~Player() {};
};

