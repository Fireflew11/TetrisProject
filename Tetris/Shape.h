#ifndef SHAPE_H
#define SHAPE_H

#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "gameConfig.h"
class Cube; 
class Board; 


class Shape
{
	int color;
	bool useColors;
	int startingX; 
	int StartingY; 
public: 


	virtual void drawShape(bool isActive = true) const=0;
	virtual void move_Left(const Board& board)=0;
	virtual void move_Right(const Board& board)=0;
	virtual bool continueMovingDown(const Board& board)=0;
	virtual void implementShapeToBoard(Board& board) = 0;
	virtual bool check_valid_move(const Board& board) const=0;
	int getColor() const;
	bool getUseColors() const; 
	void drop(const Board& board);


	Shape(int color, bool useColors, int startingX, int StartingY); 


	Shape(gameConfig::PlayerType playerType, bool useColors=true);

    
};

#endif //SHAPE_H