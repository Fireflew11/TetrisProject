#pragma once
#include "ComplexShape.h"
/*
			*
			*
			*
			*
*/
class I_Shape: public ComplexShape
{
public:
	I_Shape(bool useColors, int startingX, int startingY);
	const Cube* createCubes(int startingX, int startingY);
};

