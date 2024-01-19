#include <iostream>
#include <windows.h>
#include "Player.h"
#include "gameConfig.h"
#include "Game.h"

int main() 
{
	
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	Game game1; 
	game1.startGame();
	
	


	gotoxy(0, gameConfig::GAME_HEIGHT + 1);
}

