#include"GlobalFunctions.h"

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//This function returns the upper case for any lower case letter
char toupperG(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return ch + 'A' - 'a';
    else
        return ch;
}
/**********************************************************************
Function name: SetCursorVisibility
Input: bool visible
Output:--
Function: Sets the visibility of the cursor in the console window.
If 'visible' is true, the cursor is displayed; if false, it is hidden.
**********************************************************************/
void SetCurserVisibility(bool visible)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visible; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);

}
