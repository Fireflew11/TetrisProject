#include "Player.h"

enum { LeftPlayer = 1, RightPlayer=2 };


void Player::keyChoice()
{
    char key = _getch();

    switch (key) 
    {
    case 'a':
    case 'A':
        move_Left();
        break;
    case 'd':
    case 'D':
        move_Right();
        break;
    case 's':
    case 'S':
        rotate_Clock_wise();
        break;
    case 'w':
    case 'W':
        rotate_CounterClock_wise();
        break;
    case 'x':
    case 'X':
        drop_Shape();
        break;
}
