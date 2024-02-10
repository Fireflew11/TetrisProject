#include "T_Shape.h"

//T_Shape::T_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[3], useColors, startingX, startingY, createCubes(startingX, startingY))
//{}
/*
const Cube* T_Shape::createCubes(int startingX, int startingY)
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y, gameConfig::COLORS[3]),
        Cube(x - 1, y, gameConfig::COLORS[3]),
        Cube(x + 1, y , gameConfig::COLORS[3]),
        Cube(x , y+1, gameConfig::COLORS[3]) };
    return cubes;
}
*/
T_Shape::T_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[3], useColors, startingX, startingY,

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY, gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX,startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX +2 , startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY+1 , gameConfig::COLORS[3]) })
{}