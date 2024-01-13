#pragma once

#include <iostream>
#include"Shape.h" 
#include "gameConfig.h"


class Shape; 

using namespace std;

class Board
{
	Cube board_game[gameConfig::GAME_WIDTH][gameConfig::GAME_HEIGHT]; 
	int startingX; 
	Shape* curShape;
	int startingY; 

public:
	void display_board(const int startingX);
	void insert_Shape(const Shape& shape); 
	Board(int starting_X=0, int starting_Y=0);
	void setStartingX(const int x);
	void setStartingY(const int y);

	Shape* getCurShape() const;
	void setCurShape(Shape* curShape);
	const Cube(&getBoardGame() const)[12][18];

	bool check_valid_move(const Shape& shape) const;
	void updateBoard(const Shape& shape);

	void clearLine(int index_line); 
	bool IsLineFull(int index_line);
	void clearFullLines();
	bool isGameOver(); 
	void implementShapeToBoard(const Shape& shape);


private: 
	void print_Line(); 
};

