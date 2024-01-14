#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>

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
        Shape curShape(gameConfig::PlayerType(1));
        //Shape curShape(gameConfig::GAME_WIDTH + 1, 1);
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
                    keyPressed = toupper(keyPressed);
                    keyChoice(gameConfig::keys(keyPressed), curShape, players[0].getPlayerBoard(), gameConfig::PlayerType(1));
                    //curShape.executeMove(keyPressed, playerBoard, moveFunctions);
                }
            }
            else 
            {

                Sleep(500);
                if (!curShape.continueMovingDown(players[0].getPlayerBoard()))
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShape);
                    //playerBoard.implementShapeToBoard(curShape);
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
    int keyPressedPlayer1 = 0;
    int keyPressedPlayer2 = 0;

    while (!isGameOver)
    {
        Shape curShapePlayer1(gameConfig::PlayerType::LEFT_PLAYER);
        Shape curShapePlayer2(gameConfig::PlayerType::RIGHT_PLAYER);

        while (true)
        {
            if (_kbhit())
            {
                int keyPressed = _getch();
                if (keyPressed == (int)gameConfig::keys::ESC)
                {
                    isGameOver = true;
                    break;
                }
                else
                {
                    keyPressed = toupper(keyPressed);

                    if (keyPressed == 'A' || keyPressed == 'D' || keyPressed == 'S' || keyPressed == 'W' || keyPressed == 'X')
                    {
                        keyChoice(gameConfig::keys(keyPressed), curShapePlayer1, players[0].getPlayerBoard(), gameConfig::PlayerType::LEFT_PLAYER);
                    }

                    else if (keyPressed == 'J' || keyPressed == 'L' || keyPressed == 'K' || keyPressed == 'I' || keyPressed == 'M')
                    {
                        keyChoice(gameConfig::keys(keyPressed), curShapePlayer2, players[1].getPlayerBoard(), gameConfig::PlayerType::RIGHT_PLAYER);
                    }
                }
            }
            else
            {
                Sleep(500);
                if (!curShapePlayer1.continueMovingDown(players[0].getPlayerBoard()))
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                    break;
                }
                if (!curShapePlayer2.continueMovingDown(players[1].getPlayerBoard()))
                {
                    players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                    break;
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


