#include "J_Shape.h"


J_Shape::J_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[6], useColors, startingX, startingY, createCubes(startingX, startingY))
{}

const Cube* J_Shape::createCubes(int startingX, int startingY)
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y + 1, gameConfig::COLORS[6]),
        Cube(x, y, gameConfig::COLORS[6]),
        Cube(x-1, y + 2, gameConfig::COLORS[6]),
        Cube(x, y +2, gameConfig::COLORS[6]) };
    return cubes;
}