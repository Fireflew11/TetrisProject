#include <iostream>
#include <windows.h>
#include "Player.h"
#include "gameConfig.h"

int main() {
	Player p1;
	p1.getPlayerBoard().display_board(0);
	Shape curShape(10, 3, 3);
	curShape.drawShape();
	Sleep(1000);
	curShape.drawShape(false);
	curShape.rotate_Clock_wise2(p1.getPlayerBoard());
	curShape.drawShape();
	
	gotoxy(0, gameConfig::GAME_HEIGHT + 1);
}

