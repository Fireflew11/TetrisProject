#include "Board.h"
#include "gameConfig.h"




Shape* Board::getCurShape() const {
	return curShape;
}
void Board::setCurShape(Shape* curShape) {
	this->curShape = curShape;
}

void Board::setStartingX(const int x) {
	startingX = x;
}

void Board::setStartingY(const int y) {
	startingY = y;
}

void Board::print_Line() 
{
	for (int i = 0; i < gameConfig::GAME_WIDTH * 2 + 2; i++)
	{
		cout << "-";
	}
	cout << endl; 
}

void Board::display_board(int startingX) //board draws at (startingX, 0) at the moment
{
	int i, j;
	gotoxy(startingX, 0);
	Board::print_Line();
	gotoxy(startingX, 1);
	for (i = 1; i < gameConfig::GAME_HEIGHT +1; i++)
	{
		cout << "|";
		for (j = 1; j < gameConfig::GAME_WIDTH *2 + 1; j++)
			cout << " "; 
		cout << "|" << endl; 
		gotoxy(startingX, i);
	}
	Board::print_Line(); 
}

Board::Board(int starting_X, int starting_Y):startingX(starting_X),startingY(starting_Y)
{
	for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
	{
		for (int j = 0; j < gameConfig::GAME_HEIGHT; j++)
		{
			board_game[i][j].set_coord(gameConfig::GAME_HEIGHT  + i, j); 
			board_game[i][j].setIsActive(false); 
		}
	}
}

void Board::insert_Shape(const Shape& shape)
{

}


const Cube(&Board::getBoardGame() const)[12][18]{
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
		if (y >= gameConfig::GAME_HEIGHT || y < 1)
			return false;
		if (board_game[(x - startingX- 1) / 2][y - 1].getIsActive() == true) //למה פה שמנו Y-1? //לבדוק אם צריך לחלק את איקס ל-2 בגלל גודל הקוביה 
			return false;

	}
	return true;

}

void Board:: updateBoard(const Shape& shape)// לבדוק אם ערכי הY ששמתי טובים פה 
{

	for (int i = 0; i < 4; ++i)
	{
		int x = shape.get_cubes()[i].get_X();
		int y = shape.get_cubes()[i].get_Y();
		board_game[x - startingX][y-startingY-1].set_coord(x, y);
		board_game[x - startingX][y-startingY-1].setIsActive(true);
	}
}

void Board::clearLine(int index_line)
{
//board_game[index_line][i].drawCube(false); //לשנות את ההצרות במסך עצמו להבין 
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

void  Board::clearFullLines()
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
}
void Board::implementShapeToBoard(const Shape& shape) {
	for (int i = 0; i < 4; i++)
	{
		board_game[(shape.get_cubes()[i].get_X() - startingX - 1 ) / 2][shape.get_cubes()[i].get_Y() - 1].setIsActive(true);
	}
}
/*
bool Board::isGameOver()
{

}
*/






