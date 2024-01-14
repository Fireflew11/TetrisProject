#ifndef SHAPE_H
#define SHAPE_H
#pragma once
#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
enum Direction { RIGHT = 1, LEFT };
class Cube; 
class Board; 
class Shape
{
	//Cube starting_cube; //אנסה למצוא פתרון טוב יותר - הקוביה תשמור את אמצע הלוח למעלה של כל שחקן, כלומר נקודת ההתחלה שממנה יפלו הקוביות  
	Cube cubes[4];
	int id;
	int startingX, startingY;
	//int color; 
	bool isIVertical = true; //unique for I shape, starts true
	using MoveFunction = void (Shape::*)(const Board&);  // Directly define the type of moveFunctions


public: 
	Shape(int x, int y, int cheatShape = 0);  // הנקודה הזה תתן לי את מרכז הלוח שבו אני רוצה להתחיל את נפילת הקוביה 

	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i,  Cube cube); 
	void deleteCubesBlock();
	void drawShape(bool isActive = true) const;
	int getRowsAmount() const;
	int getId();
	~Shape();


	void rotate_CounterClock_wise2(const Board& board);
	void rotate_Clock_wise2(const Board& board);
	void move_Left(const Board& board);
	void move_Right(const Board& board); 
	bool continueMovingDown(const Board& board);
	void drop(const Board& board);
	void executeMove(char input, const Board& board, MoveFunction moveFunctions[]);




   
    
};

#endif //SHAPE_H