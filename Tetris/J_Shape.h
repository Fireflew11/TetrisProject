#pragma once
#include "ComplexShape.h"
/**********************************************************************
Class: J_Shape

Description:
	Represents the J-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
			  *
			  *
			* *

*/
class J_Shape:public ComplexShape
{
public: 
	J_Shape(bool useColors, int startingX, int startingY);
};

