#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"

using namespace std;

class player; 

class Game
{
	Player players[gameConfig::NUM_OF_PLAYERS];
public: 

	void keyChoice(gameConfig::keys key, Shape& shape, const Board& board, gameConfig::PlayerType player);
	Game(); 
	void Print_Menu(); 
	void Present_instructionsand_keys(); 
	void GameLoop();
};

