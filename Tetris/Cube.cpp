#include "Cube.h"
#include "gameConfig.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>


/**********************************************************************
Function name: get_X
Input: --
Output: int
Function: Returns the X-coordinate of the cube.
*********************************************************************/
int Cube::get_X() const
{
	return coord.X; 
}

/**********************************************************************
Function name: get_Y
Input: --
Output: int
Function: Returns the Y-coordinate of the cube.
**********************************************************************/
int Cube::get_Y() const
{
	return coord.Y;
}

/**********************************************************************
   Function name:getIsActive
   Input: --
   Output: bool 
   Function: Returns the activation status of the cube.
   **********************************************************************/
bool Cube::getIsActive()const 
{
	return isActive;
}

/**********************************************************************
Function name: setIsActive
Input: bool isActive 
Output: None
Function: Sets the activation status of the cube.
    **********************************************************************/
void Cube::setIsActive(const bool isActive) 
{
	this->isActive = isActive;
}


/**********************************************************************
Function name:drawCube
Input: bool isActive - Whether the cube is currently active
bool useColors - Whether to use colors in the console output
Output: --
Function: Draws the cube on the console screen with optional colors.
**********************************************************************/
void Cube::drawCube(const bool isActive, bool useColors) const
{
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the cursor position
    gotoxy(coord.X, coord.Y);

    // Set the text and background colors based on conditions
    if (useColors && isActive)
        SetConsoleTextAttribute(hConsole, color);
    else
        SetConsoleTextAttribute(hConsole, gameConfig::COLORS[0]);

    if (isActive)
        cout << "#";
    else
        cout << " ";

    // Reset text and background colors to default
    SetConsoleTextAttribute(hConsole, gameConfig::COLORS[0]);
}



/**********************************************************************
Function name: set_coord
Input: const int& x, const int& y
Output: --
Function:Sets the X and Y coordinates of the cube.
**********************************************************************/
void Cube::set_coord(const int& x, const int& y)
{
    coord.X = x; 
    coord.Y = y;
}


/**********************************************************************
Function name: Cube (constructor)
Input:int x , int y , int colorIndex, bool active
Output: --
Function: Constructor for the Cube class, initializes cube properties.
**********************************************************************/
Cube::Cube(int x , int y , int colorIndex, bool active )
{
    coord.X = x;
    coord.Y = y;
    color = colorIndex;
    isActive = active;
}

Cube::Cube(gameConfig::PlayerType playerType, int colorIndex, bool active)
{
    if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
    {
        coord.X = gameConfig::GAME_WIDTH / 2 + gameConfig::MIN_X_LEFT_BOARD + 1;///check 
        coord.Y = gameConfig::MIN_Y_LEFT_BOARD;
    }
    else
    {
        coord.X = gameConfig::GAME_WIDTH / 2 + gameConfig::MIN_X_RIGHT_BOARD + 1;// check 
        coord.Y = gameConfig::MIN_Y_RIGHT_BOARD;
    }
    color = colorIndex; 
    isActive = active; 
}

/**********************************************************************
Function name: set_X
Input: const int& x 
Output: --
Function: Sets the X-coordinate of the cube.
**********************************************************************/
void  Cube::set_X(const int& x)
{
	coord.X = x; 
}

/**********************************************************************
Function name: set_Y
Input: const int& y 
Output: --
Function: Sets the Y-coordinate of the cube.
**********************************************************************/
void Cube::set_Y(const int& y)
{
	coord.Y = y; 
}

/**********************************************************************
Function name:setColor
Input: const int& color 
 Output: --
Function:Sets the color of the cube.
**********************************************************************/
void Cube::setColor(const int& color)
{
    this->color = color;
}
WORD Cube::getColor()const
{
    return color; 
}










