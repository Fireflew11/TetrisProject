#pragma once

#include <Windows.h>
#include<iostream>
#include"GlobalFunctions.h"
using namespace std;
/**********************************************************************
Class: Cube

Description:
    Represents a cube in the Tetris game, managing its coordinates, activation status, and color.

Member Variables:
    - coord: COORD structure storing X and Y coordinates of the cube.
    - isActive: Boolean indicating the activation status of the cube.
    - color: WORD representing the color of the cube.
**********************************************************************/
class Cube
{
private:
	COORD coord;
	bool isActive;
	WORD color; 
public: 

	int get_X() const;
	int get_Y() const;
	bool getIsActive() const;

	void setIsActive(const bool isActive);
	void drawCube(const bool isActive, bool useColors) const;
	void set_coord(const int& x, const int& y); 
	void set_X(const int& x); 
	void set_Y(const int& y); 
	void setColor(const int& color);

	Cube(int x=0, int y=0, int colorIndex =0, bool active = true);

};

