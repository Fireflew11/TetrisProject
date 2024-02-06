#pragma once
#include "ComplexShape.h"
class S_Shape :public ComplexShape
{
public:
	S_Shape(bool useColors, int startingX, int startingY);
	const Cube* createCubes(int startingX, int startingY);
};

