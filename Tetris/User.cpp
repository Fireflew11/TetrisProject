#include "User.h"

/**********************************************************************
Function name:getPlayerBoard
Input:--
Output:Board&
Function: Returns a reference to the player's game board.
**********************************************************************/
Board& User::getPlayerBoard()
{
    return playerBoard;
}

/**********************************************************************
Function name: Player (Constructor)
Input:
    - playerType: Type of the player (gameConfig::PlayerType)
    - score: Initial score for the player (int)
    - isWinner: Initial winner status for the player (bool)
Output: --
Function:Initializes a Player object with the specified player type, initial score, and winner status.
The constructor sets the initial values for the player's score, winner status, and retrieves the appropriate starting coordinates and board for the player based on their type.
**********************************************************************/
User::User(gameConfig::PlayerType playerType, int score, bool isWinner) :isWinner(false), score(0), playerType(playerType), playerBoard(
    (playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD,
    (playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_Y_LEFT_BOARD : gameConfig::MIN_Y_RIGHT_BOARD),
    startingX((playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD)
{}

/**********************************************************************
Function name:updateScore
Input: Number of cleared lines (int)
Output: --
Function:Updates the player's score based on the number of lines cleared during gameplay.
**********************************************************************/
void User::updateScore(int numClearedLines)
{
    switch (numClearedLines)
    {
    case 1:
        score += static_cast<int>(gameConfig::Score::SINGLE_LINE_CLEAR);
        displayScore();
        break;
    case 2:
        score += static_cast<int>(gameConfig::Score::DOUBLE_LINE_CLEAR);
        displayScore();
        break;
    case 3:
        score += static_cast<int>(gameConfig::Score::TRIPLE_LINE_CLEAR);
        displayScore();
        break;
    case 4:
        score += static_cast<int>(gameConfig::Score::TETRIS_LINE_CLEAR);
        displayScore();
        break;
    default:
        break;
    }
}

/**********************************************************************
Function name:displayScore
Input: --
Output:--
Function:Displays the player's current score on the game screen.
**********************************************************************/
void User::displayScore()
{
    gotoxy(startingX, gameConfig::MAX_Y_RIGHT_BOARD + 1);
    cout << "Player " << (int)playerType << " score: " << score;
}

/**********************************************************************
Function name: setIsWinner
Input:bool
Output:--
Function:Sets the winner status for the player.
**********************************************************************/
void User::setIsWinner(bool isWinner)
{
    this->isWinner = isWinner;
}

/**********************************************************************
Function name:getIsWinner
Input: --
Output: Winner status (bool)
Function:The function retrieves the current winner status for the player.
**********************************************************************/
const bool User::getIsWinner() const
{
    return isWinner;
}

/**********************************************************************
Function name: getScore
Input:--
Output: Current player's score (int)
Function:The function retrieves the current score of the player.
**********************************************************************/
const int User::getScore()
{
    return score;
}

const gameConfig::PlayerType User::getPlayerType()const
{
    return playerType;
}




