#pragma once
#include "Shape.h"


class Bomb: Shape
{
	Cube cube; 
public:
	static constexpr int blastRange = 4; 

	void drawShape(bool isActive = true) const override;
	void move_Left(const Board& board)override;
	void move_Right(const Board& board)override;
	bool continueMovingDown(const Board& board)override;



	Bomb(gameConfig::PlayerType playerType, bool useColors);

	void explosion(Board& board);

};

