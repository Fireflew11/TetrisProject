#ifndef SHAPE_H
#define SHAPE_H
#pragma once
#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "gameConfig.h"
enum Direction { RIGHT = 1, LEFT };
class Cube; 
class Board; 
class Shape
{
	//Cube starting_cube; //אנסה למצוא פתרון טוב יותר - הקוביה תשמור את אמצע הלוח למעלה של כל שחקן, כלומר נקודת ההתחלה שממנה יפלו הקוביות  
	Cube cubes[4];
	//int startingX, startingY; //למה אנחנו צריכים את זה עכשיו? לשקול להוריד את זה 
	int color; 
	gameConfig::ShapeType type; 
	bool useColors;





public: 
	Shape(int x, int y, int cheatShape = 0);  // הנקודה הזה תתן לי את מרכז הלוח שבו אני רוצה להתחיל את נפילת הקוביה 

	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i,  Cube cube); 
	void deleteCubesBlock();
	void drawShape(bool isActive = true) const;
	int getRowsAmount() const;
	~Shape();


	void rotate_CounterClock_wise(const Board& board);
	void rotate_Clock_wise(const Board& board);
	void move_Left(const Board& board);
	void move_Right(const Board& board); 
	bool continueMovingDown(const Board& board);
	void drop(const Board& board);

	int getColor() const;
	const gameConfig::ShapeType getShapeType(); 

	Shape(gameConfig::PlayerType playerType, bool useColors=true);


	bool isOShape() const;


   
    
};

#endif //SHAPE_H