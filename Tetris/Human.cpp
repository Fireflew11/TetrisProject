#include "Human.h"

/**********************************************************************
Function name: Human::Human
Input: gameConfig::PlayerType playerType
Output:--
Function:Constructor for the Human class. Initializes the moveFunctions map based on the player type.
**********************************************************************/
Human::Human(gameConfig::PlayerType playerType) : Player(playerType) 
{
    if (playerType == gameConfig::PlayerType::LEFT_PLAYER) {
        moveFunctions[(char)gameConfig::LeftKeys::LEFT] = &Shape::move_Left;
        moveFunctions[(char)gameConfig::LeftKeys::RIGHT] = &Shape::move_Right;
        moveFunctions[(char)gameConfig::LeftKeys::DROP] = &Shape::drop;
        moveFunctions[(char)gameConfig::LeftKeys::ROTATE_CLOCK_WISE] = &Shape::rotate_Clock_wise;
        moveFunctions[(char)gameConfig::LeftKeys::ROTATE_COUNTER_CLOCK_WISE] = &Shape::rotate_CounterClock_wise;
    }
    else {
        moveFunctions[(char)gameConfig::RightKeys::LEFT] = &Shape::move_Left;
        moveFunctions[(char)gameConfig::RightKeys::RIGHT] = &Shape::move_Right;
        moveFunctions[(char)gameConfig::RightKeys::DROP] = &Shape::drop;
        moveFunctions[(char)gameConfig::RightKeys::ROTATE_CLOCK_WISE] = &Shape::rotate_Clock_wise;
        moveFunctions[(char)gameConfig::RightKeys::ROTATE_COUNTER_CLOCK_WISE] = &Shape::rotate_CounterClock_wise;
    }
}

/**********************************************************************
Function name: Human::decideMove
Input: Shape& shape, char key
Output:--
Function:Decides the move based on the pressed key for the Human player.
**********************************************************************/
void Human::decideMove(Shape& shape, char key)
{
    auto func = moveFunctions.find(key);
    if (func != moveFunctions.end()) 
    {
        shape.drawShape(false);
        (shape.*(func->second))(getPlayerBoard());
        shape.drawShape(true);
    }
}