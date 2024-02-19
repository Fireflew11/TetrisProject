#pragma once
#include "ComplexShape.h"

/**********************************************************************
Class: T_Shape

Description:
	Represents the T-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
			   * * *
				 *
*/
class T_Shape:public ComplexShape
{
public:
	T_Shape(bool useColors, int startingX, int startingY);
	
};

