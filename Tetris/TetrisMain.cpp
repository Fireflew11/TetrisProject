#include <iostream>
#include <windows.h>
#include "Board.h"

int main() {
	Board board;
	board.display_board(0);
	board.display_board(50);
	Shape shape = Shape(14, 1, 1);
	for (int i = 0; i < 4; i++)
	{
		shape.get_cubes()[i].drawCube(true);
	}
	gotoxy(50, 50);
}

