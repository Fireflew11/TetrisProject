#include "Computer.h"
#include <algorithm>
#include <functional>
#include "ComplexShape.h"
#include "Bomb.h"

enum class ScoringWeights { maxHeightWeight = -80, fillWellWeight = 35, clearedTwoLinesWeight = 200,
clearedThreeLinesWeight = 1000, clearedFourLinesWeight = 2000, smoothnessDifferenceWeight = -20,
holeWeight = -80};

void Computer::calculateMove(Shape *temp, int& maxScoreForMove) {
	int isBestMove;
	switch (difficulty)
	{
	case gameConfig::Difficulty::BEST:
		isBestMove = 1;
		break;
	case gameConfig::Difficulty::GOOD:
		isBestMove = rand() % 40;
		break;
	case gameConfig::Difficulty::NOVICE:
		isBestMove = rand() % 10;
		break;
	}
	if (isBestMove == 0) {
		curRotationTarget = rand() % 4;
		curXTarget = rand() % gameConfig::GAME_WIDTH + getPlayerBoard().getStartingX();
	}
	else {
		int rotationsAmount = temp->getDifferentRotations();
		for (int i = 0; i < rotationsAmount; i++)
		{
			checkAllMoves(*temp, i, maxScoreForMove);
			if (!temp->rotate_Clock_wise(getPlayerBoard()))
			{
				temp->continueMovingDown(getPlayerBoard());
				temp->rotate_Clock_wise(getPlayerBoard());
			}
		}
	}
}
void Computer::decideMove(Shape& shape, char key)
{
	int maxScoreForMove = MIN_SCORE_VALUE;
	/*
	Shape* temp;
	createTempShape(shape, temp);
	if (curXTarget == 0) {
		int rotationsAmount = temp->getDifferentRotations();
		for (int i = 0; i < rotationsAmount; i++)
		{
			checkAllMoves(*temp, i, maxScoreForMove);
			if(!temp->rotate_Clock_wise(getPlayerBoard()))
			{
				temp->continueMovingDown(getPlayerBoard());
				temp->rotate_Clock_wise(getPlayerBoard());
			}
		}
	}
	*/
	Shape* temp;
	createTempShape(shape, temp);
	if (curXTarget == 0)
		calculateMove(temp, maxScoreForMove);

	int curX = temp->getX();
	shape.drawShape(false);
	if (curRotationTarget > 0) {
		if (curRotationTarget == 3) {
			if (shape.rotate_CounterClock_wise(getPlayerBoard()))
				curRotationTarget = 0;
		}
		else {
			if (shape.rotate_Clock_wise(getPlayerBoard()))
				curRotationTarget--;
		}
	}
	else if (curX > curXTarget) {
		shape.move_Left(getPlayerBoard());
	}
	else if (curX < curXTarget) {
		shape.move_Right(getPlayerBoard());
	}
	
	else
		shape.drop(getPlayerBoard());
		
	
	shape.drawShape(true);
}

void Computer::checkAllMoves(Shape& shape, int rotation, int& maxScoreForMove)
{
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, true);
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, false);

}
void Computer::performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft) 
{
	Shape* tempShape = nullptr;
	createTempShape(shape, tempShape);
	bool didSucceed = false;
	while (!didSucceed) {
		Board tempBoard(playerBoard);
		tempShape->continueMovingDown(tempBoard);
		Shape* tempDown = nullptr;
		createTempShape(*tempShape, tempDown);

		while (tempDown->continueMovingDown(tempBoard));
		tempDown->implementShapeToBoard(tempBoard, false);

		int curScore = calculateScore(tempBoard, tempDown);
		if (curScore > maxScoreForMove)
		{
			maxScoreForMove = curScore;
			curRotationTarget = rotation;
			curXTarget = tempDown->getX();
		}
		didSucceed = !(moveLeft ? tempShape->move_Left(playerBoard) : tempShape->move_Right(playerBoard));
		delete tempDown;
	}

	delete tempShape;
}
void Computer::resetTargets()
{
	curRotationTarget = 0;
	curXTarget = 0;
}
void Computer::createTempShape(Shape& shape, Shape*& tempShape) 
{
	tempShape = shape.clone();
}

int Computer::calculateScore(Board board, Shape* shape) const
{
	int score = 0;
	score += board.fillsWell(shape) * (int)ScoringWeights::fillWellWeight;
	int linesCleard = board.clearFullLines();
	switch (linesCleard) {
	case 2:
		score += (int)ScoringWeights::clearedTwoLinesWeight;
		break;
	case 3:
		score += (int)ScoringWeights::clearedThreeLinesWeight;
		break;
	case 4:
		score += (int)ScoringWeights::clearedFourLinesWeight;
		break;

}
	score += board.getMaxHeight() * (int)ScoringWeights::maxHeightWeight;
	score += board.calculateSmoothness() * (int)ScoringWeights::smoothnessDifferenceWeight;
	score += board.getHolesAmount() * (int)ScoringWeights::holeWeight;
	return score;
}






