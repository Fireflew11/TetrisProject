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
    Represents a Tetris shape, managing its properties and movement.

Member Variables:
    - type: The type of the shape (gameConfig::ShapeType).
    - orientation: The current orientation of the shape.
    - coordinates: An array of Cube objects representing the shape's cubes.
    - useColors: A boolean indicating whether colors are used.
**********************************************************************/
class Shape
{
	Cube cubes[4];
	int color; 
	gameConfig::ShapeType type; 
	bool useColors;

public: 

	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i,  Cube cube); 
	void drawShape(bool isActive = true) const;
	int getRowsAmount() const;
	void rotate_CounterClock_wise(const Board& board);
	void rotate_Clock_wise(const Board& board);
	void move_Left(const Board& board);
	void move_Right(const Board& board); 
	bool continueMovingDown(const Board& board);
	void drop(const Board& board);
	int getColor() const;
	const gameConfig::ShapeType getShapeType(); 
	Shape(gameConfig::PlayerType playerType, bool useColors=true);





   
    
};

#endif //SHAPE_H