#include "L_Shape.h"

//L_Shape::L_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[7], useColors, startingX, startingY, )
//{}

L_Shape::L_Shape(bool useColors, int startingX, int startingY): ComplexShape(gameConfig::COLORS[7], useColors, startingX, startingY,
          {Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY + 1, gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY , gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY+2, gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 2,startingY +2 , gameConfig::COLORS[7])})
{}

/*
const Cube* L_Shape::createCubes(int startingX, int startingY)
{
    int x = gameConfig::GAME_WIDTH / 2 + startingX + 1;
    int y = startingY;
    Cube cubes[4] = {
        Cube(x, y + 1, gameConfig::COLORS[7]),
        Cube(x, y, gameConfig::COLORS[7]),
        Cube(x, y + 2, gameConfig::COLORS[7]),
        Cube(x+1, y + 2, gameConfig::COLORS[7]) };
    return cubes;
}
*/

