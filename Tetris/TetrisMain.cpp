#include <iostream>
#include <windows.h>
#include "Player.h"

int main() {
	Player p1;
	Board& b1 = p1.getPlayerBoard();
	Shape* checkShape = new Shape(14, 1);
	b1.setCurShape(checkShape);
	b1.display_board(0);
	b1.getCurShape()->drawShape();
	for (int i = 0; i < 5; i++)
	{
		p1.keyChoice();
	}
	
	/*
	(*checkShape).drawShape();
	Sleep(1000);
	(*checkShape).rotateShape(LEFT);
	Sleep(1000);
	(*checkShape).rotateShape(LEFT);
	Sleep(1000);
	(*checkShape).rotateShape(LEFT);
	Sleep(1000);
	(*checkShape).rotateShape(LEFT);
	Sleep(1000);
	*/
	if(checkShape->getId() != 2)
		(*checkShape).deleteCubesBlock();

	gotoxy(0, b1.get_height() + 1);
}

