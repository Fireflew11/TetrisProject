#include "Bomb.h"
#include "gameConfig.h"


//Bomb::Bomb(gameConfig::PlayerType playerType, bool useColors): Shape(gameConfig::COLORS[8], true),cube(playerType,useColors){}

Bomb::Bomb(bool useColors, int startingX, int startingY) :Shape(gameConfig::COLORS[8], useColors, startingX, startingY), cube(startingX +(gameConfig::GAME_WIDTH)/2 +1, startingY, gameConfig::COLORS[8])
{}


void Bomb:: drawShape(bool isActive)const
{
	cube.drawCube(isActive,getColor());
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

	for (int y = bombY - blastRange; y < bombY + blastRange; y++)
	{
		for (int x = bombX - blastRange; x < bombX + blastRange; x++)
		{
			if (board.isValidPosition(x, y) == true)
				board.set_cube_active_in_board_game(x, y);
		}
	}
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