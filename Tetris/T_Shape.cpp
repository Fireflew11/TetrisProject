#include "T_Shape.h"



T_Shape::T_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[3], useColors, startingX, startingY,

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY, gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX-1,startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX +1 , startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY+1 , gameConfig::COLORS[3]) })
{}