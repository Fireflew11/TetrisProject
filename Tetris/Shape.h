#pragma once
#include "Cube.h"
#include <cstdlib>
#include <ctime>
#include "Board.h"
enum Direction { RIGHT = 1, LEFT };
class Cube; 

class Shape
{
	//Cube starting_cube; //אנסה למצוא פתרון טוב יותר - הקוביה תשמור את אמצע הלוח למעלה של כל שחקן, כלומר נקודת ההתחלה שממנה יפלו הקוביות  
	Cube cubes[4];
	int id;
	int startingX, startingY;
	bool isIVertical = true; //unique for I shape, starts true
public:
	Cube* cubesBlock[][3];

public: 
	Shape(int x, int y, int cheatShape = 0);  // הנקודה הזה תתן לי את מרכז הלוח שבו אני רוצה להתחיל את נפילת הקוביה 

	const Cube* const get_cubes() const;
	void set_cubes_by_Index(int i,  Cube cube); 
	void initializeCubesBlock();
	void deleteCubesBlock();
	void drawShape() const;
	int getRowsAmount() const;
	int getId();
	void rotateMatrixClockwise();
	void rotateMatrixCounterClockwise();
	void transposeMatrix();
	void rotateShape(Direction direction);
	~Shape();

   
    
};

