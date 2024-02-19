#include "T_Shape.h"


/**********************************************************************
 Function name:Constructor T_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the T_Shape class. Initializes a T-shaped tetromino with the specified attributes.
 **********************************************************************/
T_Shape::T_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[3], useColors, startingX, startingY, 4, 

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY, gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX-1,startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX +1 , startingY , gameConfig::COLORS[3]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY+1 , gameConfig::COLORS[3]) })
{}