#pragma once
#include "Cube.h"
#include <cstdlib>
#include <ctime>

class Cube; 

class Shape
{
	//Cube starting_cube; //אנסה למצוא פתרון טוב יותר - הקוביה תשמור את אמצע הלוח למעלה של כל שחקן, כלומר נקודת ההתחלה שממנה יפלו הקוביות  
	Cube cubes[4];

public: 
	Shape(int x, int y, int cheatShape = 0); // הנקודה הזה תתן לי את מרכז הלוח שבו אני רוצה להתחיל את נפילת הקוביה 
	const Cube* const get_cubes(); 
};

