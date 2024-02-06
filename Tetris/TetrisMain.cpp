#include <iostream>
#include <windows.h>
#include "Player.h"
#include "gameConfig.h"
#include "Game.h"

int main() 
{
	/*
	SetCurserVisibility(false);
	Game game1; 
	game1.startGame();
	cout << "Thanks for playing!!" << endl;
	*/
	Computer c(gameConfig::PlayerType::LEFT_PLAYER);
	Shape s1(c.getPlayerType());
	list<list<Player::ShapeFunctionType>> lst = c.getAllPossibleMoves(s1);

}

