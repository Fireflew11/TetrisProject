#include "ComplexShape.h"

/*
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY): Shape(color, useColors, startingX, startingY)
{
	for (auto& cube : cubes)
	{
		cube.set_coord(startingX, startingY); 
	}
}

*/
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube* newCubes): Shape(color, useColors, startingX, startingY)
{
	for (int i = 0; i < 4; ++i) 
	{
		cubes[i] = newCubes[i];
	}
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
Output: --
Function:The Function moves the shape one unit to the left.
Checks if the new position is valid on the board.
**********************************************************************/
void ComplexShape::move_Left(const Board& board)
{

	drawShape(false);
	ComplexShape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() - 1;
		Cube temp_cube(x, temp.cubes[i].get_Y(), getColor(), true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

	if (board.check_valid_move(temp))
	{
		*this = temp;
	}
	drawShape(true);
}


/**********************************************************************
Function name: move_Right
Input: const Board& board
Output: None
Function: Moves the shape one unit to the right.
Checks if the new position is valid on the board.
**********************************************************************/
void ComplexShape::move_Right(const Board& board)
{
	drawShape(false);
	ComplexShape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() + 1;
		Cube temp_cube(x, temp.cubes[i].get_Y(), getColor(), true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

	if (board.check_valid_move(temp))
	{
		*this = temp;
	}
	drawShape(true);
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
		Cube tempCube(temp.cubes[i].get_X(), y, color, true);
		temp.set_cubes_by_Index(i, tempCube);
	}

	if (board.check_valid_move(temp))
	{
		drawShape(false);  // Erase the current shape
		*this = temp;      // Update the shape
		drawShape(true);   // Draw the shape at its new position
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

 Cube* const ComplexShape::get_and_set_cubes()
{
	return cubes;
}


