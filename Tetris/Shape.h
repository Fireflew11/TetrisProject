#ifndef SHAPE_H
#define SHAPE_H

#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "gameConfig.h"
class Cube; 
class Board; 
/**********************************************************************
Class: Shape

Description:
	Represents a generic shape in the game. This is an abstract base class that defines common functionality for all shapes in the game.

Member Variables:
	- color: The color of the shape.
	- useColors: Boolean indicating whether colors are used in the console output.
	- startingX, StartingY: The initial X and Y coordinates (horizontal and vertical position) of the shape.
	- differentRotations: The number of different possible rotations for the shape.
**********************************************************************/

class Shape
{
	int color;
	bool useColors;
	int startingX; 
	int StartingY; 
	int differentRotations;

public: 
	virtual void drawShape(bool isActive = true) const=0;
	virtual bool move_Left(const Board& board)=0;
	virtual bool move_Right(const Board& board)=0;
	virtual bool continueMovingDown(const Board& board)=0;
	virtual void implementShapeToBoard(Board& board, bool isDraw) const = 0 ;
	virtual bool check_valid_move(const Board& board) const=0;

	int getColor() const;
	bool getUseColors() const; 
	bool drop(const Board& board);

	virtual bool rotate_CounterClock_wise(const Board& board)=0;
	virtual bool rotate_Clock_wise(const Board& board) =0;
	virtual Shape* clone() const = 0;
	virtual int getX() const = 0;
	int getDifferentRotations() const;
	Shape(int color, bool useColors, int startingX, int StartingY, int differentRotations); 
	virtual ~Shape() {};  
};

#endif //SHAPE_H