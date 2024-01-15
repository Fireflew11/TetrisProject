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

void Cube::drawCube(const bool isActive, int colorIndex, const int size) const
{
    gotoxy(coord.X, coord.Y);

    if (isActive)
    {
        cout << "\033[41m";
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    }
    else
    {
        cout << "\033[40m"; // black background color
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), gameConfig::COLORS[3]);
    }
    cout << "  ";
    cout << "\033[0m";
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), gameConfig::COLORS[0]);  
}




void Cube::set_coord(const int& x, const int& y)
{
    coord.X = x; 
    coord.Y = y;
}


/*
Cube::Cube(int x, int y, bool active)
{
    coord.X = x;
    coord.Y = y;
    isActive = active;
}


Cube::Cube(int x, int y, bool active)
{
    coord.X = x;
    coord.Y = y;
    isActive = active;
}
*/
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











//******////
/*
void Cube::move(gameConfig::Rkeys key)
{
    switch (key)
    {
    case gameConfig:: Rkeys:: LEFT: 
        coord.X += -2; 
        break; 
    case gameConfig::Rkeys::RIGHT:
        coord.X += 2;
        break;
    case gameConfig::Rkeys::ROTATE_CLOCK_WISE:
        //
        break;
    case gameConfig::Rkeys::ROTATE_COUNTER_CLOCK_WISE:
       //
        break;
    case gameConfig::Rkeys::DROP: 
        // 
        break;
    default:
        break;
    }

    //if(coord.X> gameConfig:: GAME_WIDTH)
    //if(x==0)


}


void Cube:: draw(char ch, int backcolor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE, backcolor); 
    gotoxy(coord.X + gameConfig::MIN_X, coord.Y + gameConfig::MIN_Y); 
    cout << ch; 
}

void check()
{
    while (true)
    {
        Cube cube(1, 1, true); 
        int keyPressed = 0; 
        if (_kbhit())
        {
            keyPressed == _getch(); 
            if (keyPressed == (int)gameConfig:: Rkeys::ESC)
                break;
        }

        cube.draw('*', 120); 
        Sleep(500);
        cube.move((gameConfig::Rkeys)keyPressed); 
        cube.draw(' '); 
        
        
    }


}


*/