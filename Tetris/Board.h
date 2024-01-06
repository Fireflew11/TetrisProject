#pragma once

#include <iostream>
using namespace std;

class Board
{
	const int height = 18;
	const int width = 25;
	//char board_game[width][height]; 

public: 
	const int& get_height() const; 
	const int& get_width() const; 
	void display_board(); // יכול להיות שעדיף לשים הדפסת הלוח כבנאי 
private: 
	void print_Line(); 
};

