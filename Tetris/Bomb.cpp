#include "Bomb.h"
#include "gameConfig.h"


//Bomb::Bomb(gameConfig::PlayerType playerType, bool useColors): Shape(gameConfig::COLORS[8], true),cube(playerType,useColors){}


Bomb::Bomb(bool useColors, int startingX, int startingY) :Shape(gameConfig::COLORS[8], useColors, startingX, startingY), cube(startingX +(gameConfig::GAME_WIDTH)/2 , startingY, gameConfig::COLORS[8])
{}
const Cube& Bomb::getCube() const
{
	return cube;
}

Shape* Bomb::clone() const
{
	return new Bomb(*this);
}




void Bomb:: drawShape(bool isActive)const
{
	cube.drawCube(isActive, getUseColors());
}

bool Bomb::move_Left(const Board& board)
{
	bool res = false;
	int x = cube.get_X()-1;
	int y = cube.get_Y(); 

	Cube tempCube(x, y, getColor(), true); 
	Bomb temp = *this; 
	temp.cube= tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp; 
		res = true;
	}
	return res;

}
bool Bomb:: move_Right(const Board& board)
{
	bool res = false;
	int x = cube.get_X() + 1;
	int y = cube.get_Y();

	Cube tempCube(x, y, getColor(), true);
	Bomb temp = *this;
	temp.cube = tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp;
		res = true;
	}
	return res;

}
bool Bomb::continueMovingDown(const Board& board)
{
	Bomb temp = *this;
	int y = cube.get_Y() + 1;
	Cube tempCube(cube.get_X(), y, getColor(), true);
	temp.cube = tempCube; 

	if (temp.check_valid_move(board))
	{
		*this = temp;      // Update the shape
		return true;
	}

	return false;
}





void Bomb::explosion(Board& board,bool isDraw) const
{
	
	int bombX = cube.get_X(); 
	int bombY = cube.get_Y(); 

	int startingXExplosion = 0;
	int startingYExplosion = 0;
	int rangeX = 0;
	int rangeY = 0;
	//הוספת ניקוד
	//שימוש בטווח לפיצוץ 
	CalculateBlastRange(bombX, bombY, startingXExplosion, startingYExplosion, rangeX, rangeY, board);
	for (int y = bombY - blastRange; y <= bombY + blastRange; y++)
	{
		for (int x = bombX - blastRange; x <= bombX + blastRange; x++)
		{
			if (board.isValidExplosion(x, y) == true)
				board.set_cube_active_in_board_game(x, y);
		}
	}

	board.moveCubesDownAfterExplosion(startingXExplosion, startingYExplosion, rangeX, rangeY); 
	if (isDraw)
		board.drawBoardCubes(); 
}

void Bomb::implementShapeToBoard(Board& board, bool isDraw) const
{
	explosion(board, isDraw);
}

bool Bomb::check_valid_move(const Board& board) const
{
	return board.isValidPosition(cube.get_X(),cube.get_Y());
}


void Bomb::CalculateBlastRange(int bombX, int bombY, int &startingXExplosion, int& startingYExplosion, int&rangeX, int& rangeY, const Board& board) const
{
	bool isFirstValidX = false;
	bool isFirstValidY = false;	
		for (int y = bombY - blastRange; (y <= bombY + blastRange) && (board.isValidYExplosion(y) == true); y++)
		{
			rangeY++;
			if (isFirstValidY == false)
			{
				startingYExplosion = y - board.getStartingY();
				isFirstValidY = true;
			}
		}
		for (int x = fmax(bombX - blastRange, board.getStartingX()); (x <= bombX + blastRange) && (board.isValidXExplosion(x) == true); x++)
		{
			rangeX++;
			if (isFirstValidX == false)
			{
				startingXExplosion = x;
				isFirstValidX = true;
			}
		}
}



int Bomb::getX() const
{
	return cube.get_X();
}

