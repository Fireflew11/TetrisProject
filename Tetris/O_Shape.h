#pragma once
#include "ComplexShape.h"
/**********************************************************************
Class: O_Shape

Description:
	Represents the O-shaped tetromino in the game. Inherits from the ComplexShape class.
**********************************************************************/
/*
			* *
			* *
*/
class O_Shape: public ComplexShape
{
public: 
	O_Shape(bool useColors, int startingX, int startingY);
	
	bool rotate_CounterClock_wise(const Board& board) override { return false; };
	bool rotate_Clock_wise(const Board& board) override { return false; };
};

