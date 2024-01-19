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
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    if (isActive)
        cout << "*";
    else
        cout << " ";

    // Reset text and background colors to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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










