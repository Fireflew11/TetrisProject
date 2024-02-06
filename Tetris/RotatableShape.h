#pragma once
#include "ComplexShape.h"
class RotatableShape: ComplexShape
{
public: 
	void rotate_CounterClock_wise(const Board& board);
	void rotate_Clock_wise(const Board& board);
	RotatableShape(int color, bool useColors, int startingX, int StartingY);
};

