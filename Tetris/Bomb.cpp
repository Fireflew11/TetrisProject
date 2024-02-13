#include "Bomb.h"
#include "gameConfig.h"


//Bomb::Bomb(gameConfig::PlayerType playerType, bool useColors): Shape(gameConfig::COLORS[8], true),cube(playerType,useColors){}

Bomb::Bomb(bool useColors, int startingX, int startingY) :Shape(gameConfig::COLORS[8], useColors, startingX, startingY), cube(startingX +(gameConfig::GAME_WIDTH)/2 , startingY, gameConfig::COLORS[8])
{}


void Bomb:: drawShape(bool isActive)const
{
	cube.drawCube(isActive, getUseColors());
}

void Bomb::move_Left(const Board& board)
{
	drawShape(false); 
	int x = cube.get_X()-1;
	int y = cube.get_Y(); 

	Cube tempCube(x, y, getColor(), true); 
	Bomb temp = *this; 
	temp.cube= tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp; 
	}
	drawShape(true); 

}
void Bomb:: move_Right(const Board& board)
{
	drawShape(false);
	int x = cube.get_X() + 1;
	int y = cube.get_Y();

	Cube tempCube(x, y, getColor(), true);
	Bomb temp = *this;
	temp.cube = tempCube;

	if (temp.check_valid_move(board))
	{
		*this = temp;
	}
	drawShape(true);

}
bool Bomb::continueMovingDown(const Board& board)
{
	Bomb temp = *this;
	int y = cube.get_Y() + 1;
	Cube tempCube(cube.get_X(), y, getColor(), true);
	temp.cube = tempCube; 

	if (temp.check_valid_move(board))
	{
		drawShape(false);  // Erase the current shape
		*this = temp;      // Update the shape
		drawShape(true);   // Draw the shape at its new position
		return true;
	}

	return false;
}





void Bomb::explosion(Board& board)
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
	board.drawBoardCubes(); 
}

void Bomb::implementShapeToBoard(Board& board)
{
	explosion(board);
}

bool Bomb::check_valid_move(const Board& board) const
{
	return board.isValidPosition(cube.get_X(),cube.get_Y());
}

void Bomb::CalculateBlastRange(int bombX, int bombY, int &startingXExplosion, int& startingYExplosion, int&rangeX, int& rangeY, const Board& board)
{
	bool isFirstValidX = false;
	bool isFirstValidY = false;	
		for (int y = bombY - blastRange; (y <= bombY + blastRange) && (board.isValidYExplosion(y) == true); y++)
		{
			rangeY++;
			if (isFirstValidY == false)
			{
				startingYExplosion = y;
				isFirstValidY = true;
			}
		}
		for (int x = bombX - blastRange; (x <= bombX + blastRange) && (board.isValidXExplosion(x) == true); x++)
		{
			rangeX++;
			if (isFirstValidX == false)
			{
				startingXExplosion = x;
				isFirstValidX = true;
			}
		}
}


