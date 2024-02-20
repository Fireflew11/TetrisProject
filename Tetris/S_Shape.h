#pragma once
#include "ComplexShape.h"
/**********************************************************************
Class: S_Shape

Description:
	Represents the S-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
		  * *
		* * 
*/
class S_Shape :public ComplexShape
{
public:
	S_Shape(bool useColors, int startingX, int startingY);
	
};

