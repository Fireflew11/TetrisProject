#include "Cube.h"
#include "gameConfig.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

int Cube::get_X() const
{
	return coord.X; 
}
int Cube::get_Y() const
{
	return coord.Y;
}
bool Cube::getIsActive()const 
{
	return isActive;
}
void Cube::setIsActive(const bool isActive) 
{
	this->isActive = isActive;
}

/*
void Cube::drawCube(const bool isActive, const int size) const 
{
    gotoxy(coord.X, coord.Y);
    if (isActive)
    {
        cout << "\033[41m";  // red background color
    }
    else
        cout << "\033[40m"; // black background color

    cout << "  ";

    cout << "\033[0m";   // Reset ANSI escape codes
}
*/

void Cube::drawCube(const bool isActive, bool useColors) const
{
    gotoxy(coord.X, coord.Y);

    if (isActive && useColors)
    {
        // Set background color based on the cube's color
        cout << "\033[48;5;" << color << "m";

        // Use a different text color for active cubes (e.g., white)
        cout << "\033[38;5;15m";
    }
    else
    {
            // Set background color to black
            cout << "\033[40m";

            // Use black text color for inactive cubes
            //cout << "\033[38;5;0m";
    }


    if (!useColors&& isActive)
        cout << "**";
    else
        cout << "  ";

    // Reset colors
    cout << "\033[0m";
}




void Cube::set_coord(const int& x, const int& y)
{
    coord.X = x; 
    coord.Y = y;
}



Cube::Cube(int x , int y , int colorIndex, bool active )
{
    coord.X = x;
    coord.Y = y;
    color = colorIndex;
    isActive = active;
}


void  Cube::set_X(const int& x)
{
	coord.X = x; 
}
void Cube::set_Y(const int& y)
{
	coord.Y = y; 
}

void Cube::setColor(const int& color)
{
    this->color = color;
}










