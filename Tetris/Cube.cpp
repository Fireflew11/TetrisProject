#include "Cube.h"
int Cube::get_X() const
{
	return coord.X; 
}
int Cube::get_Y() const
{
	return coord.Y;
}
bool Cube::getIsActive()const {
	return isActive;
}
void Cube::setIsActive(const bool isActive) {
	this->isActive = isActive;
}
void Cube::drawCube(const bool isActive, const int size) const {
    gotoxy(coord.X, coord.Y);
    if(isActive)
        cout << "\033[41m";  // red background color
    else
        cout << "\033[40m"; // black background color

    for (int i = 0; i < size; ++i) { //size is always 1 (I leave it as a variable so it will be easier to change in the future if needed)
        for (int j = 0; j < size * 2; ++j) {
            cout << " "; // The cube is represented by a single character (1x1)
        }
        gotoxy(coord.X, coord.Y);
    }

    cout << "\033[0m";   // Reset ANSI escape codes
}



void Cube::set_coord(const int& x, const int& y)
{
    coord.X = x; 
    coord.Y = y;
}

Cube::Cube(int x, int y, bool active)
{
    coord.X = x;
    coord.Y = y;
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
