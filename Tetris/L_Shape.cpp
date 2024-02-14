#include "L_Shape.h"



L_Shape::L_Shape(bool useColors, int startingX, int startingY): ComplexShape(gameConfig::COLORS[7], useColors, startingX, startingY, 3, 
          {Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY + 1, gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1,startingY , gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 1, startingY+2, gameConfig::COLORS[7]),
          Cube(gameConfig::GAME_WIDTH / 2 + startingX + 2,startingY +2 , gameConfig::COLORS[7])})
{}

