#pragma once
#include<iostream>
using namespace std;
namespace pointNs {
	class Point
	{
	private:
		int x;
		int y;
		bool isPointOccupied;
	public:
		const int getX() const;
		void setX(const int x);
		const int getY() const;
		void setY(const int y);
		const bool getPointOcc() const;
		void setPointOcc(const bool isPointOccupied);
	};
}

