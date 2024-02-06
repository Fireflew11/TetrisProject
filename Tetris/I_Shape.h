#pragma once
#include "RotatableShape.h"

class I_Shape: public ComplexShape
{
public:
	I_Shape(int color, bool useColors, int startingX, int startingY);
	const Cube* createCubes(int startingX, int startingY, int color)
};

