#pragma once
#include "Shape.h" 

/**********************************************************************
Class name: ComplexShape
Description:
	The ComplexShape class represents a complex shape composed of multiple cubes. 
	It inherits from the Shape class and adds functionality to handle complex shapes in a game environment.
	This class manages the arrangement and movement of cubes that form the shape, including rotation, horizontal movement, and vertical movement.
	It also provides methods to check for valid moves and draw the shape on a game board.
**********************************************************************/
class ComplexShape: public Shape
{
	Cube cubes[4];
	
public: 
	void drawShape(bool isActive = true) const override;
	bool move_Left(const Board& board)override;
	bool move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;
	bool rotate_CounterClock_wise(const Board& board) override;
	bool rotate_Clock_wise(const Board& board) override;
	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i, Cube cube);
	Shape* clone() const override;
	ComplexShape(int color, bool useColors, int startingX, int startingY, int differentRotation, const Cube(&newCubes)[4]);
	int fillsWell(const Board& board) const;
	int getX() const override;
	~ComplexShape() override {};
	Cube* const get_and_set_cubes();
	void implementShapeToBoard(Board& board, bool isDraw) const override;
	bool check_valid_move(const Board& board) const override;



};

