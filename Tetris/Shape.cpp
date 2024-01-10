#include "Shape.h"
#include <ctime>
enum  ShapeType{ I = 1, O, T, S, Z, J, L};

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
		
	switch (random_shape)
	{
	case I: 
	{
		/*
			*
			* 
			* 
			* 
		*/
		cubes[0] = Cube(x, y); 
		cubes[1] = Cube(x, y + 1); 
		cubes[2] = Cube(x, y + 2); 
		cubes[3] = Cube(x, y + 3);
		break; 
	}
	case O:
		/* 
			* * 
			* *
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x+2,y );
		cubes[2] = Cube(x, y + 1);
		cubes[3] = Cube(x+2, y +1);



		break; 
	case T:
		/*
			   * * *
			     *
		*/
		cubes[0] = Cube(x - 2, y);
		cubes[1] = Cube(x, y);
		cubes[2] = Cube(x+2, y);
		cubes[3] = Cube(x, y +1);
		break; 
	case S:
		/*
			   
			   * *
			 * *
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x+2 , y);
		cubes[2] = Cube(x - 2, y + 1);
		cubes[3] = Cube(x, y + 1);
			
		break; 
	case Z: 
		/*
			 * *
			   * * 
			   
		*/
		cubes[0] = Cube(x - 2, y);
		cubes[1] = Cube(x, y);
		cubes[2] = Cube(x, y+1);
		cubes[3] = Cube(x+2 , y+1);
		break; 
	case J:
		/*
			  *
			  * 
			* * 
			 
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x ,y+1);
		cubes[2] = Cube(x - 2, y + 2);
		cubes[3] = Cube(x, y + 2);
		break; 
	case L: 
		/*
			 *
			 *
			 * *	 
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x, y+1);
		cubes[2] = Cube(x, y+2);
		cubes[3] = Cube(x+2, y+2);
		break; 
	default:
		break;
	}
	initializeCubesBlock();
	
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

void Shape::initializeCubesBlock() {
	int cubesIndex = 0;
	for (int i = 0; i < 3 && id != 2 && id != 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubesBlock[i][j] = new Cube(); // Initialize each element with a new Cube object
			cubesBlock[i][j]->set_X(startingX + (2 * (j - 1)));
			cubesBlock[i][j]->set_Y(startingY + i);
			if (cubesBlock[i][j]->get_X() == cubes[cubesIndex].get_X() && cubesBlock[i][j]->get_Y() == cubes[cubesIndex].get_Y()) {
				cubesBlock[i][j]->setIsActive(true);
				cubesIndex++;
			}
			else
				cubesBlock[i][j]->setIsActive(false);

		}
	}
}
void Shape::deleteCubesBlock() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			//delete cubesBlock[i][j]; // Delete each dynamically allocated Cube object
		}
	}
}
void Shape::drawShape() const {
	if (id == 2 || id == 1) {
		for (int i = 0; i < 4; i++)
		{
			cubes[i].drawCube(cubes[i].getIsActive());
		}
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cubesBlock[i][j]->drawCube(cubesBlock[i][j]->getIsActive());
			}
		}
	}
	
}
void Shape::rotateMatrixClockwise() {

	for (int i = 0; i < 3 / 2; i++) {
		for (int j = i; j < 3 - i - 1; j++) {

			// Swap elements of each cycle
			// in clockwise direction
			bool temp = (cubesBlock)[i][j]->getIsActive();
			cubesBlock[i][j]->setIsActive(cubesBlock[3 - 1 - j][i]->getIsActive());
			cubesBlock[3 - 1 - j][i]->setIsActive(cubesBlock[3 - 1 - i][3 - 1 - j]->getIsActive());
			cubesBlock[3 - 1 - i][3 - 1 - j]->setIsActive(cubesBlock[j][3 - 1 - i]->getIsActive());
			cubesBlock[j][3 - 1 - i]->setIsActive(temp);
		}
	}
}
void Shape::rotateMatrixCounterClockwise() {
	for (int i = 0; i < 3 / 2; i++)
	{
		for (int j = i; j < 3 - i - 1; j++)
		{
			// Swapping elements after each iteration in Anticlockwise direction
			bool temp = (cubesBlock)[i][j]->getIsActive();
			cubesBlock[i][j]->setIsActive(cubesBlock[j][3 - i - 1]->getIsActive());
			cubesBlock[j][3 - i - 1]->setIsActive(cubesBlock[3 - i - 1][3 - j - 1]->getIsActive());
			cubesBlock[3 - i - 1][3 - j - 1]->setIsActive(cubesBlock[3 - j - 1][i]->getIsActive());
			cubesBlock[3 - j - 1][i]->setIsActive(temp);
		}
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
void Shape::rotateShape(Direction direction) {
	if (id == 1) {
			transposeMatrix();
	}
	else if (id != 2) {
		if (direction == RIGHT)
			rotateMatrixClockwise();
		else
			rotateMatrixCounterClockwise();
	}
	
}
int Shape::getId() {
	return id;
}

Shape::~Shape() {
	int i = 1;
}