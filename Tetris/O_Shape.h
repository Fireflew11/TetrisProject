#pragma once
#include "ComplexShape.h"
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

