#pragma once
#include "Player.h"
#include "ComplexShape.h"


/**********************************************************************
Class name: Computer
Description:
    The Computer class represents a player controlled by the computer in a Tetris-like game. It inherits from the Player class and implements AI logic to make decisions about moving shapes on the game board.
    This class includes methods for deciding the next move of a shape, calculating scores based on the current game state, and managing targets for the computer player's moves.

Member variables:
    - int curXTarget: Represents the current target X coordinate for the next move.
    - int curRotationTarget: Represents the current target rotation for the next move.
    - gameConfig::Difficulty difficulty: Represents the difficulty level of the computer player.

Static Constants:
    - MIN_SCORE_VALUE: Represents the minimum possible score value.

Enums:
    - ScoringWeights: Represents the weights assigned to different scoring factors used by the computer player for decision making.
**********************************************************************/

class Computer : public Player
{
private:
	int curXTarget;
	int curRotationTarget;
	gameConfig::Difficulty difficulty;
public:
	static constexpr int MIN_SCORE_VALUE = -1000000;
	enum class ScoringWeights {maxHeightWeight = -80, fillWellWeight = 35, clearedTwoLinesWeight = 200,
	clearedThreeLinesWeight = 1000, clearedFourLinesWeight = 2000, smoothnessDifferenceWeight = -20,holeWeight = -80};

	Computer(gameConfig::PlayerType playerType, gameConfig::Difficulty difficulty) : Player(playerType), curXTarget(0), curRotationTarget(0), difficulty(difficulty) {}
	void decideMove(Shape& shape, char key) override;
	void checkAllMoves(Shape& shape, int rotation,int& maxScoreForMove);
	int calculateScore(Board board, Shape* shape) const;
	void createTempShape(Shape& shape, Shape*& tempShape);
	void performMoves(Shape& shape, Board& playerBoard, int rotation, int& maxScoreForMove, bool moveLeft);
	void resetTargets();
	void calculateMove(Shape* shape, int& maxScoreForMove); 
	void makeNextMove(Shape& shape);
	int getIsBestMove();
	~Computer()override {};

};

