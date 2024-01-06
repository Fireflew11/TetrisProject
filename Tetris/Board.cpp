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
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl; 
}

void Board::display_board()
{
	Board::print_Line();
	for (int i = 1; i < height-1; i++)
	{
		cout << "|";
		for (int j = 1; i < width - 1; j++)
			cout << " "; 
		cout << "|" << endl; 
	}
	Board::print_Line(); 
}

Board::Board()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			board_game[i][j] = ' '; 
		}
	}
}

void  Board::insert_Shape(const Shape& shape)
{

}
