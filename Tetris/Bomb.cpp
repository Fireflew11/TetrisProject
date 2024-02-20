#include "Bomb.h"
#include "gameConfig.h"



/**********************************************************************
Function name: Bomb
Input:bool useColors, int startingX, int startingY
Output:--
Function:Constructor for the Bomb class. Initializes a Bomb object with the specified parameters.
**********************************************************************/
Bomb::Bomb(bool useColors, int startingX, int startingY) :Shape(gameConfig::COLORS[8], useColors, startingX, startingY, 1), cube(startingX +(gameConfig::GAME_WIDTH)/2 , startingY, gameConfig::COLORS[8])
{}
const Cube& Bomb::getCube() const
{
	return cube;
}

/**********************************************************************
Function name: clone
Input:--
Output:Shape*: A pointer to a newly created Bomb object, which is a clone of the current Bomb object.
Function:Creates a new Bomb object that is an exact copy of the current Bomb object and returns a pointer to it.
**********************************************************************/
Shape* Bomb::clone() const
{
	return new Bomb(*this);
}


/**********************************************************************
Function name: drawShape
Input:bool isActive
Output:--
Function:Draws the bomb shape on the board, considering whether it is active or not.
**********************************************************************/
void Bomb:: drawShape(bool isActive)const
{
	cube.drawCube(isActive, getUseColors(), '?');
}

/**********************************************************************
Function name: move_Left
Input:const Board& board: The game board.
Output:bool: Indicates whether the move was successful.
Function:Moves the bomb shape one position to the left on the board if the move is valid.
**********************************************************************/
bool Bomb::move_Left(const Board& board)
{
	bool res = false;
	int x = cube.get_X()-1;
	int y = cube.get_Y(); 

	Cube tempCube(x, y, getColor(), true); 
	Bomb temp = *this; 
	temp.cube= tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp; 
		res = true;
	}
	return res;

}

/**********************************************************************
Function name: move_Right
Input:const Board& board: The game board.
Output:bool: Indicates whether the move was successful.
Function:Moves the bomb shape one position to the right on the board if the move is valid.
**********************************************************************/
bool Bomb:: move_Right(const Board& board)
{
	bool res = false;
	int x = cube.get_X() + 1;
	int y = cube.get_Y();

	Cube tempCube(x, y, getColor(), true);
	Bomb temp = *this;
	temp.cube = tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp;
		res = true;
	}
	return res;

}

/**********************************************************************
Function name:continueMovingDown
Input:const Board& board
Output:bool: Indicates whether the bomb successfully continued moving down.
Function:Moves the bomb one step down on the game board if the move is valid.
**********************************************************************/
bool Bomb::continueMovingDown(const Board& board)
{
	Bomb temp = *this;
	int y = cube.get_Y() + 1;
	Cube tempCube(cube.get_X(), y, getColor(), true);
	temp.cube = tempCube; 

	if (temp.check_valid_move(board))
	{
		*this = temp;      // Update the shape
		return true;
	}

	return false;
}

/**********************************************************************
Function name: explosion
Input:Board& board,bool isDraw: A boolean indicating whether to draw the board after the explosion.
Output:--
Function:Triggers the explosion of the bomb on the game board, marking the affected area.
Moves cubes down after the explosion and optionally redraws the board.
**********************************************************************/
void Bomb::explosion(Board& board,bool isDraw) const
{
	int bombX = cube.get_X(); 
	int bombY = cube.get_Y(); 
	int startingXExplosion = 0;
	int startingYExplosion = 0;
	int rangeX = 0;
	int rangeY = 0;

	Calculate_Valid_BlastRange_In_Board(bombX, bombY, startingXExplosion, startingYExplosion, rangeX, rangeY, board);
	for (int y = startingYExplosion; y <= startingYExplosion + rangeY; y++)
	{
		for (int x = startingXExplosion; x <= startingXExplosion + rangeX; x++)
		{
			if (board.isValidExplosion(x, y) == true)
				board.set_cube_active_in_board_game(x, y);
		}
	}
	board.moveCubesDownAfterExplosion(startingXExplosion, startingYExplosion, rangeX, rangeY); 
	if (isDraw)
		board.drawBoardCubes(); 
}

/**********************************************************************
Function name:implementShapeToBoard
Input:Board& board,bool isDraw: A boolean indicating whether to draw the board after implementing the shape.
Output:--
Function:Implements the bomb shape onto the game board, triggering an explosion and optionally redrawing the board.
**********************************************************************/
void Bomb::implementShapeToBoard(Board& board, bool isDraw) const
{
	
	explosion(board, isDraw);
}

/**********************************************************************
Function name: check_valid_move
Input:const Board& board
Output:bool
Function:Checks if the current position of the bomb is valid on the game board.
**********************************************************************/
bool Bomb::check_valid_move(const Board& board) const
{
	return board.isValidPosition(cube.get_X(),cube.get_Y());
}

/**********************************************************************
Function name: Calculate_Valid_BlastRange_In_Board
Input:
	int bombX: The X-coordinate of the bomb.
	int bombY: The Y-coordinate of the bomb.
	int& startingXExplosion: Reference to the starting X-coordinate of the explosion area.
	int& startingYExplosion: Reference to the starting Y-coordinate of the explosion area.
	int& rangeX: Reference to the range of explosion along the X-axis.
	int& rangeY: Reference to the range of explosion along the Y-axis.
	const Board& board
Output:--
Function:Calculates the blast range of the bomb explosion based on its position and the board boundaries.
**********************************************************************/
void Bomb::Calculate_Valid_BlastRange_In_Board(int bombX, int bombY, int &startingXExplosion, int& startingYExplosion, int&rangeX, int& rangeY, const Board& board) const
{
	bool isFirstValidX = false;
	bool isFirstValidY = false;	
		for (int y = bombY - blastRange; (y <= bombY + blastRange) && (board.isValidYExplosion(y) == true); y++)
		{
			rangeY++;
			if (isFirstValidY == false)
			{
				startingYExplosion = y;
				isFirstValidY = true;
			}
		}
		for (int x = max(bombX - blastRange, board.getStartingX()); (x <= bombX + blastRange) && (board.isValidXExplosion(x) == true); x++)
		{
			rangeX++;
			if (isFirstValidX == false)
			{
				startingXExplosion = x;
				isFirstValidX = true;
			}
		}
}



/**********************************************************************
Function name: getX
Input:--
Output:int
Function:Returns the X-coordinate of the bomb cube.
**********************************************************************/
int Bomb::getX() const
{
	return cube.get_X();
}

