#include "Shape.h"

enum  ShapeType{ I = 1, O, T, S, Z, J, L};

Shape::Shape(int x, int y, int cheatShape) //added cheat for checks, will be removed in final version (default value 0 means no cheat
{	
	int random_shape;
	if (cheatShape == 0)
		random_shape = rand() % 7;
	else
		random_shape = cheatShape;
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
		cubes[3] = Cube(x-2, y +1);
		break; 
	case T:
		/*
			   * * *
			     *
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x - 2, y);
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
		cubes[2] = Cube(x, y+1);
		cubes[3] = Cube(x-2, y+1);
		break; 
	case Z: 
		/*
			 * *
			   * * 
			   
		*/
		cubes[0] = Cube(x, y);
		cubes[1] = Cube(x-2 , y);
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
		cubes[2] = Cube(x, y+2);
		cubes[3] = Cube(x-2, y+2);
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
	
}

const Cube* const Shape::get_cubes() const
{
	return cubes; 
}

void Shape::set_cubes_by_Index(int i,  Cube cube)
{
	cubes[i] = cube; 
}
