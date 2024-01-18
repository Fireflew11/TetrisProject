#include "Board.h"
#include "gameConfig.h"


void Board::print_Line() 
{
	for (int i = 0; i < gameConfig::GAME_WIDTH + 1; i++)
	{
		cout << "--";
	}
	cout << endl; 
}

void Board::display_board(int startingX) //board draws at (startingX, 0) at the moment
{
	int i, j;
	gotoxy(startingX, 0);
	Board::print_Line();
	gotoxy(startingX, 1);
	for (i = 1; i < gameConfig::GAME_HEIGHT + 2; i++)
	{
		cout << "|";
		for (j = 1; j < gameConfig::GAME_WIDTH + 1; j++)
			cout << "  "; 
		cout << "|" << endl; 
		gotoxy(startingX, i);
	}
	Board::print_Line(); 
	drawBoardCubes();
}

Board::Board(int starting_X, int starting_Y, bool useColors):startingX(starting_X),startingY(starting_Y), useColors(useColors)
{
	for (int i = 0; i <(int)gameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < (int)gameConfig::GAME_WIDTH; j++)
		{
			board_game[i][j].set_coord(startingX + 1 + j * 2, startingY + i); 
			board_game[i][j].setIsActive(false); 
			board_game[i][j].setColor(gameConfig::COLORS[0]);
		}
	}
}


const Cube(&Board::getBoardGame() const)[gameConfig::GAME_HEIGHT][gameConfig::GAME_WIDTH]
{
	return board_game;
}



bool Board::check_valid_move(const Shape& shape) const
{
	for (int i = 0; i < 4; i++)
	{
		int x = shape.get_cubes()[i].get_X(); 
		int y = shape.get_cubes()[i].get_Y();   
		if ((x >= gameConfig::GAME_WIDTH * 2 + startingX) || (x <= startingX))
			return false;
		if (y >= gameConfig::GAME_HEIGHT + 1 || y < 1)
			return false;
		if (board_game[y - 1][(x - startingX - 1) / 2].getIsActive() == true) 
			
			return false;

	}
	return true;

}

void Board::updateBoard(const Shape& shape)
{

	for (int i = 0; i < 4; ++i)
	{
		int x = shape.get_cubes()[i].get_X();
		int y = shape.get_cubes()[i].get_Y();
		board_game[x/2 - startingX][y-startingY-1].setIsActive(true);
	}
}

void Board::clearLine(int index_line)
{

	for (int i = index_line; i > 0; i--)
	{
		for (int j = 0; j < gameConfig::GAME_WIDTH; j++)
		{
			board_game[i][j].setIsActive(board_game[i - 1][j].getIsActive()); 
		}
	}
	for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
	{
		board_game[0][i].setIsActive(false); 
	}
}
bool Board::IsLineFull(int index_line)
{
	for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
	{
		if (board_game[index_line][i].getIsActive() == false)
			return false; 
	}
	return true; 
}

int  Board::clearFullLines()
{
	int numClearedLines = 0;
	for (int i = 0; i < gameConfig::GAME_HEIGHT; i++)
	{
		if (IsLineFull(i))
		{
			numClearedLines++; 
			clearLine(i);  
		}
	}
	if (numClearedLines > 0)
		drawBoardCubes();

	return numClearedLines; 
}



void Board::implementShapeToBoard(const Shape& shape) 
{
	for (int i = 0; i < 4; i++)
	{
		board_game[shape.get_cubes()[i].get_Y() - 1][(shape.get_cubes()[i].get_X() - startingX - 1) / 2].setIsActive(true);
		board_game[shape.get_cubes()[i].get_Y() - 1][(shape.get_cubes()[i].get_X() - startingX - 1) / 2].setColor(shape.getColor());
	}
	
}
void Board::drawBoardCubes()
{
	for (int i = 0; i < gameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < gameConfig::GAME_WIDTH; j++)
			board_game[i][j].drawCube(board_game[i][j].getIsActive(),useColors);
	}
}

void  Board::setUseColor(bool useColors)
{
	this->useColors = useColors; 
}







