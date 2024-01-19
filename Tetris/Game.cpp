#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>
#include "GlobalFunctions.h"



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


void Game::GameLoop()
{
    bool isGameOver = false;
    players[0].displayScore();
    players[1].displayScore();
    while (!isGameOver)
    {
        Shape curShapePlayer1(gameConfig::PlayerType::LEFT_PLAYER, useColors);
        Shape curShapePlayer2(gameConfig::PlayerType::RIGHT_PLAYER, useColors);

        //להכניס לפונקציה 
        if (!(players[0].getPlayerBoard().check_valid_move(curShapePlayer1)) || !(players[1].getPlayerBoard().check_valid_move(curShapePlayer2)))
        {
            if (!(players[0].getPlayerBoard().check_valid_move(curShapePlayer1)))
            {
                players[1].setIsWinner(true);
            }
            if (!(players[1].getPlayerBoard().check_valid_move(curShapePlayer1)))
            {
                players[0].setIsWinner(true);
            }
            isGameOver=true; 
            status = gameConfig::GameStatus::Finish; 
            break; 
        }

        while (true)
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
                    {
                        checkKeyChoice(keyPressed, curShapePlayer1, curShapePlayer2);
                    }
                }
            }
            Sleep(300);

            bool movedDownPlayer1 = curShapePlayer1.continueMovingDown(players[0].getPlayerBoard());
            bool movedDownPlayer2 = curShapePlayer2.continueMovingDown(players[1].getPlayerBoard());
            if (!movedDownPlayer1 && !movedDownPlayer2)
            {
                players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                if ((this->isGameOver()))
                {
                    isGameOver = true;
                    break;
                }
                break;
            }
            if (!movedDownPlayer1)
            {
                players[0].getPlayerBoard().implementShapeToBoard(curShapePlayer1);
                if ((this->isGameOver()))
                {
                    isGameOver = true;
                    break;
                }
                curShapePlayer1 = Shape(gameConfig::PlayerType::LEFT_PLAYER,useColors); 
                if (!(players[0].getPlayerBoard().check_valid_move(curShapePlayer1)))
                {
                    players[1].setIsWinner(true);
                    isGameOver = true;
                    status = gameConfig::GameStatus::Finish;
                    break;
                } 
            }
            if (!movedDownPlayer2)
            {
                players[1].getPlayerBoard().implementShapeToBoard(curShapePlayer2);
                if ((this->isGameOver()))
                {
                    isGameOver = true;
                    break;
                }
                curShapePlayer2 = Shape(gameConfig::PlayerType::RIGHT_PLAYER, useColors);
                if (!(players[1].getPlayerBoard().check_valid_move(curShapePlayer2)))
                {
                    players[0].setIsWinner(true);
                    isGameOver = true;
                    status = gameConfig::GameStatus::Finish;
                    break;
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




void Game::startGame()
{
    bool isMenuVisible = false;
    char keyPressed = 0;
    while (status != gameConfig::GameStatus::Ended)
    {
        if (status == gameConfig::GameStatus::Finish)
        {
            announceWinner();
            isMenuVisible = false;
            players[0] = Player(gameConfig::PlayerType::LEFT_PLAYER);
            players[1] = Player(gameConfig::PlayerType::RIGHT_PLAYER);
            status = gameConfig::GameStatus::NewGame;
        }
        if (!isMenuVisible) {
            system("cls");
            Print_Menu();
            isMenuVisible = true;
        }
         keyPressed = _getch();
        if (keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME || keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS)
        {
            if (keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS)
                useColors = false;
            else
                useColors = true;
            system("cls");
            if (status == gameConfig::GameStatus::Paused)
            {
                players[0] = Player(gameConfig::PlayerType::LEFT_PLAYER);
                players[1] = Player(gameConfig::PlayerType::RIGHT_PLAYER);
                status = gameConfig::GameStatus::NewGame;
                return; 

            }
            while (status == gameConfig::GameStatus::NewGame || status == gameConfig::GameStatus::Running)
            {
                players[0].getPlayerBoard().setUseColor(useColors);
                players[1].getPlayerBoard().setUseColor(useColors);
                players[0].getPlayerBoard().display_board();
                players[1].getPlayerBoard().display_board();
                GameLoop();
            }

        }
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

void Game::printRow(const string& firstColumn, const string& secondColumn, const string& thirdColumn)
{
    cout << "|" << setw(24) << left << firstColumn << "|" << setw(24) << left << secondColumn << "|" << setw(24) << left << thirdColumn << "|" << std::endl;
}
void Game::printSeparator()
{
    cout << "+------------------------+------------------------+------------------------+" << std::endl;
}


Game::Game(bool useColors, gameConfig::GameStatus status):players{Player(gameConfig::PlayerType::LEFT_PLAYER),Player(gameConfig::PlayerType::RIGHT_PLAYER)},status(status),useColors(useColors)
{

}

void Game:: Print_Menu()
{
    system("cls");
    cout << "(1) Start a new game" << endl; 
    if(status == gameConfig::GameStatus::Paused)
        cout << "(2) Continue a paused game" << endl; 
    cout << "(3) Start a new game without colors" << endl; 
    //cout << "(3) Run with colors" << endl;
    //cout << "(4) Run without colors" << endl;
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
    cout << "Press ANY key to return to menu...";
    _getch();
}

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
    _getch();

    
}

