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


 void Player::updateScore(int numClearedLines)
 {
     switch (numClearedLines)
     {
     case 1:
         score += static_cast<int>(gameConfig::Score::SINGLE_LINE_CLEAR);
         displayScore();
         break;
     case 2:
         score += static_cast<int>(gameConfig::Score::DOUBLE_LINE_CLEAR);
         displayScore();
         break;
     case 3:
         score += static_cast<int>(gameConfig::Score::TRIPLE_LINE_CLEAR);
         displayScore();
         break;
     case 4:
         score += static_cast<int>(gameConfig::Score::TETRIS_LINE_CLEAR);
         displayScore();
         break;
     default:
         break;
     }
 }

 void Player::displayScore()
 {
     if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
         gotoxy(gameConfig::MAX_X_LEFT_BOARD + 2, 2);
     else
         gotoxy(gameConfig::MAX_X_RIGHT_BOARD + 2, 2);
     cout << "Player " << (int)playerType << " score: " << score;
 }

