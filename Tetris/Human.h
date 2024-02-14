#pragma once
#include "Player.h"
#include <map>
#include <functional>

class Human : public Player {
private:
    map<char, ShapeFunctionType> moveFunctions;
public:
    Human(gameConfig::PlayerType playerType);
    void decideMove(Shape& shape, char key) override;
};