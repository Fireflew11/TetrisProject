#pragma once

#include <iostream>
#include"Shape.h" 
#include "gameConfig.h"

class Shape; 

using namespace std;

class Board
{
	Cube board_game[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]; 
	int startingX; 
	Shape* curShape;
	int startingY; 

public:
	void display_board(const int startingX);
	void insert_Shape(const Shape& shape); 
	Board(int starting_X=0, int starting_Y=0);
	Shape* getCurShape() const;
	void setCurShape(Shape* curShape);
	const Cube(&getBoardGame() const)[18][12] ;
	bool check_valid_move(const Shape& shape) const;

	void updateBoard(const Shape& shape);


private: 
	void print_Line(); 
};

