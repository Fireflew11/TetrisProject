#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"

void Game::keyChoice(gameConfig::keys key, Shape& shape, const Board& board, gameConfig::PlayerType player)
{
    if (player == gameConfig::PlayerType::LEFT_PLAYER)
    {
        switch (key)
        {
        case gameConfig::keys::LP_RIGHT:
            shape.move_Right(board);
            break;
        case gameConfig::keys::LP_LEFT:
            shape.move_Left(board);
            break;
        case gameConfig::keys::LP_ROTATE_CLOCK_WISE:
            shape.rotate_Clock_wise2(board);
            break;
        case gameConfig::keys::LP_ROTATE_COUNTER_CLOCK_WISE:
            shape.rotate_CounterClock_wise2(board);
            break;
        case gameConfig::keys::LP_DROP:
            shape.drop(board);
            break;
        }
    }
    else//player== gameConfig::PlayerType::RIGHT_PLAYER
    {
        switch (key)
        {
        case gameConfig::keys::RP_RIGHT:
            shape.move_Right(board);
            break;
        case gameConfig::keys::RP_LEFT:
            shape.move_Left(board);
            break;
        case gameConfig::keys::RP_ROTATE_CLOCK_WISE:
            shape.rotate_Clock_wise2(board);
            break;
        case gameConfig::keys::RP_ROTATE_COUNTER_CLOCK_WISE:
            shape.rotate_CounterClock_wise2(board);
            break;
        case gameConfig::keys::RP_DROP:
            shape.drop(board);
            break;
        }
    } 
}
/*
void Game::GameLoop()
{
    bool isGameOver = false;
    int keyPressed = 0;
    while (!isGameOver) 
    {
        Shape curShape(gameConfig::GAME_WIDTH + 1, 1);
        while (true) 
        {
            if (_kbhit()) 
            {
                keyPressed = _getch();
                if (keyPressed == (int)gameConfig::keys::ESC) 
                {
                    isGameOver = true;
                    break;
                }
                else 
                {
                    curShape.executeMove(keyPressed, playerBoard, moveFunctions);
                }
            }
            else {

                Sleep(500);
                if (!curShape.continueMovingDown(playerBoard)) 
                {
                    playerBoard.implementShapeToBoard(curShape);
                    break;
                }
            }
        }
    }
}

*/


void Game::GameLoop()
{
    bool isGameOver = false;
    int keyPressed = 0;

    while (!isGameOver)
    {
        for (int playerIndex = 0; playerIndex < gameConfig::NUM_OF_PLAYERS; ++playerIndex)
        {
            Shape curShape(gameConfig::PlayerType(playerIndex + 1));

            if (_kbhit())
            {
                keyPressed = _getch();
                if (keyPressed == (int)gameConfig::keys::ESC)
                {
                    isGameOver = true;
                    break;
                }
                else
                {
                    keyChoice(gameConfig::keys(keyPressed), curShape, players[playerIndex].getPlayerBoard(), gameConfig::PlayerType(playerIndex));
                }
            }
            else
            {
                Sleep(500);
                if (!curShape.continueMovingDown(players[playerIndex].getPlayerBoard()))
                {
                    players[playerIndex].getPlayerBoard().implementShapeToBoard(curShape);
                }
            }
        }
    }
}



Game::Game():players{Player(gameConfig::PlayerType::LEFT_PLAYER),Player(gameConfig::PlayerType::RIGHT_PLAYER)} 
{

}

void Game:: Print_Menu()
{
    cout << "(1) Start a new game" << endl; 
    cout << "(2) Continue a paused game" << endl; 
    cout << "(8) Present instructionsand keys" << endl; 
    cout << "(9) EXIT" << endl; 
}

/*
void Game::Present_instructionsand_keys()
{
   
}
*/


