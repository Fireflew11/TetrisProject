#pragma once
#include "ComplexShape.h"

/**********************************************************************
Class: Z_Shape

Description:
	Represents the Z-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
			 * *
			   * *
*/

class Z_Shape:public ComplexShape
{
public:
	Z_Shape(bool useColors, int startingX, int startingY);
	
};

