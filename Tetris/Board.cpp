﻿#include "Board.h"
#include "gameConfig.h"

/**********************************************************************
Function name: display_board
Input: --
Output:--
Function:Displays the game board on the console.The function prints the board structure, including inactive and active cubes,to the console.
**********************************************************************/
void Board::display_board() 
{
	int i, j;
	gotoxy(startingX-1, 0);
	Board::print_Line();
	gotoxy(startingX-1, 1);
	for (i = 1; i < gameConfig::GAME_HEIGHT + 2; i++)
	{
		cout << "|";
		for (j = 1; j < gameConfig::GAME_WIDTH + 1; j++)
			cout << " ";
		cout << "|" << endl;
		gotoxy(startingX-1, i);
	}
	Board::print_Line();
	drawBoardCubes();
}

/**********************************************************************
Function name:Constructor Board
Input:int starting_X, int starting_Y, bool useColors
Function:Constructor for the Board class.
**********************************************************************/
Board::Board(int starting_X, int starting_Y, bool useColors):startingX(starting_X),startingY(starting_Y), useColors(useColors)
{
	for (int i = 0; i <(int)gameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < (int)gameConfig::GAME_WIDTH; j++)
		{
			board_game[i][j].set_coord(startingX + j, startingY + i); 
			board_game[i][j].setIsActive(false); 
			board_game[i][j].setColor(gameConfig::COLORS[0]);//COLORS[0] is black,the default colors for inactive cubes. 
		}
	}
}

/**********************************************************************
Function name::getBoardGame
Input: --
Output: const Cube(&)[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH] 
Function:Gets a reference to the 2D array representing the board.
**********************************************************************/
const Cube(&Board::getBoardGame() const)[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]
{
	return board_game;
}


/**********************************************************************
Function name:check_valid_move
Input: const Shape& shape
Output: bool
Function:Checks if a given shape can make a valid move on the board. 
The function verifies if the shape's position and orientation are within the bounds of the board and if it collides with any active cubes.
**********************************************************************/
/*
bool Board::check_valid_move(const Shape& shape) const
{
	for (int i = 0; i < 4; i++)
	{
		int x = shape.get_cubes()[i].get_X(); 
		int y = shape.get_cubes()[i].get_Y();   
		if ((x > gameConfig::GAME_WIDTH + startingX) || (x <= startingX))
			return false;
		if (y >= gameConfig::GAME_HEIGHT + 1 || y < 1)
			return false;
		if (board_game[y - 1][(x - startingX - 1)].getIsActive() == true) 
			
			return false;

	}
	return true;

}
*/

/**********************************************************************
Function name:clearLine
Input: int index_line
Output: --
Function:Clears a specific line on the board.
**********************************************************************/
void Board::clearLine(int index_line)
{
	for (int i = index_line; i > 0; i--)
	{
		for (int j = 0; j < gameConfig::GAME_WIDTH; j++)
		{
			board_game[i][j].setIsActive(board_game[i - 1][j].getIsActive()); 
		}
	}
	for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
	{
		board_game[0][i].setIsActive(false); 
	}
}

/**********************************************************************
Function name:IsLineFull
Input: int index_line
Output: bool
Function:Checks if a specific line on the board is full.
**********************************************************************/
bool Board::IsLineFull(int index_line)
{
	for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
	{
		if (board_game[index_line][i].getIsActive() == false)
			return false; 
	}
	return true; 
}

/**********************************************************************
Function name:clearFullLines
Input: --
Output: int 
Function:Clears any full lines on the board and updates the board accordinglyd.
The function returns the total number of lines cleared during this process.
**********************************************************************/
int  Board::clearFullLines()
{
	int numClearedLines = 0;
	for (int i = 0; i < gameConfig::GAME_HEIGHT; i++)
	{
		if (IsLineFull(i))
		{
			numClearedLines++; 
			clearLine(i);  
		}
	}
	if (numClearedLines > 0)
		drawBoardCubes();

	return numClearedLines; 
}

/**********************************************************************
Function name:implementShapeToBoard
Input:const Shape& shape
Output:--
Function:The function implements the given shape on the game board 
by updating the state of the board_game array based on the shape's cubes' positions and color.
**********************************************************************/
/*
void Board::implementShapeToBoard(const Shape& shape) 
{
	for (int i = 0; i < 4; i++)
	{
		board_game[shape.get_cubes()[i].get_Y() - 1][shape.get_cubes()[i].get_X() - startingX - 1].setIsActive(true);
		board_game[shape.get_cubes()[i].get_Y() - 1][shape.get_cubes()[i].get_X() - startingX - 1].setColor(shape.getColor());
	}
	
}
*/


/**********************************************************************
Function name:drawBoardCubes
Input: --
Output: --
Function::The function Draws the cubes of the game board based on the current state of the board_game array.
**********************************************************************/
void Board::drawBoardCubes()
{
	for (int i = 0; i < gameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < gameConfig::GAME_WIDTH; j++)
			board_game[i][j].drawCube(board_game[i][j].getIsActive(),useColors);
	}
}

/**********************************************************************
Function name:setUseColor
Input: bool useColors
Output: --
Function: Sets the useColors property of the board to the provided boolean value.
**********************************************************************/
void  Board::setUseColor(bool useColors)
{
	this->useColors = useColors; 
}


void Board::print_Line()
{
	for (int i = 0; i < gameConfig::GAME_WIDTH + 2; i++)
	{
		cout << "-";
	}
	cout << endl;
}

bool Board::isValidPosition(const int x, const int y)const 
{
	if ((x > gameConfig::GAME_WIDTH + startingX) || (x <= startingX))
		return false;
	if (y >= gameConfig::GAME_HEIGHT + 1 || y < 1)
		return false;
	if (board_game[y -startingY][(x - startingX )].getIsActive() == true)
		return false; 
	return true; 
}



void Board::set_cube_active_in_board_game(const int x, const int y) 
{
	board_game[y - startingY][x - startingX].setIsActive(false); 
}


const int Board::getStartingX()const
{
	return startingX; 
}
const int Board::getStartingY() const
{
	return startingY; 
}

Cube(&Board::get_to_set_BoardGame())[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]
{
	return board_game;
}

bool Board::isValidExplosion(const int x, const int y)const
{
	if ((x > gameConfig::GAME_WIDTH + startingX) || (x < startingX))
		return false;
	if (y >= gameConfig::GAME_HEIGHT + startingY || y < startingY)
		return false;
	return true; 
}

bool Board::isValidYExplosion(const int y)const
{
	if (y >= gameConfig::GAME_HEIGHT + startingY || y < startingY)
		return false;
	return true; 
}

bool Board::isValidXExplosion(const int x)const
{
	if ((x > gameConfig::GAME_WIDTH + startingX) || (x < startingX))
		return false;
	return true; 
}


void Board::moveCubesDownAfterExplosion(int startingXExplosion, int startingYExplosion, int rangeX, int rangeY)
{
	for (int y = startingYExplosion; y >= startingY; y--)
	{
		for (int x = startingXExplosion; x <= startingXExplosion + rangeX; x++)
		{
			board_game[y - startingY + rangeY][x-startingX+rangeX].setIsActive(board_game[y-startingY][x-startingX].getIsActive());
			board_game[y - startingY][x - startingX].setIsActive(false); 
		}
	}
	//(board_game[y - 1][(x - startingX - 1)].getIsActive() == true)
}