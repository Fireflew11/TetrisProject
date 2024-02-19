#include "L_Shape.h"

/**********************************************************************
 Function name:Constructor L_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the L_Shape class. Initializes a L-shaped tetromino with the specified attributes.
 **********************************************************************/
L_Shape::L_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[7], useColors, startingX, startingY,4,
    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 1, gameConfig::COLORS[7]),
    Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY , gameConfig::COLORS[7]),
    Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 2, gameConfig::COLORS[7]),
    Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY + 2 , gameConfig::COLORS[7]) })
{}

