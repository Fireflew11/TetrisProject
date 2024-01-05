#pragma once
#include <iostream>
#include "Point_H.h";
using namespace std;
using namespace pointNs;
namespace BoardNS {
	class BoardFunctions
	{
	private:
		Point board[18][12];
	public:
		void initializeBoard();

	};
}

