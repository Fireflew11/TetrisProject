#pragma once
#include "ComplexShape.h"
/*
			 * *
			   * *
*/

class Z_Shape:public ComplexShape
{
public:
	Z_Shape(bool useColors, int startingX, int startingY);
	const Cube* createCubes(int startingX, int startingY);
};

