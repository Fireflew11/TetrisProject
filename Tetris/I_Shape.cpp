#include "I_Shape.h"
#include "gameConfig.h"



I_Shape::I_Shape(int color, bool useColors, int startingX, int startingY): ComplexShape(color, useColors, startingX, startingY,createCubes(startingX,startingY, color))
{}

const Cube* I_Shape ::createCubes(int startingX, int startingY, int color) 
{
    Cube cubes[4] = {
        Cube(startingX, startingY + 1, color),
        Cube(startingX, startingY, color),
        Cube(startingX, startingY + 2, color),
        Cube(startingX, startingY + 3, color) };
    return cubes;
}