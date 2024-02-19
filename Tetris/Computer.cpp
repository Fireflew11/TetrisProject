#include "Computer.h"
#include <algorithm>
#include <functional>
#include "ComplexShape.h"
#include "Bomb.h"


/**********************************************************************
Function name:calculateMove
Input: Shape* temp, int& maxScoreForMove
Output:--
Function: Determines the best move for the computer player based on the current game state and difficulty level.
Updates the maximum score for the move.
**********************************************************************/
void Computer::calculateMove(Shape *temp, int& maxScoreForMove) 
{
	int isBestMove = getIsBestMove(); 
	if (isBestMove == 0) 
	{
		curRotationTarget = rand() % temp->getDifferentRotations();
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

/**********************************************************************
Function name: getIsBestMove
Input: None
Output: int
Function: Determines if the current move should be the best move based on the difficulty level.
Returns 0 if the move should not be the best move, otherwise returns a random value.
**********************************************************************/
int Computer::getIsBestMove()
{
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
	default:
		isBestMove = 1;
		break;
	}
	return isBestMove; 
}

/**********************************************************************
Function name:decideMove
Input: Shape& shape, char key
Output:--
Function: Decides the next move for the computer player.
Calculates the best move based on the current game state and difficulty level.
Executes the next move.
**********************************************************************/
void Computer::decideMove(Shape& shape, char key)
{
	int maxScoreForMove = MIN_SCORE_VALUE;
	Shape* temp;
	createTempShape(shape, temp);
	if (curXTarget == 0)
		calculateMove(temp, maxScoreForMove);
	makeNextMove(shape);
}

/**********************************************************************
Function name:makeNextMove
Input: Shape& shape
Output:--
Function: Executes the next move for the computer player based on the calculated target positions.
**********************************************************************/
void Computer::makeNextMove(Shape& shape)
{
	int curX = shape.getX();
	shape.drawShape(false);
	if (curRotationTarget > 0)
	{
		if (curRotationTarget == 3)
		{
			if (shape.rotate_CounterClock_wise(getPlayerBoard()))
				curRotationTarget = 0;
		}
		else {
			if (shape.rotate_Clock_wise(getPlayerBoard()))
				curRotationTarget--;
		}
	}
	else if (curX > curXTarget)
	{
		shape.move_Left(getPlayerBoard());
	}
	else if (curX < curXTarget)
	{
		shape.move_Right(getPlayerBoard());
	}

	shape.drawShape(true);
}

/**********************************************************************
Function name: checkAllMoves
Input: Shape& shape, int rotation, int& maxScoreForMove
Output:--
Function: Checks all possible moves (left and right) for the given shape rotation.
Updates the maximum score, and targets for the move.
**********************************************************************/
void Computer::checkAllMoves(Shape& shape, int rotation, int& maxScoreForMove)
{
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, true);
	performMoves(shape, getPlayerBoard(), rotation, maxScoreForMove, false);

}

/**********************************************************************
Function name:performMoves
Input: Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft
Output:--
Function:Performs the sequence of moves for the given shape rotation and direction (left or right).
Updates the maximum score, and targets for the move.
**********************************************************************/
void Computer::performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft) 
{
	Shape* tempShape = nullptr;
	createTempShape(shape, tempShape);
	bool didSucceed = false;
	while (!didSucceed) 
	{
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

/**********************************************************************
Function name:resetTargets
Input: None
Output:--
Function:Resets the target positions for the computer player's next move.
**********************************************************************/
void Computer::resetTargets()
{
	curRotationTarget = 0;
	curXTarget = 0;
}

/**********************************************************************
Function name: createTempShape
Input: Shape& shape, Shape*& tempShape
Output:--
Function: Creates a temporary shape for calculating potential moves.
**********************************************************************/
void Computer::createTempShape(Shape& shape, Shape*& tempShape) 
{
	tempShape = shape.clone();
}

/**********************************************************************
Function name: calculateScore
Input: Board board,Shape* shape
Output: int
Function: Calculates the score for a potential move based on the current game state and shape placement.
Returns the calculated score.
**********************************************************************/
int Computer::calculateScore(Board board, Shape* shape) const
{
	int score = 0;
	score += board.fillsWell(shape) * static_cast<int>(ScoringWeights::fillWellWeight);
	int linesCleard = board.clearFullLines();
	switch (linesCleard) 
	{
	case 2:
		score += static_cast<int>(ScoringWeights::clearedTwoLinesWeight);
		break;
	case 3:
		score += static_cast<int>(ScoringWeights::clearedThreeLinesWeight);
		break;
	case 4:
		score += static_cast<int>(ScoringWeights::clearedFourLinesWeight);
		break;

}
	score += board.getMaxHeight() * static_cast<int>(ScoringWeights::maxHeightWeight);
	score += board.calculateSmoothness() * static_cast<int>(ScoringWeights::smoothnessDifferenceWeight);
	score += board.getHolesAmount() * static_cast<int>(ScoringWeights::holeWeight);
	return score;
}






