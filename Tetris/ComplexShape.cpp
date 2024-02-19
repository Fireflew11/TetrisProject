#include "ComplexShape.h"


/**********************************************************************
Function name:Constructor ComplexShape
Input: int color, bool useColors, int startingX, int startingY, int differentRotations, const Cube(&newCubes)[4]
Output: --
Function: Constructor for the ComplexShape class. Initializes a ComplexShape object with the specified parameters.
**********************************************************************/
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY, int differentRotations, const Cube(&newCubes)[4])
	: Shape(color, useColors, startingX, startingY, differentRotations), cubes{newCubes[0], newCubes[1], newCubes[2], newCubes[3]}
{}

/**********************************************************************
Function name: fillsWell
Input:const Board& board
Output: int
Function:determines how many parts of the well are filled by the shape.
**********************************************************************/
int ComplexShape::fillsWell(const Board& board) const {
	int filledParts = 0; // Counter for filled parts of the well

	// Iterate through each cube of the shape
	for (int i = 0; i < 4; ++i) {
		int currX = cubes[i].get_X() - board.getStartingX(); // Adjust X coordinate
		int currY = cubes[i].get_Y() - board.getStartingY(); // Adjust Y coordinate

		// Check if the cube is against the left or right wall and at the bottom of the board
		if ((currX == 0 || currX == gameConfig::GAME_WIDTH - 1) && currY == gameConfig::GAME_HEIGHT - 1) {
			filledParts++; // Increment the counter for filled parts
		}
	}

	return filledParts;
}

/**********************************************************************
Function name: getX
Input: --
Output: int
Function: Returns the X-coordinate of the first cube in the ComplexShape.
**********************************************************************/
int ComplexShape::getX() const
{
	return cubes[0].get_X();
}

/**********************************************************************
Function name: drawShape
Input: bool isActive
Output:--
Function: Draws the shape on the console screen using the cubes in the array.
**********************************************************************/
void ComplexShape::drawShape(bool isActive)const
{
	for (int i = 0; i < 4; i++)
	{
		cubes[i].drawCube(isActive, getUseColors());
	}
}


/**********************************************************************
Function name:move_Left
Input: const Board& board
Output: bool
Function:The Function moves the shape one unit to the left.
Checks if the new position is valid on the board.
**********************************************************************/
bool ComplexShape::move_Left(const Board& board)
{
	bool res = false;
	ComplexShape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() - 1;
		Cube temp_cube(x, temp.cubes[i].get_Y(), getColor(), true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

	if (temp.check_valid_move(board))
	{
		*this = temp;
		res = true;
	}
	return res;
}


/**********************************************************************
Function name: move_Right
Input: const Board& board
Output: bool
Function: Moves the shape one unit to the right.
Checks if the new position is valid on the board.
**********************************************************************/
bool ComplexShape::move_Right(const Board& board)
{
	bool res = false;
	ComplexShape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() + 1;
		Cube temp_cube(x, temp.cubes[i].get_Y(), getColor(), true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

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
Output: bool - Whether the shape successfully moved down
Function:Moves the shape one unit down and checks if it can continue moving.
**********************************************************************/
bool ComplexShape::continueMovingDown(const Board& board)
{
	ComplexShape temp = *this;
	for (int i = 0; i < 4; i++)
	{
		int y = temp.cubes[i].get_Y() + 1;
		Cube tempCube(temp.cubes[i].get_X(), y, getColor(), true);
		temp.set_cubes_by_Index(i, tempCube);
	}

	if (temp.check_valid_move(board))
	{
		*this = temp;      // Update the shape
		return true;
	}

	return false;
}




/**********************************************************************
Function name:get_cubes
Input:
Output: const Cube* const
Function:Returns a constant pointer to the array of cubes.
**********************************************************************/
const Cube* const ComplexShape::get_cubes() const
{
	return cubes;
}

/**********************************************************************
Function name:set_cubes_by_Index
Input:int i,Cube cube
Output: --
Function:Sets the cube at the specified index in the array to the given cube.
**********************************************************************/
void ComplexShape::set_cubes_by_Index(int i, Cube cube)
{
	cubes[i] = cube;
}

/**********************************************************************
Function name: clone
Input:--
Output: Shape*
Function:Creates a new ComplexShape object that is a clone of the current ComplexShape object and returns a pointer to it.
**********************************************************************/
Shape* ComplexShape::clone() const
{
	return new ComplexShape(*this);
}

/**********************************************************************
Function name: set_cubes_by_Index
Input: int i, Cube cube
Output: --
Function: Sets the cube at the specified index in the array to the given cube.
**********************************************************************/
 Cube* const ComplexShape::get_and_set_cubes()
{
	return cubes;
}

 /**********************************************************************
 Function name: rotate_CounterClock_wise
 Input: const Board& board
 Output: bool
 Function: Rotates the shape counterclockwise if the new position is valid on the board.
 **********************************************************************/
bool ComplexShape::rotate_CounterClock_wise(const Board& board)
{
	bool res = false;
	ComplexShape tempShape = *this;
	int centerX = tempShape.get_cubes()[0].get_X();
	int centerY = tempShape.get_cubes()[0].get_Y();


	for (int i = 1; i < 4; ++i) {
		int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
		int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;

		int newX = centerX + relativeY;
		int newY = centerY - relativeX;

		Cube tempCube(newX, newY, getColor(), true);
		tempShape.set_cubes_by_Index(i, tempCube);
	}

	if (tempShape.check_valid_move(board))
	{
		*this = tempShape;
		res = true;
	}
	return res;
}

/**********************************************************************
Function name: rotate_Clock_wise
Input: const Board& board
Output: bool
Function: Rotates the shape clockwise if the new position is valid on the board.
**********************************************************************/
bool ComplexShape::rotate_Clock_wise(const Board& board)
{
	bool res = false;
	ComplexShape tempShape = *this;
	int centerX = tempShape.get_cubes()[0].get_X();
	int centerY = tempShape.get_cubes()[0].get_Y();

	for (int i = 1; i < 4; ++i) {
		int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
		int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;

		int newX = centerX - relativeY;
		int newY = centerY + relativeX;

		Cube tempCube(newX, newY, getColor(), true);
		tempShape.set_cubes_by_Index(i, tempCube);
	}

	if (tempShape.check_valid_move(board))
	{
		*this = tempShape;
		res = true;
	}
	return res;
}

/**********************************************************************
Function name: implementShapeToBoard
Input: Board& board, bool isDraw
Output: --
Function: Updates the board with the current shape.
**********************************************************************/
void ComplexShape::implementShapeToBoard(Board& board,bool isDraw) const
{
	int startingX = board.getStartingX();
	int startingY = board.getStartingY(); 
	for (int i = 0; i < 4; i++)
	{	
		board.get_to_set_BoardGame()[(cubes[i].get_Y() - startingY)][(cubes[i].get_X() - startingX )].setIsActive(true);
		board.get_to_set_BoardGame()[(cubes[i].get_Y() - startingY)][(cubes[i].get_X() - startingX )].setColor(getColor());
	}
}

/**********************************************************************
Function name: check_valid_move
Input: const Board& board
Output: bool
Function: Checks if the current shape can make a valid move on the board.
**********************************************************************/
bool ComplexShape::check_valid_move(const Board& board) const
{
	bool res = true; 
	for (int i = 0; i < 4 && res==true; i++)
	{
		int x = cubes[i].get_X();
		int y = cubes[i].get_Y();
		res = board.isValidPosition(x, y); 
	}
	return res;
}

