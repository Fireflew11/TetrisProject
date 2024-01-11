#include "Shape.h"
#include <ctime>
#include "gameConfig.h"
#include "Board.h"


Shape::Shape(int x, int y, int cheatShape) //added cheat for checks, will be removed in final version (default value 0 means no cheat
{	
	srand(time(0));
	int random_shape;
	if (cheatShape == 0)
		random_shape = rand() % 7;
	else
		random_shape = cheatShape;
	startingX = x;
	startingY = y;
	id = random_shape;
		
	switch ((gameConfig::ShapeType)random_shape)
	{
	case gameConfig::ShapeType::I:
	{
		/*
			*
			* 
			* 
			* 
		*/
		cubes[0] = Cube(x, y + 1);
		cubes[1] = Cube(x, y); 
		cubes[2] = Cube(x, y + 2); 
		cubes[3] = Cube(x, y + 3);
		break; 
	}
	case  gameConfig::ShapeType::O:
		/* 
			* * 
			* *
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x+2,y );
		cubes[2] = Cube(x, y + 1);
		cubes[3] = Cube(x+2, y +1);



		break; 
	case  gameConfig::ShapeType::T:
		/*
			   * * *
			     *
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x - 2, y);
		cubes[2] = Cube(x+2, y);
		cubes[3] = Cube(x, y +1);
		break; 
	case  gameConfig::ShapeType::S:
		/*
			   
			   * *
			 * *
		*/
		cubes[0] = Cube(x, y + 1);
		cubes[1] = Cube(x+2 , y);
		cubes[2] = Cube(x - 2, y + 1);
		cubes[3] = Cube(x, y);
			
		break; 
	case  gameConfig::ShapeType::Z:
		/*
			 * *
			   * * 
			   
		*/
		cubes[0] = Cube(x, y + 1);
		cubes[1] = Cube(x - 2, y);
		cubes[2] = Cube(x, y);
		cubes[3] = Cube(x+2 , y+1);
		break; 
	case  gameConfig::ShapeType::J:
		/*
			  *
			  * 
			* * 
			 
		*/
		cubes[0] = Cube(x, y + 1);
		cubes[1] = Cube(x, y);
		cubes[2] = Cube(x - 2, y + 2);
		cubes[3] = Cube(x, y + 2);
		break; 
	case  gameConfig::ShapeType::L:
		/*
			 *
			 *
			 * *	 
		*/
		cubes[0] = Cube(x, y + 1);
		cubes[1] = Cube(x, y);
		cubes[2] = Cube(x, y+2);
		cubes[3] = Cube(x+2, y+2);
		break; 
	default:
		break;
	}
	
}


const Cube* const Shape::get_cubes() const
{
	return cubes; 
}

void Shape::set_cubes_by_Index(int i,  Cube cube)
{
	cubes[i] = cube; 
}

int Shape::getRowsAmount() const {
	if (id == 1)
		return 4;
	else
		return 3;
}

void Shape::deleteCubesBlock() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			//delete cubesBlock[i][j]; // Delete each dynamically allocated Cube object
		}
	}
}
void Shape::drawShape(bool isActive) const {
	for (int i = 0; i < 4; i++)
	{
		cubes[i].drawCube(isActive);
	}
	
}

void Shape::transposeMatrix() {
	int direction;
	for (int i = 0; i < 4; i++)
	{
		cubes[i].setIsActive(false);
	}
	drawShape();
	if (isIVertical)
		direction = 1;
	else
		direction = -1;
	cubes[0].set_X(cubes[0].get_X() + (-2) * direction);
	cubes[0].set_Y(cubes[0].get_Y() + (+1) * direction);
	cubes[2].set_X(cubes[2].get_X() + (+2) * direction);
	cubes[2].set_Y(cubes[2].get_Y() + (-1) * direction);
	cubes[3].set_X(cubes[3].get_X() + (+4) * direction);
	cubes[3].set_Y(cubes[3].get_Y() + (-2) * direction);
	for (int i = 0; i < 4; i++)
	{
		cubes[i].setIsActive(true);
	}
	isIVertical = !isIVertical;
}
int Shape::getId() {
	return id;
}

Shape::~Shape() {
	int i = 1;
}



void Shape::rotate_CounterClock_wise2(const Board& board)
{
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
	}

	if (board.check_valid_move(tempShape)) 
	{
		*this = tempShape;
	}
}


void Shape::rotate_Clock_wise2(const Board& board)
{
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
        Cube tempCube(newX, newY, true);
        tempShape.set_cubes_by_Index(i, tempCube);
    }

    // Check if the rotated shape is a valid move on the board
    if (board.check_valid_move(tempShape)) {
        *this = tempShape;  // Update the current shape if the move is valid
    }
}
