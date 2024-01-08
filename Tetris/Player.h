#pragma once

#include <cstdlib>
#include <conio.h>
#include "Shape.h"
#include "Board.h"
using namespace std;
class Shape; 

class Player
{
private: 
	int playerType; 
	Board playerBoard; //אולי עדיך לעשות את זה כמצביע? 
	//int score; 
public: 
	void keyChoice(); 
};

