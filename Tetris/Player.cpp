#include "Player.h"

enum { LeftPlayer = 1, RightPlayer=2 };

Player::Player() {

}

Board& Player::getPlayerBoard()
{
    return playerBoard;
}

void Player::keyChoice()
{
    
    while (!_kbhit()) {
        //playerboard.moveShapeDown
        //sleep(1000)
    }
    char key = _getch();
    switch (key)
    {
    case 'a':
    case 'A':
        playerBoard.rotate_Clock_wise(*(playerBoard.getCurShape()));
        break;
    case 'd':
    case 'D':
        //move_Right();
        break;
    case 's':
    case 'S':
        //rotate_Clock_wise();
        break;
    case 'w':
    case 'W':
        //rotate_CounterClock_wise();
        break;
    case 'x':
    case 'X':
        //drop_Shape();
        break;
    }
}
    
