#pragma once

#include <iostream>
#include"Shape.h" 

class Shape; 

using namespace std;

class Board
{
	const int height = 18;//זה צריך להיות 12 לא? 
	const int width = 12;// זה צריך להיות 18 לא? 
	//char board_game[width][height]; 
	Cube board_game[18][12]; 

public:
	const int& get_height() const; 
	const int& get_width() const; 
	void display_board();
	void insert_Shape(const Shape& shape); 

	Board();

private: 
	void print_Line(); 
};

