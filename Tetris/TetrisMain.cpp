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

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	Game game1; 
	game1.startGame();
	
	


	gotoxy(0, gameConfig::GAME_HEIGHT + 1);
}

