#pragma once
#include "Player.h"
#include "ComplexShape.h"
#include <list>
enum class ScoringVariables{ClearLine = 100, Hole = -50, maxHeight = -10, fillWell = 200};
class Computer : public Player
{
private:
	int curXTarget;
	int curRotationTarget;
	gameConfig::ComputerLevel level;
public:
	Computer(gameConfig::PlayerType playerType, gameConfig::ComputerLevel level) : Player(playerType), curXTarget(0), curRotationTarget(0), level(level) {}
	void decideMove(Shape& shape, char key) override;
	void checkAllMoves(Shape& shape, int rotation,int& maxScoreForMove);
	int calculateScore(Board board, Shape* shape) const;
	void createTempShape(Shape& shape, Shape*& tempShape);
	void performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft);
	void resetTargets();
	int getRotationAmount(ComplexShape& shape);
};

