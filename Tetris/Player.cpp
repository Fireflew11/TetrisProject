#include "Player.h"




/*
Player::Player(int startingX, int startingY)
{
    playerBoard.setStartingX(startingX);
    playerBoard.setStartingY(startingY);
}
*/

Board& Player::getPlayerBoard()
{
    return playerBoard;
}


/*
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
*/




void Player::initializeMoveFunctions()
{
    for (int i = 0; i < 128; i++)
    {
        moveFunctions[i] = nullptr;
    }
    if (this->playerType == gameConfig::PlayerType::LEFT_PLAYER) 
    {
        moveFunctions['w'] = &Shape::rotate_CounterClock_wise2;
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



 Player:: Player(gameConfig:: PlayerType playerType) : score(0), playerType(playerType), playerBoard(
    (playerType ==  gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD,
    (playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig:: MIN_Y_LEFT_BOARD: gameConfig:: MIN_Y_RIGHT_BOARD) 
 {

 }


