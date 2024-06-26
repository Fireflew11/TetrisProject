#include "Player.h"

/**********************************************************************
Function name:getPlayerBoard
Input:--
Output:Board&
Function: Returns a reference to the player's game board.
**********************************************************************/
Board& Player::getPlayerBoard() 
{
    return playerBoard;
}

/**********************************************************************
Function name: Player::Player
Input: gameConfig::PlayerType playerType
Output:--
Function:Constructor for the Player class. Initializes the player type, score, and player board based on the provided player type.
**********************************************************************/
 Player:: Player(gameConfig:: PlayerType playerType) : isWinner(false), score(0), playerType(playerType),playerBoard(
    (playerType ==  gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD,
    (playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig:: MIN_Y_LEFT_BOARD: gameConfig:: MIN_Y_RIGHT_BOARD),
     startingX((playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD),
     startingY((playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_Y_LEFT_BOARD : gameConfig::MIN_Y_RIGHT_BOARD)
 {}

/**********************************************************************
Function name:updateScore
Input: Number of cleared lines (int)
Output: --
Function:Updates the player's score based on the number of lines cleared during gameplay.
**********************************************************************/
 void Player::updateScore(int numClearedLines)
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
     if(numClearedLines > 0)
       playerBoard.drawBoardCubes();
 }

/**********************************************************************
Function name:displayScore
Input: --
Output:--
Function:Displays the player's current score on the game screen.
**********************************************************************/
 void Player::displayScore()
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
 void Player:: setIsWinner(bool isWinner)
 {
     this->isWinner = isWinner; 
 }

/**********************************************************************
Function name:getIsWinner
Input: --
Output: Winner status (bool)
Function:The function retrieves the current winner status for the player.
**********************************************************************/
 const bool Player::getIsWinner() const
 {
     return isWinner; 
 }

/**********************************************************************
Function name: getScore
Input:--
Output: Current player's score (int)
Function:The function retrieves the current score of the player.
**********************************************************************/
 const int Player::getScore()
 {
     return score; 
 }

/**********************************************************************
Function name: Player::getPlayerType
Input:--
Output: gameConfig::PlayerType
Function: Getter function to retrieve the player type.
**********************************************************************/
 const gameConfig::PlayerType Player:: getPlayerType()const
 {
     return playerType;
 }

 /**********************************************************************
Function name: Player::getStartingX
Input:--
Output: int
Function: Getter function to retrieve the starting X coordinate of the player's board.
**********************************************************************/
 const int Player::getStartingX() const
 {
     return startingX; 
 }

 /**********************************************************************
Function name: Player::getStartingY
Input:--
Output: int
Function: Getter function to retrieve the starting Y coordinate of the player's board.
**********************************************************************/
 const int Player:: getStartingY() const
 {
     return startingY; 
 }





