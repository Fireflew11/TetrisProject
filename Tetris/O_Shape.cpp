#include "O_Shape.h"


O_Shape::O_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[2], useColors, startingX, startingY, 4 ,

    {Cube(gameConfig::GAME_WIDTH / 2 + startingX + 2, startingY, gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY + 1 , gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY, gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 2,startingY + 1 , gameConfig::COLORS[2]) })
{}

