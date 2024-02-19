#include "O_Shape.h"

/**********************************************************************
 Function name:Constructor O_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the O_Shape class. Initializes a O-shaped tetromino with the specified attributes.
 **********************************************************************/
O_Shape::O_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[2], useColors, startingX, startingY, 1 ,
    {Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY, gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY , gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 1, gameConfig::COLORS[2]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY + 1 , gameConfig::COLORS[2]) })
{}

