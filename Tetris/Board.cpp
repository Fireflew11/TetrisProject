﻿#include "Board.h"
#include "gameConfig.h"
#include "ComplexShape.h"

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

	return numClearedLines; 
}

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

/**********************************************************************
Function name:print_Line
Input: --
Output: --
Function:Prints a line of dashes to the console, used for visual separation in the board display.
**********************************************************************/
void Board::print_Line()
{
	for (int i = 0; i < gameConfig::GAME_WIDTH + 2; i++)
	{
		cout << "-";
	}
	cout << endl;
}

/**********************************************************************
Function name: isValidPosition
Input: const int x, const int y
Output: bool
Function: Checks if a given position (x, y) is a valid position on the board, considering the board boundaries and whether the cell is occupied.
**********************************************************************/
bool Board::isValidPosition(const int x, const int y)const 
{
	if ((x >= gameConfig::GAME_WIDTH + startingX) || (x < startingX))
		return false;
	if (y >= gameConfig::GAME_HEIGHT + startingY || y < startingY)
		return false;
	if (board_game[y -startingY][(x - startingX )].getIsActive() == true)
		return false; 
	return true; 
}


/**********************************************************************
Function name: set_cube_active_in_board_game
Input: const int x, const int y
Output: --
Function: Sets a cube at position (x, y) on the board to be inactive.
**********************************************************************/
void Board::set_cube_active_in_board_game(const int x, const int y) 
{
	board_game[y - startingY][x - startingX].setIsActive(false); 
}

/**********************************************************************
Function name: getStartingX
Input: --
Output: const int
Function: Returns the starting X coordinate of the board.
**********************************************************************/
const int Board::getStartingX()const
{
	return startingX; 
}

/**********************************************************************
Function name: getStartingY
Input: --
Output: const int
Function: Returns the starting Y coordinate of the board.
**********************************************************************/
const int Board::getStartingY() const
{
	return startingY; 
}

/**********************************************************************
Function name: get_to_set_BoardGame
Input: --
Output: Cube(&)[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]
Function: Returns a reference to the 2D array representing the game board.
**********************************************************************/
Cube(&Board::get_to_set_BoardGame())[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]
{
	return board_game;
}

/**********************************************************************
Function name: isValidExplosion
Input: const int x, const int y
Output: bool
Function: Checks if a given position (x, y) is a valid position for an explosion on the board, considering the board boundaries.
**********************************************************************/
bool Board::isValidExplosion(const int x, const int y)const
{
	if ((x >= gameConfig::GAME_WIDTH + startingX) || (x < startingX))
		return false;
	if (y >= gameConfig::GAME_HEIGHT + startingY || y < startingY)
		return false;
	return true; 
}

/**********************************************************************
Function name: isValidYExplosion
Input: const int y
Output: bool
Function:Checks if a given Y coordinate is a valid position for an explosion on the board, considering the board boundaries.
**********************************************************************/
bool Board::isValidYExplosion(const int y)const
{
	if (y >= gameConfig::GAME_HEIGHT + startingY || y < startingY)
		return false;
	return true; 
}

/**********************************************************************
Function name: isValidXExplosion
Input: const int x
Output: bool
Function: Checks if a given X coordinate is a valid position for an explosion on the board, considering the board boundaries.
**********************************************************************/
bool Board::isValidXExplosion(const int x)const
{
	if ((x >= gameConfig::GAME_WIDTH + startingX) || (x < startingX))
		return false;
	return true; 
}

/**********************************************************************
Function name: moveCubesDownAfterExplosion
Input: int startingXExplosion, int startingYExplosion, int rangeX, int rangeY
Output: --
Function: Moves cubes down after an explosion on the board, adjusting their positions based on the explosion's parameters.
**********************************************************************/
void Board::moveCubesDownAfterExplosion(int startingXExplosion, int startingYExplosion, int rangeX, int rangeY)
{
	for (int y = startingYExplosion- startingY; y >= startingY; y--)
	{
		for (int x = startingXExplosion; x < startingXExplosion + rangeX; x++)
		{
			board_game[y - startingY + rangeY][x - startingX].setIsActive(board_game[y-startingY][x-startingX].getIsActive());
			board_game[y - startingY + rangeY][x - startingX].setColor(board_game[y - startingY][x - startingX].getColor());
			board_game[y - startingY][x - startingX].setIsActive(false); 

		}
		
	}

}

/**********************************************************************
Function name: getMaxHeight
Input: --
Output: int
Function: Determines the maximum height of active cubes on the board.
**********************************************************************/
int Board::getMaxHeight()
{
	for (int i = 0; i < gameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < gameConfig::GAME_WIDTH; j++)
		{
			if (board_game[i][j].getIsActive())
				return (gameConfig::GAME_HEIGHT - i);
		}
	}
	return 0;
}

/**********************************************************************
Function name: getMaxHeightOfcol
Input: int col
Output: int
Function: Determines the maximum height of active cubes in a specific column of the board.
**********************************************************************/
int Board::getMaxHeightOfcol(int col)
{
	int max_height = 0;
	for (int row = 0; row < gameConfig::GAME_HEIGHT; ++row)
	{
		if (board_game[row][col].getIsActive()) {
			max_height = gameConfig::GAME_HEIGHT - row;
			break;
		}
	}
	return max_height;
}

/**********************************************************************
Function name: getHolesAmount
Input: --
Output: int
Function: Calculates the number of holes (empty spaces beneath active cubes) on the board.
**********************************************************************/
int Board::getHolesAmount() 
{
	int holes = 0;

	// Iterate through each column
	for (int col = 0; col < gameConfig::GAME_WIDTH; col++) {
		bool activeFound = false;  // Flag to indicate if an active cube is found in the column

		// Iterate through each row, starting from the bottom
		for (int row = 0; row < gameConfig::GAME_HEIGHT; row++) {
			// Check if the current cell is active
			if (board_game[row][col].getIsActive()) {
				activeFound = true;  // Set the flag indicating an active cube is found in this column
			}
			else if (!board_game[row][col].getIsActive() && activeFound) {
				holes++;  // Found a hole
			}
		}
	}

	return holes;
}

/**********************************************************************
Function name: calculateSmoothness
Input: --
Output: int
Function: Calculates the smoothness metric of the board, which measures the variation in height between adjacent columns.
**********************************************************************/
int Board::calculateSmoothness()
{
	int smoothness = 0;
	int minForMaxRow = 0;
	for (int col = 0; col < gameConfig::GAME_WIDTH - 1; ++col) 
	{
		int height1 = this->getMaxHeightOfcol(col);
		int height2 = this->getMaxHeightOfcol(col + 1);
		smoothness += std::abs(height1 - height2);
	}

	return smoothness;
}



/**********************************************************************
Function name: fillsWell
Input: Shape* shape
Output: int
Function: Calculates how many parts of a shape "fills well" on the board, i.e., how many cubes of the shape are at the bottom and adjacent to the walls.
**********************************************************************/
int Board::fillsWell(Shape* shape) const 
{
	ComplexShape* newShape = dynamic_cast<ComplexShape*>(shape);
	if (!newShape)
		return 0;
	int filledParts = 0; // Counter for filled parts of the well

	// Iterate through each cube of the shape
	for (int i = 0; i < 4; ++i) {
		int currX = newShape->get_cubes()[i].get_X() - startingX; // Adjust X coordinate
		int currY = newShape->get_cubes()[i].get_Y() - 1;                     // Adjust Y coordinate

		// Check if the cube is against the left or right wall and at the bottom of the board
		if ((currX == 0 || currX == gameConfig::GAME_WIDTH - 1) && currY == gameConfig::GAME_HEIGHT - 1) 
		{
			filledParts++; // Increment the counter for filled parts
		}
	}

	return filledParts;
}