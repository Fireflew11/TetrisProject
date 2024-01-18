#include "Player.h"


Board& Player::getPlayerBoard()
{
    return playerBoard;
}


 Player:: Player(gameConfig:: PlayerType playerType, int score, bool isWinner) :isWinner(false), score(0), playerType(playerType), playerBoard(
    (playerType ==  gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig::MIN_X_LEFT_BOARD : gameConfig::MIN_X_RIGHT_BOARD,
    (playerType == gameConfig::PlayerType::LEFT_PLAYER) ? gameConfig:: MIN_Y_LEFT_BOARD: gameConfig:: MIN_Y_RIGHT_BOARD) 
 {

 }


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
 }

 void Player::displayScore()
 {
     if (playerType == gameConfig::PlayerType::LEFT_PLAYER)
         gotoxy(gameConfig::MAX_X_LEFT_BOARD + 2, 2);
     else
         gotoxy(gameConfig::MAX_X_RIGHT_BOARD + 2, 2);
     cout << "Player " << (int)playerType << " score: " << score;
 }


 void Player:: setIsWinner(bool isWinner)
 {
     this->isWinner = isWinner; 
 }
 bool Player::getIsWinner()
 {
     return isWinner; 
 }

 const int Player::getScore()
 {
     return score; 
 }



