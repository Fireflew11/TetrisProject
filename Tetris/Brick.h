#pragma once
#include <iostream>
using namespace std;
namespace BrickNS {
	struct Point {
		int x, y;
	};
	/*
		BRICK: always 1x1 cube, 
		p symbolizes the bottom left part of the brick (left bottom part of the board is (0,0))
		isActive helps checking if a line is complete or which shape is the current shape
	*/
	class Brick
	{
	private:
		Point p;
		bool isActive;
	public:
		Brick(const Point p, const bool isActive = false);
		const Point& getPoint() const;
		void setPoint(const Point p);
		bool getIsActive() const;
		void setIsActive(const bool isActive);
	};
}

