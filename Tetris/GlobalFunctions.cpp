#include"GlobalFunctions.h"
void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char toupperG(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return ch + 'A' - 'a';
    else
        return ch;
}
