#include "Board.h"

const int&  Board::get_height() const
{
	return height; 
}
const int& Board:: get_width() const
{
	return width; 
}
Shape* Board::getCurShape() const {
	return curShape;
}
void Board::setCurShape(Shape* curShape) {
	this->curShape = curShape;
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

void Board:: move_Left(Shape& shape)
{
	int x = shape.get_cubes()[0].get_X();
	int y = shape.get_cubes()[0].get_Y();
	Shape temp(x,y, 0);
	x = x - 2; 
	for (int i = 0; i < 4; i++)
	{
		Cube temp_cube(x, y, true); 
		temp.set_cubes_by_Index(i, temp_cube); 
	}
	if (check_valid_move(temp) == true)
		shape = temp; 
	shape = temp; 
}



void Board:: move_right(Shape& shape)
{
	int x = shape.get_cubes()[0].get_X();
	int y = shape.get_cubes()[0].get_Y();
	Shape temp(x, y, 0);
	x = x +2 ;
	for (int i = 0; i < 4; i++)
	{
		Cube temp_cube(x, y, true);
		temp.set_cubes_by_Index(i, temp_cube);
	}
	if (check_valid_move(temp) == true)
		shape = temp;
	shape = temp;
}
void Board:: rotate_Clock_wise(Shape& shape)
{
	
	shape.rotateShape(RIGHT);
	if (!check_valid_move(shape))
		shape.rotateShape(LEFT);
	shape.drawShape();
}
void Board:: rotate_CounterClock_wise()
{



}
void  Board:: drop_Shape()
{

}

bool Board::check_valid_move( const Shape& shape) const
{
	for (int i = 0; i < 4; i++)
	{
		int x = shape.get_cubes()[i].get_X(); 
		int y= shape.get_cubes()[i].get_Y();
		if ((x >= width*2 + startingX) || (x <= startingX))
			return false; 
		if (y >= height || y < 1)
			return false; 
		if (board_game[x - startingX][y-1].getIsActive() == true)
			return false;

	}
	return true; 
	
}