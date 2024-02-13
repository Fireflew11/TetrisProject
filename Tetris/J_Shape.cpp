#include "J_Shape.h"


J_Shape::J_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[6], useColors, startingX, startingY,

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY+1, gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY , gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 2, gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY + 2 , gameConfig::COLORS[6]) })
{}