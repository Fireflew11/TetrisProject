﻿#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>
#include "GlobalFunctions.h"


/**********************************************************************
Function name: keyChoice
Input:gameConfig::LeftKeys key, Shape& shape
Output: --
Function:The function handles the Left player's key choices for movement, rotation, and dropping.
**********************************************************************/
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
        {
            if (shape.getShapeType()!= gameConfig::ShapeType::O)
               shape.rotate_Clock_wise(players[0].getPlayerBoard());
            break;
        }
            
        case gameConfig::LeftKeys::ROTATE_COUNTER_CLOCK_WISE:
        {
            if (shape.getShapeType() != gameConfig::ShapeType::O)
                shape.rotate_CounterClock_wise(players[0].getPlayerBoard());
            break;
                
        }
        case gameConfig::LeftKeys::DROP:
            shape.drop(players[0].getPlayerBoard());
            break;
        default:
            break; 
    }
}

/**********************************************************************
Function name: keyChoice
Input:gameConfig::LeftKeys key, Shape& shape
Output: --
Function:The function handles the Right player's key choices for movement, rotation, and dropping.
**********************************************************************/
void Game::keyChoice(gameConfig::RightKeys key, Shape& shape)
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
    {
        if (shape.getShapeType()!= gameConfig::ShapeType::O)
            shape.rotate_Clock_wise(players[1].getPlayerBoard());
        break;
    } 
    case gameConfig::RightKeys::ROTATE_COUNTER_CLOCK_WISE:
    {
        if(shape.getShapeType() != gameConfig::ShapeType::O)
            shape.rotate_CounterClock_wise(players[1].getPlayerBoard());
        break;
    }
    case gameConfig::RightKeys::DROP:
        shape.drop(players[1].getPlayerBoard());
        break;
    default:
        break;
    }
}

/**********************************************************************
Function name: GameLoop
Input: --
Output: --
Function:The main game loop responsible for managing the gameplay, player moves, and checking game conditions.
**********************************************************************/
void Game::GameLoop()
{
    bool isGameOver = false;
    players[0].displayScore();
    players[1].displayScore();
    while (!isGameOver)// Main game loop
    {
        Shape curShapePlayer1(gameConfig::PlayerType::LEFT_PLAYER, useColors); // Create new shapes for each player
        Shape curShapePlayer2(gameConfig::PlayerType::RIGHT_PLAYER, useColors);
        if (!checkGameValidity(curShapePlayer1, curShapePlayer2, isGameOver))
            break;       
        while (true)// Inner loop for handling player movements and shape placements
        {    
            // Update scores and handle user input
            players[0].updateScore(players[0].getPlayerBoard().clearFullLines());
            players[1].updateScore(players[1].getPlayerBoard().clearFullLines());
            handleInput(curShapePlayer1, curShapePlayer2);

            // Move shapes down for both players
            bool movedDownPlayer1 = curShapePlayer1.continueMovingDown(players[0].getPlayerBoard());
            bool movedDownPlayer2 = curShapePlayer2.continueMovingDown(players[1].getPlayerBoard());

            // Check if both shapes reached the bottom
            if (!movedDownPlayer1 && !movedDownPlayer2)
            {
                players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                if ((this->isGameOver()))
                {
                    isGameOver = true;
                }
                break;
            }
            // Handle shape movements and updates for player 1
            if (!movedDownPlayer1)
            {
                if (checkGameConditions(players[0], curShapePlayer1, isGameOver))
                    break; 
            }
            if (!movedDownPlayer2)
            {
                if (checkGameConditions(players[1], curShapePlayer2, isGameOver))
                    break;
            }
            
        }
    }
}

bool Game::checkGameConditions(Player& player, Shape& shape, bool& isGameOver)
{
    
    player.getPlayerBoard().implementShapeToBoard(shape); 
    if ((this->isGameOver()))// Check if the game is over after placing the shape
    {
        isGameOver = true;
        return true; 
    }
    // Reset the shape for the next iteration
    shape = Shape(player.getPlayerType(), useColors);

    // Check if the new shape is valid, if not, set the other player as the winner
    if (!(player.getPlayerBoard().check_valid_move(shape)))
    {
        if (player.getPlayerType() == gameConfig::PlayerType::LEFT_PLAYER)
            players[1].setIsWinner(true);
        else
            players[0].setIsWinner(true);
        isGameOver = true;
        status = gameConfig::GameStatus::Finish;
        return true; 
    }
    return false; 
    
}

/**********************************************************************
Function name: checkKeyChoice
Input:int keyPressed, Shape& Leftshape,Shape& RightShape
Output:--
Function:The function checks the key pressed by the player and calls the appropriate keyChoice function for the respective player.
**********************************************************************/
void Game:: checkKeyChoice(int keyPressed, Shape& Leftshape,Shape& RightShape)
{
    keyPressed = toupperG(keyPressed);
    //keyPressed = toupper(keyPressed); 
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

bool Game::isGameOver() 
{
    for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
    {
        if (players[0].getPlayerBoard().getBoardGame()[0][i].getIsActive())
        {
            players[1].setIsWinner(true); 
            break; 
        }
    }
    for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
    {
        if (players[1].getPlayerBoard().getBoardGame()[0][i].getIsActive())
        {
            players[0].setIsWinner(true);
            break;
        }
    }
    if ((players[0].getIsWinner() || players[1].getIsWinner()))
        status = gameConfig::GameStatus::Finish;
    return (players[0].getIsWinner() || players[1].getIsWinner()); 
    
}

/**********************************************************************
Function name:startGame
Input: --
Output: --
Function:Initiates or continues the game based on user input, handling different game statuses.
**********************************************************************/
void Game::startGame()
{
    bool isMenuVisible = false;
    char keyPressed = 0;
    // Main loop for game status handling
    while (status != gameConfig::GameStatus::Ended)
    {
        if (status == gameConfig::GameStatus::Finish)
        {
            // Announce the winner and reset the game
            announceWinner();
            isMenuVisible = false;
            players[0] = Player(gameConfig::PlayerType::LEFT_PLAYER);
            players[1] = Player(gameConfig::PlayerType::RIGHT_PLAYER);
            status = gameConfig::GameStatus::NewGame;
        }
        // Clear the console, print the menu, and set the menu visibility flag
        if (!isMenuVisible) {
            system("cls");
            Print_Menu();
            isMenuVisible = true;
        }
         keyPressed = _getch();
         // Check the pressed key for different menu options
        if (keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME || keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS)
        {
            if (keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS)
                useColors = false;
            else
                useColors = true;
            system("cls");
            // Check if the game was paused, reset players, and set the game status to NewGame
            if (status == gameConfig::GameStatus::Paused)
            {
                players[0] = Player(gameConfig::PlayerType::LEFT_PLAYER);
                players[1] = Player(gameConfig::PlayerType::RIGHT_PLAYER);
                status = gameConfig::GameStatus::NewGame;
                return; 

            }
            // Main loop for handling NewGame and Running status
            while (status == gameConfig::GameStatus::NewGame || status == gameConfig::GameStatus::Running)
            {
                players[0].getPlayerBoard().setUseColor(useColors);
                players[1].getPlayerBoard().setUseColor(useColors);
                players[0].getPlayerBoard().display_board();
                players[1].getPlayerBoard().display_board();
                GameLoop();
            }

        }
        // Continue a paused game by displaying player boards and scores
        else if (keyPressed == (char)gameConfig::MenuOption::CONTINUE_PAUSED_GAME && status == gameConfig::GameStatus::Paused)
        {
            system("cls");
            players[0].getPlayerBoard().display_board();
            players[1].getPlayerBoard().display_board();
            players[0].displayScore();
            players[1].displayScore();
            return;
        }
        else if (keyPressed == (char)gameConfig::MenuOption::PRESENT_INSTRUCTIONS)
        {
            system("cls");
            Present_instructionsand_keys();
            Print_Menu();
        }
        
        else if (keyPressed == (char)gameConfig::MenuOption::EXIT)
        {
            system("cls");
            status = gameConfig::GameStatus::Ended;
            return;
        }
    }
}

/**********************************************************************
 Helper function to print a row in the instructionsand_keys.
**********************************************************************/
void Game::printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn)
{
    cout << "|" << setw(24) << left << firstColumn << "|" << setw(24) << left << secondColumn << "|" << setw(24) << left << thirdColumn << "|" << std::endl;
}
/**********************************************************************
 Helper function to print a separator line in the instructionsand_keys.
**********************************************************************/
void Game::printSeparator()
{
    cout << "+------------------------+------------------------+------------------------+" << std::endl;
}

/**********************************************************************
Function name: Game(Constructor)
Input:useColors: A boolean indicating whether colors are enabled in the game,
status: The initial status of the game (default: gameConfig::GameStatus::Running).
Output:--
Function:Constructor for the Game class. Initializes the game with specified color settings and initial status.
Creates instances of Player for the left and right players.
**********************************************************************/
Game::Game(bool useColors, gameConfig::GameStatus status):players{Player(gameConfig::PlayerType::LEFT_PLAYER),Player(gameConfig::PlayerType::RIGHT_PLAYER)},status(status),useColors(useColors)
{}

/**********************************************************************
Function name: Print_Menu
Input:--
Output:--
Function:Displays the main menu options
**********************************************************************/
void Game:: Print_Menu()
{
    system("cls");
    cout << "(1) Start a new game" << endl; 
    if(status == gameConfig::GameStatus::Paused)
        cout << "(2) Continue a paused game" << endl; 
    cout << "(3) Start a new game without colors" << endl; 
    cout << "(8) Present instructionsand keys" << endl; 
    cout << "(9) EXIT" << endl; 
}

/**********************************************************************
Function name: Present_instructionsand_keys
Input:--
Output:--
Function: Displays the key instructions for player controls
**********************************************************************/
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
    cout << "Press ANY key to return to menu...";
    char ch=_getch();
}

/**********************************************************************
Function name: announceWinner
Input:--
Output:--
Function:Displays the winner of the game
**********************************************************************/
void Game::announceWinner()
{
    system("cls"); 
    gotoxy(gameConfig::WINNDER_ANNOUNCEMENT_POS_X, gameConfig::WINNDER_ANNOUNCEMENT_POS_Y); 
    if (players[0].getIsWinner() && players[1].getIsWinner())
    {
        if (players[0].getScore() > players[1].getScore())
        {
            cout << "The winner is: Player1 with " << players[0].getScore()<< " points."<< endl;
        }
        else if (players[1].getScore() > players[0].getScore())
        {
            cout << "The winner is: Player2 with " << players[1].getScore()<< " points."<<endl;

        }
        else
        {
            cout << "It's a tie! Both players have "<< players[0].getScore()<<  " points." << endl; 
        }
    }
    else if (players[0].getIsWinner())
    {
        cout << "The winner is: Player1 with "<< players[0].getScore() <<" points." << endl;
    }
    else 
    {
        cout << "The winner is: Player2 with " <<players[1].getScore() << " points." << endl;
    }
    cout << "Press ANY key to return to menu...";
    char ch=_getch();

    
}
/**********************************************************************
Function name: checkGameValidity
Input:const Shape& ShapePlayer1, const Shape& ShapePlayer2, bool& isGameOver
Output:Returns true if the game is still valid; false if the game is over.
Function:Checks the validity of the game based on the current positions of player shapes.
**********************************************************************/
bool Game::checkGameValidity(const Shape& ShapePlayer1, const Shape& ShapePlayer2, bool& isGameOver)
{
    if (!(players[0].getPlayerBoard().check_valid_move(ShapePlayer1)) || !(players[1].getPlayerBoard().check_valid_move(ShapePlayer2)))
    {
        if (!(players[0].getPlayerBoard().check_valid_move(ShapePlayer1)))
        {
            players[1].setIsWinner(true);
        }
        if (!(players[1].getPlayerBoard().check_valid_move(ShapePlayer2)))
        {
            players[0].setIsWinner(true);
        }
        isGameOver = true;
        status = gameConfig::GameStatus::Finish;
        return false; 
    }
    return true; 
}

/**********************************************************************
Function name:handleInput
Input: Shape& curShapePlayer1, Shape& curShapePlayer2
Output:--
Function:Handles user input during the game, updating player scores and checking for key presses.
Calls checkKeyChoice to interpret and act upon key presses, and allows for pausing the game.
**********************************************************************/
void Game::handleInput(Shape& curShapePlayer1, Shape& curShapePlayer2)
{
    players[0].updateScore(players[0].getPlayerBoard().clearFullLines());
    players[1].updateScore(players[1].getPlayerBoard().clearFullLines());
    for (int i = 0; i < 5; i++)
    {
        if (_kbhit())
        {
            int keyPressed = _getch();
            if (keyPressed == (int)gameConfig::ESC)
            {
                status = gameConfig::GameStatus::Paused;
                startGame();
                if (status == gameConfig::GameStatus::Ended || status == gameConfig::GameStatus::NewGame)
                    return;
            }
            else
                checkKeyChoice(keyPressed, curShapePlayer1, curShapePlayer2);
        }
    }
    Sleep(300);
}

