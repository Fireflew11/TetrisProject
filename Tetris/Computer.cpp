#include "Computer.h"
#include <algorithm>
#include <functional>
#include "ComplexShape.h"
#include "Bomb.h"

int Computer::getRotationAmount(ComplexShape& shape)
{
	int type = shape.getShapeType();
	if (type == 4)
		return 1;
	if (type == 1 || type == 5 || type == 7)
		return 2;
	else
		return 4;
}

void Computer::decideMove(Shape& shape, char key)
{
	int maxScoreForMove = -1000000;
	Shape* temp;
	createTempShape(shape, temp);

	if (curXTarget == 0) {
		//int rotationsAmount = getRotationAmount(*dynamic_cast<ComplexShape*>(&shape));
		for (int i = 0; i < 4; i++)
		{
			checkAllMoves(*temp, i, maxScoreForMove);
			if(!temp->rotate_Clock_wise(getPlayerBoard()))
			{
				temp->continueMovingDown(getPlayerBoard());
				temp->rotate_Clock_wise(getPlayerBoard());
			}
		}
	}
	int curX = temp->getX();
	shape.drawShape(false);
	if (curRotationTarget > 0) {
		if (shape.rotate_Clock_wise(getPlayerBoard())) 
			curRotationTarget--;
	}
	else if (curX > curXTarget) {
		shape.move_Left(getPlayerBoard());
	}
	else if (curX < curXTarget) {
		shape.move_Right(getPlayerBoard());
	}
	/*
	else
		shape.drop(getPlayerBoard());
		*/
	
	shape.drawShape(true);
}

void Computer::checkAllMoves(Shape& shape, int rotation, int& maxScoreForMove)
{
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, true);
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, false);

}
void Computer::performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft) {
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
void Computer::createTempShape(Shape& shape, Shape*& tempShape) {
	tempShape = shape.clone();
}

int Computer::calculateScore(Board board, Shape* shape) const
{
	int score = 0;
	ComplexShape *tempShape = dynamic_cast<ComplexShape*>(shape);
	if (tempShape)
		score += tempShape->fillsWell(board) * 35;
	int linesCleard = board.clearFullLines();
	switch (linesCleard) {
	case 2:
		score += 200;
		break;
	case 3:
		score += 1000;
		break;
	case 4:
		score += 2000;
		break;

}
	//score += board.clearFullLines() * (int)ScoringVariables::ClearLine;
	score += board.getMaxHeight() * -30;
	score += board.calculateSmoothness() * -20;
	score += board.getHolesAmount() * -80;
	//score += board.preventTallTowersScore();

	return score;
}






