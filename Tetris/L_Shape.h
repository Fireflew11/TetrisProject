#pragma once
#include "ComplexShape.h"
/**********************************************************************
Class: L_Shape

Description:
	Represents the L-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
		 *
		 *
		 * *
*/
class L_Shape: public ComplexShape
{
public: 
	L_Shape(bool useColors, int startingX, int startingY);
	
};

