#pragma once
class Cube
{
private:
	int x;
	int y; 
public: 
	const int& get_X() const;
	const int& get_Y() const;
	//void set_X(const int& x); 
	//void set_Y(const int& y); 
	
	Cube(int startX=0, int startY=0) : x(startX), y(startY) {}; 
};

