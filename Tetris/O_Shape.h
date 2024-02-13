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
	
	void rotate_CounterClock_wise(const Board& board) override {};
	void rotate_Clock_wise(const Board& board) override {};
};

