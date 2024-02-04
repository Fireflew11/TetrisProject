#pragma once
#include "Player.h"
#include <list>
class Computer : public Player
{
private:
	list<ShapeFunctionType> movesOrderList;
public:
	Computer(gameConfig::PlayerType playerType) : Player(playerType) {}
	bool decideMove(Shape& shape, char key) override;
	void clearMovesList();
	list<list<Player::ShapeFunctionType>> getAllPossibleMoves(Shape& shape);
	list<Player::ShapeFunctionType> getCurList(Shape& shape);
};

