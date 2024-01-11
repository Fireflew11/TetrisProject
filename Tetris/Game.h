#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"

using namespace std;
class Game
{
	//Player LeftPlayer; 
	//Player RightPlayer; 
public: 

	void keyChoice(gameConfig::keys key, Shape& shape, const Board& board);

};

