#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"
#include <cctype>





const Cube* const Shape::get_cubes() const
{
	return cubes; 
}

void Shape::set_cubes_by_Index(int i,  Cube cube)
{
	cubes[i] = cube; 
}



void Shape::deleteCubesBlock() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			//delete cubesBlock[i][j]; // Delete each dynamically allocated Cube object
		}
	}
}



void Shape::drawShape(bool isActive) const 
{
	for (int i = 0; i < 4; i++)
	{
		cubes[i].drawCube(isActive,useColors);
	}
	
}



Shape::~Shape() {
	int i = 1;
}



void Shape::rotate_CounterClock_wise(const Board& board)
{
	drawShape(false);
	Shape tempShape = *this; 
	int centerX = tempShape.cubes[0].get_X();  // Assuming the first cube is the center of the shape
	int centerY = tempShape.cubes[0].get_Y();

	for (int i = 0; i < 4; ++i) 
	{
		int relativeX = tempShape.cubes[i].get_X() - centerX;
		int relativeY = tempShape.cubes[i].get_Y() - centerY;

		// Perform 90-degree clockwise rotation
		tempShape.cubes[i].set_X( centerX + relativeY*2);
		tempShape.cubes[i].set_Y(centerY - relativeX/2);
		tempShape.cubes[i].setColor(color);
	}

	if (board.check_valid_move(tempShape)) 
	{
		*this = tempShape;
	}
	drawShape(true);
}


void Shape::rotate_Clock_wise(const Board& board)
{
	drawShape(false);
	Shape tempShape = *this;
    int centerX = tempShape.get_cubes()[0].get_X();  // Assuming the first cube is the center of the shape
    int centerY = tempShape.get_cubes()[0].get_Y();

    for (int i = 1; i < 4; ++i) {
        int relativeX = tempShape.get_cubes()[i].get_X() - centerX;
        int relativeY = tempShape.get_cubes()[i].get_Y() - centerY;

        // Perform 90-degree counterclockwise rotation
        // Each cube is 2x1, so we need to consider the size

        // Calculate new positions for the rotated cube
        int newX = centerX - relativeY * 2;
        int newY = centerY + relativeX/2;

        // Update the cube in the temporary shape
        Cube tempCube(newX, newY,color, true);
        tempShape.set_cubes_by_Index(i, tempCube);
    }

    // Check if the rotated shape is a valid move on the board
    if (board.check_valid_move(tempShape)) 
	{
        *this = tempShape;  // Update the current shape if the move is valid
    }
	drawShape(true);
}


void Shape::move_Left(const Board& board)
{

	drawShape(false);
	Shape temp = *this;

	for (int i = 0; i < 4; ++i)
	{
		int x = temp.cubes[i].get_X() - 2;
		Cube temp_cube(x, temp.cubes[i].get_Y(),color , true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

	if (board.check_valid_move(temp))
	{
		*this = temp;
	}
	drawShape(true);
}



void Shape::move_Right(const Board& board)
{
	drawShape(false);
	Shape temp = *this;

	for (int i = 0; i < 4; ++i) 
	{
		int x = temp.cubes[i].get_X() + 2; 
		Cube temp_cube(x, temp.cubes[i].get_Y(),color, true);
		temp.set_cubes_by_Index(i, temp_cube);
	}

	if (board.check_valid_move(temp))
	{
		*this = temp;
	}
	drawShape(true);
}


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






int Shape::getColor() const
{
	return color;
}



void Shape::drop(const Board& board)
{
	continueMovingDown(board);
}

Shape::Shape(gameConfig::PlayerType playerType, bool useColors) 
{
	srand(time(0));
	int x = 0, y = 0; 
	int randomShape= rand() % (int)gameConfig::NUM_OF_SHAPES + 1;
	this->useColors = useColors; 
	color = gameConfig::COLORS[randomShape];
	type = (gameConfig::ShapeType)randomShape; 
	/*
	if(useColors==true)
		color = gameConfig::COLORS[randomShape];
	else 
		color= gameConfig::COLORS[0];
*/

	if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
	{
		//startingX = gameConfig::MIN_X_LEFT_BOARD + 1;
		//startingY = gameConfig::MIN_Y_LEFT_BOARD;
		x = gameConfig::GAME_WIDTH +gameConfig::MIN_X_LEFT_BOARD + 1; 
		y = gameConfig::MIN_Y_LEFT_BOARD; 
	}
	else
	{
		//startingX = gameConfig::MIN_X_RIGHT_BOARD + 1; 
		//startingY = gameConfig::MIN_Y_RIGHT_BOARD; 
		x = gameConfig::GAME_WIDTH+ gameConfig::MIN_X_RIGHT_BOARD + 1;
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
		cubes[1] = Cube(x + 2, y, color);
		cubes[2] = Cube(x, y + 1, color);
		cubes[3] = Cube(x + 2, y + 1, color);



		break;
	case  gameConfig::ShapeType::T:
		/*
			   * * *
				 *
		*/
		cubes[0] = Cube(x, y, color);
		cubes[1] = Cube(x - 2, y, color);
		cubes[2] = Cube(x + 2, y, color);
		cubes[3] = Cube(x, y + 1, color);
		break;
	case  gameConfig::ShapeType::S:
		/*

			   * *
			 * *
		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x + 2, y, color);
		cubes[2] = Cube(x - 2, y + 1, color);
		cubes[3] = Cube(x, y, color);

		break;
	case  gameConfig::ShapeType::Z:
		/*
			 * *
			   * *

		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x - 2, y, color);
		cubes[2] = Cube(x, y, color);
		cubes[3] = Cube(x + 2, y + 1, color);
		break;
	case  gameConfig::ShapeType::J:
		/*
			  *
			  *
			* *

		*/
		cubes[0] = Cube(x, y + 1, color);
		cubes[1] = Cube(x, y, color);
		cubes[2] = Cube(x - 2, y + 2, color);
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
		cubes[3] = Cube(x + 2, y + 2, color);
		break;
	default:
		break;
	}

}
const gameConfig::ShapeType Shape:: getShapeType()
{
	return type;
}