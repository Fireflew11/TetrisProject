#pragma once
#include "ComplexShape.h"
/*
			  *
			  *
			* *

*/
class J_Shape:public ComplexShape
{
public: 
	J_Shape(bool useColors, int startingX, int startingY);
	const Cube* createCubes(int startingX, int startingY);
};

