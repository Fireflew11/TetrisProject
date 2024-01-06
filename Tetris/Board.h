#pragma once

#include <iostream>
#include"Shape.h"; 
class Shape; 

using namespace std;

class Board
{
	const int height = 18;
	const int width = 25;
	//char board_game[width][height]; 
	char board_game[25][18];

public: 
	const int& get_height() const; 
	const int& get_width() const; 

	void display_board();
	Board();
	void insert_Shape(const Shape& shape); 

private: 
	void print_Line(); 
};

