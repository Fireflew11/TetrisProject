#pragma once

#include <iostream>
#include"Shape.h" 
#include "gameConfig.h"
class Shape; 
using namespace std;

/**********************
* The Board class represents the game board where shapes are placed.
***********************/

class Board
{
	Cube board_game[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH];
	int startingX;
	int startingY; 
	bool useColors;

public:
	void display_board();
	Board(int starting_X=0, int starting_Y=0,  bool useColors= true);
	const Cube(&getBoardGame() const)[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH];
	bool check_valid_move(const Shape& shape) const;
	void updateBoard(const Shape& shape);
	void clearLine(int index_line); 
	bool IsLineFull(int index_line);
	int clearFullLines();
	void implementShapeToBoard(const Shape& shape);
	void drawBoardCubes();
	void setUseColor(bool useColors);

private: 
	void print_Line(); 
};

