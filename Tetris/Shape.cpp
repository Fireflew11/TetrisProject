#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"
#include <cctype>

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
	int randomShape = rand() % (int)gameConfig::NUM_OF_SHAPES + 1;
	this->useColors = useColors;
	color = gameConfig::COLORS[randomShape];
	type = (gameConfig::ShapeType)randomShape;

	if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
	{
		x = gameConfig::GAME_WIDTH / 2 + gameConfig::MIN_X_LEFT_BOARD + 1;
		y = gameConfig::MIN_Y_LEFT_BOARD;
	}
	else
	{
		x = gameConfig::GAME_WIDTH / 2 + gameConfig::MIN_X_RIGHT_BOARD + 1;
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
		cubes[0] = Cube(x, y + 1, color);
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

Shape::Shape(int color, bool useColors, int startingX, int StartingY) : color(color), useColors(useColors), startingX(startingX), StartingY(StartingY) {}

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
Function:The function moves the shape down to the bottom
**********************************************************************/
void Shape::drop(const Board& board)
{
	while (continueMovingDown(board))
	{
		Sleep(30);
	}
}

bool Shape::getUseColors() const
{
	return useColors; 
}

