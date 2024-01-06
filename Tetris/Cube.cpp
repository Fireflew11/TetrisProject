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
void Cube::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Cube::drawCube(int x, int y, const bool isActive, const int size) {
    gotoxy(x, y);
    if(isActive)
        cout << "\033[41m";  // red background color
    else
        cout << "\033[40m"; // black background color

    for (int i = 0; i < size; ++i) { //size is always 1 (I leave it as a variable so it will be easier to change in the future if needed)
        for (int j = 0; j < size * 2; ++j) {
            cout << " "; // The cube is represented by a single character (1x1)
        }
        gotoxy(x, ++y);
    }

    std::cout << "\033[0m";   // Reset ANSI escape codes
}
/*
void  Cube::set_X(const int& x)
{
	this->x = x; 
}
void Cube::set_Y(const int& y)
{
	this->y = y; 
}
*/