#pragma once
#include "Player.h"
#include <map>
#include <functional>
/**********************************************************************
The Human class represents a human player in the game. It inherits from
the Player class and implements methods for handling human player
movements.

Attributes:
- moveFunctions: A map associating character keys with functions representing different movements.
**********************************************************************/
class Human : public Player 
{
private:
    std::map<char, ShapeFunctionType> moveFunctions;
public:
    Human(gameConfig::PlayerType playerType);
    void decideMove(Shape& shape, char key) override;
    ~Human() override {};
};