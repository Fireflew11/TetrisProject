#pragma once

#include <iostream>
#include"Shape.h" 

class Shape; 

using namespace std;

class Board
{
	const int height = 18;
	const int width = 12; 
	//char board_game[width][height]; 
	Cube board_game[18][12]; 
	int startingX; 
	Shape* curShape;
	//int startingY; 

public:
	const int& get_height() const; 
	const int& get_width() const; 
	void display_board(const int startingX);
	void insert_Shape(const Shape& shape); 
	void move_Left(Shape& shape);
	void move_right(Shape& shape);
	void rotate_Clock_wise(Shape& shape);
	void rotate_CounterClock_wise();
	Board();
	Shape* getCurShape() const;
	void setCurShape(Shape* curShape);

private: 
	void print_Line(); 
	void drop_Shape();
	bool check_valid_move(const Shape& shape) const; 

};

