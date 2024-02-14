#include "S_Shape.h"



S_Shape::S_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[4], useColors, startingX, startingY, 5, 

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY + 1, gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 2,startingY , gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX  , startingY + 1, gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY , gameConfig::COLORS[4]) })
{}