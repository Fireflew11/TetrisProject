#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>
#include "GlobalFunctions.h"

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
void Game::keyChoice(gameConfig::LeftKeys key, Shape& shape, const Board& board, gameConfig::PlayerType player)
{
    switch(key)
    {
    case gameConfig::LeftKeys::RIGHT:
            shape.move_Right(board);
            break;
        case gameConfig::LeftKeys::LEFT:
            shape.move_Left(board);
            break;
        case gameConfig::LeftKeys::ROTATE_CLOCK_WISE:
            shape.rotate_Clock_wise2(board);
            break;
        case gameConfig::LeftKeys::ROTATE_COUNTER_CLOCK_WISE:
            shape.rotate_CounterClock_wise2(board);
            break;
        case gameConfig::LeftKeys::DROP:
            shape.drop(board);
            break;
        default:
            break; 
    }
}

void keyChoice(gameConfig::RightKeys key, Shape& shape, const Board& board, gameConfig::PlayerType player)
{
    switch (key)
    {
    case gameConfig::RightKeys::RIGHT:
        shape.move_Right(board);
        break;
    case gameConfig::RightKeys::LEFT:
        shape.move_Left(board);
        break;
    case gameConfig::RightKeys::ROTATE_CLOCK_WISE:
        shape.rotate_Clock_wise2(board);
        break;
    case gameConfig::RightKeys::ROTATE_COUNTER_CLOCK_WISE:
        shape.rotate_CounterClock_wise2(board);
        break;
    case gameConfig::RightKeys::DROP:
        shape.drop(board);
        break;
    default:
        break;
    }
}


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
                    isGameOver = true;
                    break;
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
    players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
    players[0].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
    GameLoop();
    /*
    Print_Menu();
    bool didGameEnd = false;
    char keyPressed = 0;
    while (!didGameEnd) {
        while (!_kbhit()) {
            keyPressed = _getch();
        }
        system("cls");
        if (keyPressed == '1') {
            players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
            players[0].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
            GameLoop();
        }
        else if (keyPressed == '2' && isGamePaused)
        {
            players[0].getPlayerBoard().display_board(gameConfig::MIN_X_LEFT_BOARD);
            players[0].getPlayerBoard().display_board(gameConfig::MIN_X_RIGHT_BOARD);
            return;
        }
        else if (keyPressed == '8')
            Present_instructionsand_keys();

        else if (keyPressed == '9')
            didGameEnd = true;
    }
    */
}


Game::Game():players{Player(gameConfig::PlayerType::LEFT_PLAYER),Player(gameConfig::PlayerType::RIGHT_PLAYER)}, isGamePaused(false)
{

}

void Game:: Print_Menu()
{
    cout << "(1) Start a new game" << endl; 
    if(isGamePaused)
        cout << "(2) Continue a paused game" << endl; 
    cout << "(8) Present instructionsand keys" << endl; 
    cout << "(9) EXIT" << endl; 
}

void Game::Present_instructionsand_keys()
{
    // Print the top border
    std::cout << "+------------------------+------------------------+------------------------+" << std::endl;

    // Print each row with placeholders for text
    for (int row = 0; row < 6; ++row)
    {
        std::cout << "|";
        for (int col = 0; col < 3; ++col)
        {
            std::cout << std::setw(24) << std::left << " "; // Placeholder for text
            std::cout << "|";
        }
        std::cout << std::endl;

        // Print the horizontal line between rows
        if (row < 5)
        {
            std::cout << "+------------------------+------------------------+------------------------+" << std::endl;
        }
    }
}

/*
void Game::Present_instructionsand_keys()
{
   
}
*/


