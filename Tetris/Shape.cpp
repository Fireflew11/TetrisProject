#include "Shape.h"

enum  ShapeType{ I = 1, O, T, S, Z, J, L};

Shape::Shape()
{
	int random_shape = rand() % 7;
	int x = starting_cube.get_X(); 
	int y = starting_cube.get_Y(); 
	switch (random_shape)
	{
	case I: 
	{
		cubes[0] = Cube(x, y); 
		cubes[1] = Cube(x, y - 1); 
		cubes[2] = Cube(x, y - 2); 
		cubes[3] = Cube(x, y - 3); 
	}
	case O:


	default:
		break;
	}
	
}
