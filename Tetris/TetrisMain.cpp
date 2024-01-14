#include <iostream>
#include <windows.h>
#include "Player.h"
#include "gameConfig.h"

int main() {
	Player p1(0, 0);
	p1.getPlayerBoard().display_board(0);
	p1.initializeMoveFunctions(1);
	p1.GameLoop();
	
	gotoxy(0, gameConfig::GAME_HEIGHT + 1);
}

