#include "I_Shape.h"
#include "gameConfig.h"



I_Shape::I_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[1], useColors, startingX, startingY, 2, 

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 1, gameConfig::COLORS[1]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY , gameConfig::COLORS[1]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 2, gameConfig::COLORS[1]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY + 3 , gameConfig::COLORS[1]) })
{}
