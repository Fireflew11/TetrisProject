#pragma once
#include <Windows.h>
#include<iostream>
using namespace std;
class Cube
{
	//cube size 1x1
private:
	COORD coord;
	bool isActive;
public: 
	int get_X() const;
	int get_Y() const;
	bool getIsActive() const;
	void setIsActive(const bool isActive);
	void drawCube(int x, int y, const bool isActive, const int size = 1);
	void gotoxy(int x, int y);
	//void set_X(const int& x); 
	//void set_Y(const int& y); 
	
	//Cube(int startX = 0, int startY = 0, bool isActive = false);
};

