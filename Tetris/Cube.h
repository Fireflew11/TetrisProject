#pragma once
#include <Windows.h>
#include<iostream>
#include"GlobalFunctions.h"

using namespace std;
class Cube
{
	//cube size 1x2 (1 height pixel = 2 width pixel
private:
	COORD coord;
	bool isActive;
	int color; 
public: 
	int get_X() const;
	int get_Y() const;
	bool getIsActive() const;
	void setIsActive(const bool isActive);

	void drawCube(const bool isActive, int colorIndex, const int size=1) const;
	//void drawCube(const bool isActive, const int size = 1) const;
	void set_coord(const int& x, const int& y); 

	void set_X(const int& x); 
	void set_Y(const int& y); 

	Cube(int x=0, int y=0, int colorIndex =0, bool active = true);
///
	void move();
	void draw(char ch); 

	//Cube(int startX = 0, int startY = 0, bool isActive = false);
	
};

