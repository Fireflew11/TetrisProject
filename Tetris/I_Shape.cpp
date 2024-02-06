#include "I_Shape.h"
#include "gameConfig.h"



I_Shape::I_Shape(bool useColors, int startingX, int startingY): ComplexShape(gameConfig::COLORS[1], useColors, startingX, startingY, createCubes(startingX, startingY))
{}

const Cube* I_Shape ::createCubes(int startingX, int startingY) 
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y + 1, gameConfig::COLORS[1]),
        Cube(x, y, gameConfig::COLORS[1]),
        Cube(x, y + 2, gameConfig::COLORS[1]),
        Cube(x, y + 3, gameConfig::COLORS[1]) };
    return cubes;
}