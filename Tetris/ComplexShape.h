#pragma once
#include "Shape.h" 

class ComplexShape: public Shape
{
	Cube cubes[4];
	
public: 
	void drawShape(bool isActive = true) const override;
	bool move_Left(const Board& board)override;
	bool move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;
	//virtual void rotate_CounterClock_wise(const Board& board) ;
	//virtual void rotate_Clock_wise(const Board& board) ;
	bool rotate_CounterClock_wise(const Board& board) override;
	bool rotate_Clock_wise(const Board& board) override;
	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i, Cube cube);
	Shape* clone() const override;
	
	ComplexShape(int color, bool useColors, int startingX, int startingY, const Cube(&newCubes)[4]);
	bool fillsWell(const Board& board) const;
	



	Cube* const get_and_set_cubes();

	void implementShapeToBoard(Board& board) override; 
	bool check_valid_move(const Board& board) const override;


};

