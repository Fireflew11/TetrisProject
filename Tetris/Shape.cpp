#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"
#include <cctype>



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
int Shape::getDifferentRotations() const {
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


bool Shape::getUseColors() const
{
	return useColors; 
}

