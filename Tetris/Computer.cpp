#include "Computer.h"
#include <algorithm>
#include <functional>
#include "ComplexShape.h"
#include "Bomb.h"

bool Computer::decideMove(Shape& shape, char key)
{
	if (key == gameConfig::ESC)
		return true;
	int maxScoreForMove = -1000000;
	Shape* temp;
	createTempShape(shape, temp);
	if (curXTarget == 0) {
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
	int curX;
	ComplexShape* complexTemp = dynamic_cast<ComplexShape*>(&shape);
	Bomb* bombTemp = dynamic_cast<Bomb*>(&shape);
	if (complexTemp != nullptr)
		curX = complexTemp->get_cubes()[0].get_X();
	else if (bombTemp != nullptr)
		curX = bombTemp->getCube().get_X();
	shape.drawShape(false);
	if (curRotationTarget > 0) {
		if (!shape.rotate_Clock_wise(getPlayerBoard())) {
			shape.continueMovingDown(getPlayerBoard());
			shape.rotate_Clock_wise(getPlayerBoard());
		}
		curRotationTarget--;
	}
	else if (curX > curXTarget)
		shape.move_Left(getPlayerBoard());
	else if (curX < curXTarget)
		shape.move_Right(getPlayerBoard());
	else
		shape.drop(getPlayerBoard());
	shape.drawShape(true);
	return false;
}

void Computer::checkAllMoves(Shape& shape, int rotation, int& maxScoreForMove)
{
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, true);
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, false);

}
void Computer::performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft) {
	Shape* tempShape = nullptr;
	createTempShape(shape, tempShape);

	while ((moveLeft ? tempShape->move_Left(playerBoard) : tempShape->move_Right(playerBoard))) {
		Board tempBoard(playerBoard);
		Shape* tempDown = nullptr;
		createTempShape(*tempShape, tempDown);

		while (tempDown->continueMovingDown(tempBoard));
		tempDown->implementShapeToBoard(tempBoard);
		int curScore = calculateScore(tempBoard, tempDown);
		if (curScore > maxScoreForMove)
		{
			maxScoreForMove = curScore;
			curRotationTarget = rotation;
			ComplexShape* complexTemp = dynamic_cast<ComplexShape*>(tempDown);
			Bomb* bombTemp = dynamic_cast<Bomb*>(tempDown);
			if (complexTemp != nullptr)
				curXTarget = complexTemp->get_cubes()[0].get_X();
			else if (bombTemp != nullptr)
				curXTarget = bombTemp->getCube().get_X();
		}
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
	if (tempShape->fillsWell(board))
		score += 100;
	score += board.clearFullLines() * (int)ScoringVariables::ClearLine;
	score += board.getMaxHeight() * -30;
	score += board.calculateSmoothness() * -10;
	score += board.getHolesAmount() * -80;

	
	


	return score;
}






