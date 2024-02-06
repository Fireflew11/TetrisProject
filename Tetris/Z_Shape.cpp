#include "Z_Shape.h"

Z_Shape::Z_Shape(bool useColors, int startingX, int startingY): ComplexShape(gameConfig::COLORS[5], useColors, startingX, startingY, createCubes(startingX, startingY))
{}

const Cube* Z_Shape::createCubes(int startingX, int startingY)
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y + 1, gameConfig::COLORS[5]),
        Cube(x - 1, y, gameConfig::COLORS[5]),
        Cube(x , y, gameConfig::COLORS[5]),
        Cube(x+1 , y+1 ,gameConfig::COLORS[5]) };
    return cubes;
}