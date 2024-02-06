#include "RotatableShape.h"

RotatableShape::RotatableShape(int color, bool useColors, int startingX, int StartingY) :ComplexShape(color, useColors, startingX, StartingY){}



/**********************************************************************
Function name:rotate_CounterClock_wise
Input: const Board& board
Output: --
Function:The function rotates the shape 90 degrees counter-clockwise.
Checks if the new position is valid on the board.
**********************************************************************/
void RotatableShape::rotate_CounterClock_wise(const Board& board)
{
	drawShape(false);
	RotatableShape tempShape = *this;
	
	int centerX = tempShape.get_cubes()[0].get_X();
	int centerY = tempShape.get_cubes()[0].get_Y();

	for (int i = 0; i < 4; ++i)
	{
		int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
		int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;
		
		int newX = centerX + relativeY;
		int newY = centerY - relativeX;

		Cube tempCube(newX, newY, getColor(), true);
		tempShape.set_cubes_by_Index(i, tempCube);
	}

	if (board.check_valid_move(tempShape))
	{
		*this = tempShape;
	}
	drawShape(true);
	/*
	drawShape(false);
	RotatableShape tempShape = *this;
	int centerX = tempShape.cubes[0].get_X();
	int centerY = tempShape.cubes[0].get_Y();

	for (int i = 0; i < 4; ++i)
	{
		int relativeX = tempShape.cubes[i].get_X() - centerX;
		int relativeY = tempShape.cubes[i].get_Y() - centerY;

		tempShape.cubes[i].set_X(centerX + relativeY);
		tempShape.cubes[i].set_Y(centerY - relativeX);
		tempShape.cubes[i].setColor(color);
	}

	if (board.check_valid_move(tempShape))
	{
		*this = tempShape;
	}
	drawShape(true);
	*/
}

/**********************************************************************
Function name: rotate_Clock_wise
Input: const Board& board
Output: --
Function:The function rotates the shape 90 degrees clockwise.
Checks if the new position is valid on the board.
**********************************************************************/
void RotatableShape::rotate_Clock_wise(const Board& board)
{
	drawShape(false);
	RotatableShape tempShape = *this;
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

	if (board.check_valid_move(tempShape))
	{
		*this = tempShape;
	}
	drawShape(true);
	/*
	drawShape(false);
	RotatableShape tempShape = *this;
	int centerX = tempShape.get_cubes()[0].get_X();
	int centerY = tempShape.get_cubes()[0].get_Y();

	for (int i = 1; i < 4; ++i) {
		int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
		int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;

		int newX = centerX - relativeY;
		int newY = centerY + relativeX;

		Cube tempCube(newX, newY, color, true);
		tempShape.set_cubes_by_Index(i, tempCube);
	}

	if (board.check_valid_move(tempShape))
	{
		*this = tempShape;
	}
	drawShape(true);
	*/
}