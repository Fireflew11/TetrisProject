#pragma once
#include "Shape.h" 

class ComplexShape: public Shape
{
	Cube cubes[4];
	
public: 
	void drawShape(bool isActive = true) const override;
	void move_Left(const Board& board)override;
	void move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;


	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i, Cube cube);

	//ComplexShape(int color, bool useColors, int startingX,int startingY);
	ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube* newCubes);
	Cube* const get_and_set_cubes();
	//const Cube* newCubes

};

