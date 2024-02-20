#pragma once
#include "Shape.h"

/**********************************************************************
Class: Bomb

Description:
	Represents a bomb shape in the game, inheriting from the Shape class. It has the ability to explode and destroy cubes in a blast range.

**********************************************************************/
class Bomb:public Shape
{
	Cube cube; 
public:
	static constexpr int blastRange = 4; 
	void drawShape(bool isActive = true) const override;
	bool move_Left(const Board& board)override;
	bool move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;
    void implementShapeToBoard(Board& board, bool isDraw) const override;
	bool check_valid_move(const Board& board) const override;
	int getX() const override;
	bool rotate_CounterClock_wise(const Board& board) override { return false; };
	bool rotate_Clock_wise(const Board& board) override { return false; };
	const Cube& getCube() const;
	Shape* clone() const override;
	~Bomb() override {};
	Bomb(bool useColors, int startingX, int startingY);
	void Calculate_Valid_BlastRange_In_Board(int bombX, int bombY, int& startingXExplosion, int& startingYExplosion, int& rangeX, int& rangeY, const Board& board) const;
	void explosion(Board& board, bool isDraw) const;

};

