#include "Computer.h"
#include <algorithm>
#include <functional>

bool Computer::decideMove(Shape& shape, char key)
{
	if (key == gameConfig::ESC)
		return true;

	if (movesOrderList.empty()) {

	}

	else {
		auto func = movesOrderList.front();
		if(func != nullptr)
			(shape.*(func))(getPlayerBoard());
		movesOrderList.pop_front();  // Remove the executed function from the list
	}



	return false;
}

void Computer::clearMovesList()
{
	movesOrderList.clear();
}

