﻿#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>
#include "GlobalFunctions.h"
/*
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
*/


void Game::keyChoice(gameConfig::LeftKeys key, Shape& shape)
{
    switch(key)
    {
    case gameConfig::LeftKeys::RIGHT:
            shape.move_Right(players[0].getPlayerBoard());
            break;
        case gameConfig::LeftKeys::LEFT:
            shape.move_Left(players[0].getPlayerBoard());
            break;
        case gameConfig::LeftKeys::ROTATE_CLOCK_WISE:
            shape.rotate_Clock_wise2(players[0].getPlayerBoard());
            break;
        case gameConfig::LeftKeys::ROTATE_COUNTER_CLOCK_WISE:
            shape.rotate_CounterClock_wise2(players[0].getPlayerBoard());
            break;
        case gameConfig::LeftKeys::DROP:
            shape.drop(players[0].getPlayerBoard());
            break;
        default:
            break; 
    }
}

void Game:: keyChoice(gameConfig::RightKeys key, Shape& shape)
{
    switch (key)
    {
    case gameConfig::RightKeys::RIGHT:
        shape.move_Right(players[1].getPlayerBoard());
        break;
    case gameConfig::RightKeys::LEFT:
        shape.move_Left(players[1].getPlayerBoard());
        break;
    case gameConfig::RightKeys::ROTATE_CLOCK_WISE:
        shape.rotate_Clock_wise2(players[1].getPlayerBoard());
        break;
    case gameConfig::RightKeys::ROTATE_COUNTER_CLOCK_WISE:
        shape.rotate_CounterClock_wise2(players[1].getPlayerBoard());
        break;
    case gameConfig::RightKeys::DROP:
        shape.drop(players[1].getPlayerBoard());
        break;
    default:
        break;
    }
}


void Game::GameLoop()
{
    bool isGameOver = false;
    players[0].displayScore();
    players[1].displayScore();
    while (!isGameOver)
    {
        Shape curShapePlayer1(gameConfig::PlayerType::LEFT_PLAYER, useColors);
        Shape curShapePlayer2(gameConfig::PlayerType::RIGHT_PLAYER, useColors);

        while (true)
        {

            players[0].updateScore(players[0].getPlayerBoard().clearFullLines());
            players[1].updateScore(players[1].getPlayerBoard().clearFullLines());

            if (_kbhit())
            {
                int keyPressed = _getch();
                if (keyPressed == (int)gameConfig::ESC)
                {
                    status = GameStatus::Paused;
                    startGame();
                    if (status == GameStatus::Ended || status == GameStatus::NewGame)
                        return;
                }
                else
                {
                    checkKeyChoice(keyPressed, curShapePlayer1, curShapePlayer2);
                }
            }
            else
            {
                Sleep(500);

                bool movedDownPlayer1 = curShapePlayer1.continueMovingDown(players[0].getPlayerBoard());
                bool movedDownPlayer2 = curShapePlayer2.continueMovingDown(players[1].getPlayerBoard());

                if (!movedDownPlayer1 && !movedDownPlayer2)
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                    players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                    break;
                }
                if (!movedDownPlayer1)
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                    curShapePlayer1 = Shape(gameConfig::PlayerType::LEFT_PLAYER,useColors);
                }

                if (!movedDownPlayer2)
                {
                    players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                    curShapePlayer2 = Shape(gameConfig::PlayerType::RIGHT_PLAYER,useColors);
                }

            }
        }
    }
}

void Game:: checkKeyChoice(int keyPressed, Shape& Leftshape,Shape& RightShape)
{
    keyPressed = toupperG(keyPressed);

    if (keyPressed == (int)gameConfig::LeftKeys::LEFT|| keyPressed == (int)gameConfig::LeftKeys::RIGHT ||
        keyPressed == (int)gameConfig::LeftKeys::ROTATE_CLOCK_WISE || keyPressed == (int)gameConfig::LeftKeys::ROTATE_COUNTER_CLOCK_WISE || 
        keyPressed == (int)gameConfig::LeftKeys::DROP)
    {
        keyChoice((gameConfig::LeftKeys)keyPressed, Leftshape); 
    }
    else if (keyPressed == (int)gameConfig::RightKeys::LEFT || keyPressed == (int)gameConfig::RightKeys::RIGHT ||
        keyPressed == (int)gameConfig::RightKeys::ROTATE_CLOCK_WISE || keyPressed == (int)gameConfig::RightKeys::ROTATE_COUNTER_CLOCK_WISE ||
        keyPressed == (int)gameConfig::RightKeys::DROP)
    {
        keyChoice((gameConfig::RightKeys)keyPressed, RightShape);
    }
}




/*
void Game::GameLoop()
{
    bool isGameOver = false;
    int keyPressedPlayer1 = 0;
    int keyPressedPlayer2 = 0;
    players[0].displayScore();
    players[1].displayScore();
    while (!isGameOver)
    {
        Shape curShapePlayer1(gameConfig::PlayerType::LEFT_PLAYER);
        Shape curShapePlayer2(gameConfig::PlayerType::RIGHT_PLAYER);

        while (true)
        {

            players[0].updateScore(players[0].getPlayerBoard().clearFullLines());
            players[1].updateScore(players[1].getPlayerBoard().clearFullLines());

            if (_kbhit())
            {
                int keyPressed = _getch();
                if (keyPressed == (int)gameConfig::keys::ESC)
                {
                    status = GameStatus::Paused;
                    startGame();
                    if (status == GameStatus::Ended || status == GameStatus::NewGame)
                        return;
                }
                else
                {
                    keyPressed = toupperG(keyPressed);
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

                bool movedDownPlayer1 = curShapePlayer1.continueMovingDown(players[0].getPlayerBoard());
                bool movedDownPlayer2 = curShapePlayer2.continueMovingDown(players[1].getPlayerBoard());
                
                if (!movedDownPlayer1 && !movedDownPlayer2)
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                    players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                    break;
                }
                if (!movedDownPlayer1)
                {
                    players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                    curShapePlayer1 = Shape(gameConfig::PlayerType::LEFT_PLAYER);
                }

                if (!movedDownPlayer2)
                {
                    players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                    curShapePlayer2 = Shape(gameConfig::PlayerType::RIGHT_PLAYER);
                }

            }
        }
    }
}
*/
bool Game::getIsGamePaused()
{
    return isGamePaused;
}

void Game::setIsGamePaused(bool isGamePaused)
{
    this->isGamePaused = isGamePaused;
}

void Game::startGame()
{
    char keyPressed = 0;
    while (status != GameStatus::Ended) 
    {
        system("cls");
        Print_Menu();
        keyPressed = _getch();
        if (keyPressed == '1')
        {
            system("cls");
            if (status == GameStatus::Paused)
            {
                players[0] = Player(gameConfig::PlayerType::LEFT_PLAYER);
                players[1] = Player(gameConfig::PlayerType::RIGHT_PLAYER);
                status = GameStatus::NewGame;
                return;
            }

            while (status == GameStatus::NewGame || status == GameStatus::Running)
            {
                players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
                players[1].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
                GameLoop();
            }

        }
        else if (keyPressed == '2' && status == GameStatus::Paused)
        {
            system("cls");
            players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
            players[1].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
            players[0].displayScore();
            players[1].displayScore();
            return;
        }
        else if (keyPressed == '8')
        {
            system("cls");
            Present_instructionsand_keys();
            Print_Menu();
        }

        else if (keyPressed == '9')
        {
            system("cls");
            status = GameStatus::Ended;
            return;
        }
        else if (keyPressed == '3'|| keyPressed == '4')
        {
            system("cls");
            if ((keyPressed=='4'&& useColors == true)|| (keyPressed == '3' && useColors == true))
            {
                useColors = !useColors;
                players[0].getPlayerBoard().setUseColor(useColors);
                players[1].getPlayerBoard().setUseColor(useColors);
            }
          
            if (status == GameStatus::Paused)
            {
                players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
                players[1].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
                players[0].displayScore();
                players[1].displayScore();
            }
            while (status == GameStatus::NewGame || status == GameStatus::Running)
            {
                players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
                players[1].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
                GameLoop();
            }

        }
      
    }
}

void Game::printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn)
{
    cout << "|" << setw(24) << left << firstColumn << "|" << setw(24) << left << secondColumn << "|" << setw(24) << left << thirdColumn << "|" << std::endl;
}
void Game::printSeparator()
{
    cout << "+------------------------+------------------------+------------------------+" << std::endl;
}


Game::Game(bool useColors):players{Player(gameConfig::PlayerType::LEFT_PLAYER),Player(gameConfig::PlayerType::RIGHT_PLAYER)},status(GameStatus::Running),useColors(useColors)
{

}

void Game:: Print_Menu()
{
    system("cls");
    cout << "(1) Start a new game" << endl; 
    if(status == GameStatus::Paused)
        cout << "(2) Continue a paused game" << endl; 
    cout << "(3) Run with colors" << endl;
    cout << "(4) Run without colors" << endl;
    cout << "(8) Present instructionsand keys" << endl; 
    cout << "(9) EXIT" << endl; 
}

void Game::Present_instructionsand_keys()
{
    // Print the top border
    cout << "Keys: " << endl;
    printSeparator();
    printRow("", "Left Player", "Right Player");
    printSeparator();
    printRow("LEFT", "a or A", "j or J");
    printSeparator();
    printRow("RIGHT", "d or D", "l (small L) or L");
    printSeparator();
    printRow("ROTATE clockwise", "s or S", "k or K");
    printSeparator();
    printRow("ROTATE counterclockwise", "w or W", "i or I (uppercase i)");
    printSeparator();
    printRow("DROP", "x or X", "m or M");
    printSeparator();
    cout << "Press ESC to return to menu...";
    while (_getch() != (char)gameConfig::keys::ESC);
    return;
}



