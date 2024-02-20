#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"
#include <cctype>


/**********************************************************************
Constructor: Shape::Shape
Input:
	- int color: The color of the shape.
	- bool useColors: Flag indicating whether to use colors for display.
	- int startingX: The starting X coordinate of the shape.
	- int StartingY: The starting Y coordinate of the shape.
	- int differentRotations: The number of different rotations the shape can have.
Function: Constructor for the Shape class.
**********************************************************************/
Shape::Shape(int color, bool useColors, int startingX, int StartingY, int differentRotations) : color(color), useColors(useColors), startingX(startingX), StartingY(StartingY), differentRotations(differentRotations) {}

/**********************************************************************
Function name: getColor
Input: --
Output: int
Function: Returns the color of the shape.
**********************************************************************/
int Shape::getColor() const
{
	return color;
}

/**********************************************************************
Function name: getDifferentRotations
Input: None
Output: int
Function: Returns the number of different possible rotations for the shape.
**********************************************************************/
int Shape::getDifferentRotations() const 
{
	return differentRotations;
}

/**********************************************************************
Function name: drop
Input: const Board& board
Output: --
Function:The function moves the shape down to the bottom
**********************************************************************/
bool Shape::drop(const Board& board)
{
	while (continueMovingDown(board))
	{
		Sleep(30);
	}
	return false;
}

/**********************************************************************
Function name: getUseColors
Input: --
Output: bool
Function: Returns true if colors are used in the game; otherwise, returns false.
**********************************************************************/
bool Shape::getUseColors() const
{
	return useColors; 
}

