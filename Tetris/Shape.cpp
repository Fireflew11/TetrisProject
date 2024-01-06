#include "Shape.h"

enum  ShapeType{ I = 1, O, T, S, Z, J, L};
/*
Shape::Shape(int x, int y)
{
	int random_shape = rand() % 7;
	switch (random_shape)
	{
	case I: 
	{
		cubes[0] = Cube(x, y); 
		cubes[1] = Cube(x-1, y); 
		cubes[2] = Cube(x-2, y); 
		cubes[3] = Cube(x-3, y); 
		break; 
	}
	case O:
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x+1,y );
		cubes[2] = Cube(x, y - 1);
		cubes[3] = Cube(x-1, y - 1);
		break; 
	case T: 
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x - 1, y);
		cubes[2] = Cube(x+1, y);
		cubes[3] = Cube(x, y - 1);
		break; 
	case S:
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x+1 , y);
		cubes[2] = Cube(x, y-1);
		cubes[3] = Cube(x-1, y-1);
		break; 
	case Z: 
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x-1 , y);
		cubes[2] = Cube(x, y-1);
		cubes[3] = Cube(x+1 , y-1);
		break; 
	case J:
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x ,y-1);
		cubes[2] = Cube(x, y-2);
		cubes[3] = Cube(x-1, y-2);
		break; 
	case L: 
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x, y-1);
		cubes[2] = Cube(x, y-2 );
		cubes[3] = Cube(x+1, y-2);
		break; 
	default:
		break;
	}
	
}
*/
const Cube* const Shape::get_cubes()
{
	return cubes; 
}