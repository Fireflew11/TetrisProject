#include "Player.h"



//enum { LeftPlayer = 1, RightPlayer=2 };

Player::Player(int startingX, int startingY)
{
    playerBoard.setStartingX(startingX);
    playerBoard.setStartingY(startingY);
}

Board& Player::getPlayerBoard()
{
    return playerBoard;
}

void Player::GameLoop()
{
    bool isGameOver = false;
    int keyPressed = 0;
    while (!isGameOver) {
        Shape curShape(gameConfig::GAME_WIDTH + 1, 1);
        while (true) {
            if (_kbhit()) {
                keyPressed = _getch();
                if (keyPressed == (int)gameConfig::keys::ESC) {
                    isGameOver = true;
                    break;
                }
                else {
                    curShape.executeMove(keyPressed, this->getPlayerBoard());
                }
            }
            else {
                Sleep(500);
                if (!curShape.continueMovingDown(playerBoard)) {
                    playerBoard.implementShapeToBoard(curShape);
                    break;
                }
            }
        }
    }
}

void Player:: updateScore(int numClearedLines)
{
    switch (numClearedLines)
    {
    case 1:
        score += static_cast<int>(gameConfig::Score::SINGLE_LINE_CLEAR);
        break;
    case 2:
        score += static_cast<int>(gameConfig::Score::DOUBLE_LINE_CLEAR);
        break;
    case 3:
        score += static_cast<int>(gameConfig::Score::TRIPLE_LINE_CLEAR);
        break;
    case 4:
        score += static_cast<int>(gameConfig::Score::TETRIS_LINE_CLEAR);
        break;
    default:
        break;
    }
}

