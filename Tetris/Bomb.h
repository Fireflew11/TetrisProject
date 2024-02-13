#pragma once
#include "Shape.h"


class Bomb:public Shape
{
	Cube cube; 
public:
	static constexpr int blastRange = 4; 

	void drawShape(bool isActive = true) const override;
	void move_Left(const Board& board)override;
	void move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;
	void implementShapeToBoard(Board& board) override; 
	bool check_valid_move(const Board& board) const override;

	void rotate_CounterClock_wise(const Board& board) override{};
	void rotate_Clock_wise(const Board& board) override{};

	Bomb(bool useColors, int startingX, int startingY);
	//Bomb(gameConfig::PlayerType playerType, bool useColors);
	void CalculateBlastRange(int bombX, int bombY, int& startingXExplosion, int& startingYExplosion, int& rangeX, int& rangeY, const Board& board);
	void explosion(Board& board);

};

