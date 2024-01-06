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
	Cube(int startX, int startY) : x(startX), y(startY) {};
};

