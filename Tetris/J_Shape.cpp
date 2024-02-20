#include "J_Shape.h"

/**********************************************************************
 Function name:Constructor J_Shape
 Input:bool useColors, int startingX, int startingY
 Output:--
 Function:Constructor for the J_Shape class. Initializes a J-shaped tetromino with the specified attributes.
 **********************************************************************/
J_Shape::J_Shape(bool useColors, int startingX, int startingY) : ComplexShape(gameConfig::COLORS[6], useColors, startingX, startingY, 4, 

    { Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY+1, gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX ,startingY , gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX , startingY + 2, gameConfig::COLORS[6]),
     Cube(gameConfig::GAME_WIDTH / 2 + startingX-1 ,startingY + 2 , gameConfig::COLORS[6]) })
{}