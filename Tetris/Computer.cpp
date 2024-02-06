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

list<list<Player::ShapeFunctionType>> Computer::getAllPossibleMoves(Shape& shape)
{
    list<list<Player::ShapeFunctionType>> allMoves;

    // Define the list of possible functions
    list<Player::ShapeFunctionType> possibleFunctions = {
        &Shape::move_Left,
        &Shape::move_Right,
        &Shape::rotate_Clock_wise,
        &Shape::rotate_CounterClock_wise,
        &Shape::drop
    };

    // Recursive function to generate all possible move sequences
    function<void(Shape&, list<Player::ShapeFunctionType>&)> generateSequences =
        [&](Shape& currentShape, list<Player::ShapeFunctionType>& currentSequence)
    {
        // Base case: if the shape reaches the bottom, add the current sequence to the list
        if (!currentShape.continueMovingDown(getPlayerBoard()))
        {
            allMoves.push_back(currentSequence);
            return;
        }

        // Recursive case: try each possible function and generate new sequences
        for (auto& func : possibleFunctions)
        {
            // Create a copy of the current shape to avoid modifying the original
            Shape tempShape = currentShape;

            // Apply the current function to the temporary shape
            (tempShape.*(func))(getPlayerBoard());

            // Update the current sequence with the chosen function
            currentSequence.push_back(func);

            // Recursively generate sequences for the updated shape
            generateSequences(tempShape, currentSequence);

            // Backtrack by removing the last function from the sequence
            currentSequence.pop_back();
        }
    };

    // Start the recursive generation with an empty sequence and the initial shape
    list<Player::ShapeFunctionType> initialSequence;
    generateSequences(shape, initialSequence);

    return allMoves;
}

list<Player::ShapeFunctionType> Computer::getCurList(Shape& shape) {

}

