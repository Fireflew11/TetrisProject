#include "O_Shape.h"

O_Shape::O_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[2], useColors, startingX, startingY, createCubes(startingX, startingY))
{}

const Cube* O_Shape::createCubes(int startingX, int startingY)
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y , gameConfig::COLORS[2]),
        Cube(x+1, y, gameConfig::COLORS[2]),
        Cube(x, y + 1, gameConfig::COLORS[2]),
        Cube(x + 1, y + 1, gameConfig::COLORS[2]) };
    return cubes;
}

