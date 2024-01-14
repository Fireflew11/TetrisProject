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
                    curShape.executeMove(keyPressed, playerBoard, moveFunctions);
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

void Player::initializeMoveFunctions(int id)
{
    for (int i = 0; i < 128; i++)
    {
        moveFunctions[i] = nullptr;
    }
    if (id == 1) {
        moveFunctions[(int)(gameConfig::keys::LP_ROTATE_CLOCK_WISE)] = &Shape::rotate_CounterClock_wise2;
        moveFunctions['s'] = &Shape::rotate_Clock_wise2;
        moveFunctions['a'] = &Shape::move_Left;
        moveFunctions['d'] = &Shape::move_Right;
        moveFunctions['x'] = &Shape::drop;

        moveFunctions['W'] = &Shape::rotate_CounterClock_wise2;
        moveFunctions['S'] = &Shape::rotate_Clock_wise2;
        moveFunctions['A'] = &Shape::move_Left;
        moveFunctions['D'] = &Shape::move_Right;
        moveFunctions['X'] = &Shape::drop;
    }
    else {
        moveFunctions['i'] = &Shape::rotate_CounterClock_wise2;
        moveFunctions['k'] = &Shape::rotate_Clock_wise2;
        moveFunctions['j'] = &Shape::move_Left;
        moveFunctions['l'] = &Shape::move_Right;
        moveFunctions['m'] = &Shape::drop;

        moveFunctions['I'] = &Shape::rotate_CounterClock_wise2;
        moveFunctions['K'] = &Shape::rotate_Clock_wise2;
        moveFunctions['J'] = &Shape::move_Left;
        moveFunctions['L'] = &Shape::move_Right;
        moveFunctions['M'] = &Shape::drop;
    }
}

