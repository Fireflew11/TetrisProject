#include "Board.h"

const int&  Board::get_height() const
{
	return height; 
}
const int& Board:: get_width() const
{
	return width; 
}


void Board::print_Line() 
{
	for (int i = 0; i < width * 2 + 2; i++)
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
	for (i = 1; i < height+1; i++)
	{
		cout << "|";
		for (j = 1; j < width*2 + 1; j++)
			cout << " "; 
		cout << "|" << endl; 
		gotoxy(startingX, i);
	}
	Board::print_Line(); 
}

Board::Board() 
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board_game[i][j].set_coord(height + i, j); 
			board_game[i][j].setIsActive(false); 
		}
	}
}

void Board::insert_Shape(const Shape& shape)
{

}
