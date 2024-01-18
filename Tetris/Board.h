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
	int startingY; 
	bool useColors= true;

public:
	void display_board(const int startingX);
	Board(int starting_X=0, int starting_Y=0,  bool useColors= true);
	void setStartingX(const int x);
	void setStartingY(const int y);

	
	
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

