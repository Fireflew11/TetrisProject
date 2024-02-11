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
/*
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY,const Cube newCubes[4]) : Shape(color, useColors, startingX, startingY), cubes{newCubes[0], newCubes[1], newCubes[2], newCubes[3]}
{
	
	//for (int i = 0; i < 4; i++) 
	//{
	//	cubes[i] = newCubes[i];
	//}
}
*/
/*
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube newCubes[]) : Shape(color, useColors, startingX, startingY) {
	for (int i = 0; i < 4; i++)
	{
		cubes[i] = newCubes[i];
	}
}
*/
/*
ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube(&newCubes)[4]): Shape(color, useColors, startingX, startingY)
{
	for (int i = 0; i < 4; i++) 
	{
		cubes[i] = newCubes[i];
	}
}
*/

ComplexShape::ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube(&newCubes)[4])
	: Shape(color, useColors, startingX, startingY), cubes{ newCubes[0], newCubes[1], newCubes[2], newCubes[3] }
{}

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
bool ComplexShape::move_Left(const Board& board)
{
	bool res = false;
	drawShape(false);
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
	drawShape(true);
}


/**********************************************************************
Function name: move_Right
Input: const Board& board
Output: None
Function: Moves the shape one unit to the right.
Checks if the new position is valid on the board.
**********************************************************************/
bool ComplexShape::move_Right(const Board& board)
{
	bool res = false;
	drawShape(false);
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
		Cube tempCube(temp.cubes[i].get_X(), y, getColor(), true);
		temp.set_cubes_by_Index(i, tempCube);
	}

	if (temp.check_valid_move(board))
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


bool ComplexShape::rotate_CounterClock_wise(const Board& board)
{
	bool res = false;
	drawShape(false);
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
	drawShape(true);
}

bool ComplexShape::rotate_Clock_wise(const Board& board)
{
	bool res = false;
	drawShape(false);
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
	drawShape(true);
}


void ComplexShape::implementShapeToBoard(Board& board)
{
	int startingX = board.getStartingX();
	for (int i = 0; i < 4; i++)
	{	
		board.get_to_set_BoardGame()[(cubes[i].get_Y() - 1)][(cubes[i].get_X() - startingX - 1)].setIsActive(true);
		board.get_to_set_BoardGame()[(cubes[i].get_Y() - 1)][(cubes[i].get_X() - startingX - 1)].setColor(getColor());
	}
}

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

