#include "S_Shape.h"

S_Shape::S_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[4], useColors, startingX, startingY, createCubes(startingX, startingY))
{}

const Cube* S_Shape::createCubes(int startingX, int startingY)
{
   int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
   int y = startingY;
    Cube cubes[4] = {
        Cube(x, y +1, gameConfig::COLORS[4]),
        Cube(x + 1, y, gameConfig::COLORS[4]),
        Cube(x-1, y + 1, gameConfig::COLORS[4]),
        Cube(x , y, gameConfig::COLORS[4]) };
    return cubes;
}
