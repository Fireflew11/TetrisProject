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
	virtual bool move_Left(const Board& board)=0;
	virtual bool move_Right(const Board& board)=0;
	virtual bool continueMovingDown(const Board& board)=0;
	virtual void implementShapeToBoard(Board& board) = 0;
	virtual bool check_valid_move(const Board& board) const=0;

	int getColor() const;
	bool getUseColors() const; 
	bool drop(const Board& board);

	virtual bool rotate_CounterClock_wise(const Board& board)=0;
	virtual bool rotate_Clock_wise(const Board& board) =0;
	virtual Shape* clone() const = 0;
	virtual int getX() const = 0;

	Shape(int color, bool useColors, int startingX, int StartingY); 



    
};

#endif //SHAPE_H