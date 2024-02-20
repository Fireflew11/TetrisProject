#include "S_Shape.h"


/**********************************************************************
 Function name:Constructor S_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the S_Shape class. Initializes a S-shaped tetromino with the specified attributes.
 **********************************************************************/
S_Shape::S_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[4], useColors, startingX, startingY, 2, 

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX, startingY + 1, gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY , gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX -1 , startingY + 1, gameConfig::COLORS[4]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY , gameConfig::COLORS[4]) })
{}