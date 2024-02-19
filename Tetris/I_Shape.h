#pragma once
#include "ComplexShape.h"

/**********************************************************************
Class: I_Shape

Description:
    Represents the I-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
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
	
};

