#ifndef SHAPE_H
#define SHAPE_H
#pragma once
#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "gameConfig.h"
enum Direction { RIGHT = 1, LEFT };
class Cube; 
class Board; 
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