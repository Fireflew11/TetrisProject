#include "Z_Shape.h"


/**********************************************************************
 Function name:Constructor Z_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the Z_Shape class. Initializes a Z-shaped tetromino with the specified attributes.
 **********************************************************************/
Z_Shape::Z_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[5], useColors, startingX, startingY, 2,

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY+1, gameConfig::COLORS[5]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX-1,startingY , gameConfig::COLORS[5]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX  , startingY , gameConfig::COLORS[5]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY + 1 , gameConfig::COLORS[5]) })
{}