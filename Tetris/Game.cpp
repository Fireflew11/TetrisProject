#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"

void Game::keyChoice(gameConfig::keys key, Shape& shape, const Board& board)
{

    switch (key)
    {
    case gameConfig::keys::LP_RIGHT:
    case gameConfig::keys::RP_RIGHT: 
        shape.move_Right(board); 
        break;
    case gameConfig::keys::LP_LEFT:
    case gameConfig::keys::RP_LEFT:
        shape.move_Left(board); 
        break;
    case gameConfig::keys::LP_ROTATE_CLOCK_WISE:
    case gameConfig::keys::RP_ROTATE_CLOCK_WISE:
        shape.rotate_Clock_wise2(board); 
        break;
    case gameConfig::keys::LP_ROTATE_COUNTER_CLOCK_WISE:
    case gameConfig::keys::RP_ROTATE_COUNTER_CLOCK_WISE:
        shape.rotate_CounterClock_wise2(board); 
        break;
    case gameConfig::keys::LP_DROP:
    case gameConfig::keys::RP_DROP:
        shape.drop(board); 
            break;
    }
}

