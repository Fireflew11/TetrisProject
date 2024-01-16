#include <iostream>
#include <windows.h>
#include "Player.h"
#include "gameConfig.h"
#include "Game.h"

int main() 
{
	/*
	Player p1(0, 0);
	p1.getPlayerBoard().display_board(0);
	p1.initializeMoveFunctions(1);
	p1.GameLoop();
	*/

	Game game1; 
	game1.startGame();
	
	


	gotoxy(0, gameConfig::GAME_HEIGHT + 1);
}

