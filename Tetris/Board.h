#pragma once

#include <iostream>
#include"Shape.h" 
#include "gameConfig.h"
class Shape; 
using namespace std;

/**********************************************************************
Class: Board

Description:
	Represents the game board in Tetris, managing a grid of cubes and handling operations such as clearing lines.

Member Variables:
	- boardGame: 2D array of Cube objects representing the game board.
	- useColors: Boolean indicating whether colors are used in the console output.
	- startingX,startingY:presents the initial X-coordinate(horizontal position) and the initial Y-coordinate(vertical position). 
**********************************************************************/
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
	//bool check_valid_move(const Shape& shape) const;
	void clearLine(int index_line); 
	bool IsLineFull(int index_line);
	int clearFullLines();
	//void implementShapeToBoard(const Shape& shape);
	void drawBoardCubes();
	void setUseColor(bool useColors);

	bool isValidPosition(const int x, const int y)const;
	bool isValidExplosion(const int x, const int y)const;
	void set_cube_active_in_board_game(const int x, const int y);
	const int getStartingX()const; 
	const int getStartingY() const; 
	int getMaxHeight();
	int getHolesAmount();
	Cube(&get_to_set_BoardGame())[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH];
	double calculateSmoothness();
	int getMaxHeight(int col);

private: 
	void print_Line(); 
};

