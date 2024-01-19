#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"
#include <cctype>

/**********************************************************************
Function name:get_cubes
Input: 
Output: const Cube* const
Function:Returns a constant pointer to the array of cubes.
**********************************************************************/
const Cube* const Shape::get_cubes() const
{
	return cubes; 
}

/**********************************************************************
Function name:set_cubes_by_Index
Input:int i,Cube cube
Output: --
Function:Sets the cube at the specified index in the array to the given cube.
**********************************************************************/
void Shape::set_cubes_by_Index(int i,  Cube cube)
{
	cubes[i] = cube; 
}

/**********************************************************************
Function name: drawShape
Input: bool isActive
Output:--
Function: Draws the shape on the console screen using the cubes in the array.
**********************************************************************/
void Shape::drawShape(bool isActive) const
{
	for (int i = 0; i < 4; i++)
	{
		cubes[i].drawCube(isActive, useColors);
	}
	
}

/**********************************************************************
Function name:rotate_CounterClock_wise
Input: const Board& board
Output: --
Function:The function rotates the shape 90 degrees counter-clockwise.
Checks if the new position is valid on the board.
**********************************************************************/
void Shape::rotate_CounterClock_wise(const Board& board)
{
	drawShape(false);
	Shape tempShape = *this; 
	int centerX = tempShape.cubes[0].get_X();  
	int centerY = tempShape.cubes[0].get_Y();

	for (int i = 0; i < 4; ++i) 
	{
		int relativeX = tempShape.cubes[i].get_X() - centerX;
		int relativeY = tempShape.cubes[i].get_Y() - centerY;

		tempShape.cubes[i].set_X( centerX + relativeY);
		tempShape.cubes[i].set_Y(centerY - relativeX);
		tempShape.cubes[i].setColor(color);
	}

	if (board.check_valid_move(tempShape)) 
	{
		*this = tempShape;
	}
	drawShape(true);
}

/**********************************************************************
Function name: rotate_Clock_wise
Input: const Board& board
Output: --
Function:The function rotates the shape 90 degrees clockwise.
Checks if the new position is valid on the board.
**********************************************************************/
void Shape::rotate_Clock_wise(const Board& board) 
{
	drawShape(false);
	Shape tempShape = *this;
    int centerX = tempShape.get_cubes()[0].get_X();  
    int centerY = tempShape.get_cubes()[0].get_Y();

    for (int i = 1; i < 4; ++i) {
        int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
        int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;

        int newX = centerX - relativeY;
        int newY = centerY + relativeX;

        Cube tempCube(newX, newY,color, true);
        tempShape.set_cubes_by_Index(i, tempCube);
    }

    if (board.check_valid_move(tempShape)) 
	{
        *this = tempShape;  
    }
	drawShape(true);
}

/**********************************************************************
Function name:move_Left
Input: const Board& board 
Output: --
Function:The Function moves the shape one unit to the left.
Checks if the new position is valid on the board.
**********************************************************************/
void Shape::move_Left(const Board& board)
{

	drawShape(false);
	Shape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() - 1;
		Cube temp_cube(x, temp.cubes[i].get_Y(),color , true);
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
void Shape::move_Right(const Board& board)
{
	drawShape(false);
	Shape temp = *this;

	for (int i = 0; i < 4; ++i) 
	{
		int x = temp.cubes[i].get_X() + 1; 
		Cube temp_cube(x, temp.cubes[i].get_Y(),color, true);
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
bool Shape::continueMovingDown(const Board& board)
{
	Shape temp = *this;
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
Function name: drop
Input: const Board& board
Output: --
Function:The function moves the shape down faster than usual
**********************************************************************/
void Shape::drop(const Board& board)
{
	while (continueMovingDown(board)) 
	{
		Sleep(30);
	}
}

/**********************************************************************
Function name: Shape (Constructor)
Input: gameConfig::PlayerType playerType - Type of the player (LEFT_PLAYER or RIGHT_PLAYER)
	   bool useColors - Whether to use colors for the shape
Output:--
Function:Initializes a new instance of the Shape class.
**********************************************************************/
Shape::Shape(gameConfig::PlayerType playerType, bool useColors) 
{
	srand(time(0));
	int x = 0, y = 0; 
	int randomShape= rand() % (int)gameConfig::NUM_OF_SHAPES + 1;
	this->useColors = useColors; 
	color = gameConfig::COLORS[randomShape];
	type = (gameConfig::ShapeType)randomShape; 

	if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
	{
		x = gameConfig::GAME_WIDTH/2 + gameConfig::MIN_X_LEFT_BOARD + 1; 
		y = gameConfig::MIN_Y_LEFT_BOARD; 
	}
	else
	{ 
		x = gameConfig::GAME_WIDTH/2 + gameConfig::MIN_X_RIGHT_BOARD + 1;
		y = gameConfig::MIN_Y_RIGHT_BOARD;
	}

	switch ((gameConfig::ShapeType)randomShape)
	{
	case gameConfig::ShapeType::I:
	{
		/*
			*
			*
			*
			*
		*/
		cubes[0] = Cube(x, y + 1,color);
		cubes[1] = Cube(x, y, color);
		cubes[2] = Cube(x, y + 2, color);
		cubes[3] = Cube(x, y + 3, color);
		break;
	}
	case  gameConfig::ShapeType::O:
		/*
			* *
			* *
		*/
		cubes[0] = Cube(x, y, color);
		cubes[1] = Cube(x + 1, y, color);
		cubes[2] = Cube(x, y + 1, color);
		cubes[3] = Cube(x + 1, y + 1, color);



		break;
	case  gameConfig::ShapeType::T:
		/*
			   * * *
				 *
		*/
		cubes[0] = Cube(x, y, color);
		cubes[1] = Cube(x - 1, y, color);
		cubes[2] = Cube(x + 1, y, color);
		cubes[3] = Cube(x, y + 1, color);
		break;
	case  gameConfig::ShapeType::S:
		/*

			   * *
			 * *
		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x + 1, y, color);
		cubes[2] = Cube(x - 1, y + 1, color);
		cubes[3] = Cube(x, y, color);

		break;
	case  gameConfig::ShapeType::Z:
		/*
			 * *
			   * *

		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x - 1, y, color);
		cubes[2] = Cube(x, y, color);
		cubes[3] = Cube(x + 1, y + 1, color);
		break;
	case  gameConfig::ShapeType::J:
		/*
			  *
			  *
			* *

		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x, y, color);
		cubes[2] = Cube(x - 1, y + 2, color);
		cubes[3] = Cube(x, y + 2, color);
		break;
	case  gameConfig::ShapeType::L:
		/*
			 *
			 *
			 * *
		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x, y, color);
		cubes[2] = Cube(x, y + 2, color);
		cubes[3] = Cube(x + 1, y + 2, color);
		break;
	default:
		break;
	}

}

/**********************************************************************
Function name:getShapeType
Input:--
Output:const gameConfig::ShapeType
Function:Returns the type of the shape.
**********************************************************************/
const gameConfig::ShapeType Shape:: getShapeType()
{
	return type;
}