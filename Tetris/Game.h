#pragma once

#include<iostream>
#include "gameConfig.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class player; 
enum class GameStatus{Running, Paused, NewGame, Ended};
class Game
{
	Player players[gameConfig::NUM_OF_PLAYERS];
	bool isGamePaused;
	GameStatus status;
public: 

	void keyChoice(gameConfig::keys key, Shape& shape, const Board& board, gameConfig::PlayerType player);
	void keyChoice(gameConfig::LeftKeys key, Shape& shape, const Board& board, gameConfig::PlayerType player);
	void keyChoice(gameConfig::RightKeys key , Shape& shape, const Board& board, gameConfig::PlayerType player);

	Game(); 
	void Print_Menu(); 
	void Present_instructionsand_keys(); 
	void GameLoop();
	bool getIsGamePaused();
	void setIsGamePaused(bool isGamePaused);
	void startGame();
	void printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn);
	void printSeparator();
};

