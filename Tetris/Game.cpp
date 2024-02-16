#include "Game.h"
#include "gameConfig.h"
#include "Shape.h" 
#include "Board.h"
#include <cctype>
#include "GlobalFunctions.h"
#include "ComplexShape.h"
#include "O_Shape.h"
#include "Z_Shape.h"
#include "T_Shape.h"
#include "L_Shape.h"
#include "I_Shape.h"
#include "J_Shape.h"
#include "S_Shape.h"
#include "Bomb.h"
/**********************************************************************
Function name: GameLoop
Input: --
Output: --
Function:The main game loop responsible for managing the gameplay, player moves, and checking game conditions.
**********************************************************************/
void Game::GameLoop()
{
    bool isGameOver = false;

    players[0]->displayScore();
    players[1]->displayScore();
    while (!isGameOver)// Main game loop
    {
        if (status != gameConfig::GameStatus::Paused) {
            currentShapeLeftPlayer = createRandomShape(*players[0]);
            currentShapeRightPlayer = createRandomShape(*players[1]);
        }
        currentShapeLeftPlayer->drawShape();
        currentShapeRightPlayer->drawShape();
        status = gameConfig::GameStatus::Running;

        while (true)// Inner loop for handling player movements and shape placements
        {    
            //handleInput returns true if ESC was pressed
            if (handleInput())
                return;

            Sleep(250);

            // Move shapes down for both players
            bool movedDownPlayer1 = true, movedDownPlayer2 = true;
            moveShapesDown(currentShapeLeftPlayer, currentShapeRightPlayer, movedDownPlayer1, movedDownPlayer2);
            

            // Check if both shapes reached the bottom
            if (!movedDownPlayer1 && !movedDownPlayer2)
            {
                currentShapeLeftPlayer->implementShapeToBoard(players[0]->getPlayerBoard(), true); 
                currentShapeRightPlayer->implementShapeToBoard(players[1]->getPlayerBoard(), true);

                ResetIfComputer(players[0]);
                ResetIfComputer(players[1]);
                isGameOver = isMaxHeight();
                break;
            }
            // Handle shape movements and updates for player 1
            if (!movedDownPlayer1)
            {
                ResetIfComputer(players[0]);
                if (checkGameConditions(*players[0], currentShapeLeftPlayer, isGameOver))
                    break; 
            }
            // Handle shape movements and updates for player 2
            if (!movedDownPlayer2)
            {
                ResetIfComputer(players[1]);
                if (checkGameConditions(*players[1], currentShapeRightPlayer, isGameOver))
                    break;
            }
            
        }
    }
}
void Game::ResetIfComputer(Player* player) {
    Computer* computerPlayer = dynamic_cast<Computer*>(player);
    if (computerPlayer)
        computerPlayer->resetTargets();
}
void Game::moveShapesDown(Shape* shapeLeft, Shape* shapeRight, bool& movedDownPlayer1, bool& movedDownPlayer2) {
    shapeLeft->drawShape(false);
    shapeRight->drawShape(false);
    movedDownPlayer1 = shapeLeft->continueMovingDown(players[0]->getPlayerBoard());
    movedDownPlayer2 = shapeRight->continueMovingDown(players[1]->getPlayerBoard());
    shapeLeft->drawShape();
    shapeRight->drawShape();
}
/**********************************************************************
Function name: checkGameConditions
Input:Player& player, Shape& shape, bool& isGameOver
Output: bool
Function:The function checks if the game is over or if it's not, it rerolls the shape to a new one
if 1. a player reaches the max height with blocks this player loses
or 2. The newly created shape cannot go down
**********************************************************************/
bool Game::checkGameConditions(Player& player, Shape* & shape, bool& isGameOver)
{
    shape->implementShapeToBoard(player.getPlayerBoard(), true); 
    
    //player.getPlayerBoard().implementShapeToBoard(shape); 
    if ((isMaxHeight()))// Check if the game is over after placing the shape
    {
        isGameOver = true;
        return true; 
    }
    // Reroll the shape for the next iteration
    shape = createRandomShape(player);//צריך להכניס useColors /////
    
    // Check if the new shape is valid, if not, set the other player as the winner, and end the game

    if (!shape->check_valid_move(player.getPlayerBoard()))
    {
        if (player.getPlayerType() == gameConfig::PlayerType::LEFT_PLAYER)
            players[1]->setIsWinner(true);
        else
            players[0]->setIsWinner(true);
        isGameOver = true;
        status = gameConfig::GameStatus::Finished;
        return true; 
    }
    return false; 
    
}

void Game::initializePlayers(char pick, gameConfig::ComputerLevel level)
{
    if (players[0] != nullptr && players[1] != nullptr) 
    {
        delete players[0];
        delete players[1];
        players[0] = players[1] = nullptr;
    }
    MenuOption option = (MenuOption)pick;
    switch (option) 
    {
    case MenuOption::START_NEW_GAME_PVP:
        players[0] = new Human(gameConfig::PlayerType::LEFT_PLAYER);
        players[1] = new Human(gameConfig::PlayerType::RIGHT_PLAYER);
        break;
    case MenuOption::START_NEW_GAME_PVC:
        players[0] = new Human(gameConfig::PlayerType::LEFT_PLAYER);
        players[1] = new Computer(gameConfig::PlayerType::RIGHT_PLAYER, level);
        break;
    case MenuOption::START_NEW_GAME_CVC:
        players[0] = new Computer(gameConfig::PlayerType::LEFT_PLAYER, level);
        players[1] = new Computer(gameConfig::PlayerType::RIGHT_PLAYER, level);
    default:
        break;
    }
}




/**********************************************************************
Function name:isMaxHeight
Input: --
Output: bool, returns true if a player reaches the max height with blocks, else false
Function:Initiates or continues the game based on the game state, handling different game statuses.
**********************************************************************/
bool Game::isMaxHeight()
{
    for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
    {
        if (players[0]->getPlayerBoard().getBoardGame()[0][i].getIsActive())
        {
            players[1]->setIsWinner(true); 
            break; 
        }
    }
    for (int i = 0; i < gameConfig::GAME_WIDTH; i++)
    {
        if (players[1]->getPlayerBoard().getBoardGame()[0][i].getIsActive())
        {
            players[0]->setIsWinner(true);
            break;
        }
    }
    if ((players[0]->getIsWinner() || players[1]->getIsWinner()))
        status = gameConfig::GameStatus::Finished;
    return (players[0]->getIsWinner() || players[1]->getIsWinner()); 
    
}

/**********************************************************************
Function name:startGame
Input: --
Output: --
Function:Initiates or continues the game based on user input, handling different game statuses.
**********************************************************************/


//this is the original 
void Game::startGame2()
{
    bool isMenuVisible = false;
    char keyPressed = 0;
    // Main loop for game status handling
    while (status != gameConfig::GameStatus::Ended)
    {

        if (status == gameConfig::GameStatus::Finished)
        {
            // Announce the winner and reset the game
            announceWinner();
            isMenuVisible = false;
            status = gameConfig::GameStatus::Menu;
        }
        // Clear the console, print the menu, and set the menu visibility flag
        // Using isMenuVisible to prevent continuous blinking if pressing random key
        if (!isMenuVisible) 
        {
            system("cls");
            Print_Menu();
            isMenuVisible = true;
        }
         keyPressed = _getch();
         // Check the pressed key for different menu options
         
        if (keyPressed == (char)MenuOption::START_NEW_GAME_PVP /*'1'*/ ||
            keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS/*'3'*/ ||
            keyPressed == (char)MenuOption::START_NEW_GAME_PVC/*'3'*/ ||
            keyPressed == (char)MenuOption::START_NEW_GAME_CVC/*'4'*/)
        {
            initializePlayers(keyPressed);
            if (keyPressed == (char)gameConfig::MenuOption::START_NEW_GAME_WITHOUT_COLORS/*'3'*/)
                useColors = false;
            else
                useColors = true;
            system("cls");
            isMenuVisible = false;
            players[0]->getPlayerBoard().setUseColor(useColors);
            players[1]->getPlayerBoard().setUseColor(useColors);
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            status = gameConfig::GameStatus::NewGame;
            GameLoop();

        }
        // Continue a paused game by displaying player boards and scores
        else if (keyPressed == (char)gameConfig::MenuOption::CONTINUE_PAUSED_GAME && status == gameConfig::GameStatus::Paused)
        {
            system("cls");
            isMenuVisible = false;
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            players[0]->displayScore();
            players[1]->displayScore();
            GameLoop();
        }
        else if (keyPressed == (char)gameConfig::MenuOption::PRESENT_INSTRUCTIONS)
        {
            system("cls");
            isMenuVisible = false;
            Present_instructionsand_keys();
        }
        
        else if (keyPressed == (char)gameConfig::MenuOption::EXIT)
        {
            system("cls");
            isMenuVisible = false;
            status = gameConfig::GameStatus::Ended;
            return;
        }
    }
}

void Game::startGame1()
{
    bool isMenuVisible = false;
    char keyPressed = 0;
    // Main loop for game status handling
    while (status != gameConfig::GameStatus::Ended)
    {

        if (status == gameConfig::GameStatus::Finished)
        {
            // Announce the winner and reset the game
            announceWinner();
            isMenuVisible = false;
            status = gameConfig::GameStatus::Menu;
        }
        // Clear the console, print the menu, and set the menu visibility flag
        // Using isMenuVisible to prevent continuous blinking if pressing random key
        if (!isMenuVisible)
        {
            system("cls");
            if (status == gameConfig::GameStatus::Menu)
            {
                Print_Menu();
            }
            else if (status == gameConfig::GameStatus::MenuWithoutColors)
            {
                Print_No_Colors_Menu();
            }
            //else 
            //{
              //  Print_Computer_Level_Menu();
           // }
            isMenuVisible = true;
        }










        keyPressed = _getch();
        // Check the pressed key for different menu options
        switch (keyPressed)
        {
        case static_cast<int>(MenuOption::START_NEW_GAME_PVP):
        {
            initializePlayers(keyPressed);
            system("cls");
            isMenuVisible = false;
            players[0]->getPlayerBoard().setUseColor(useColors);
            players[1]->getPlayerBoard().setUseColor(useColors);
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            status = gameConfig::GameStatus::NewGame;
            GameLoop();
            break;
        }
        case static_cast<int>(MenuOption::START_NEW_GAME_CVC):
        case static_cast<int>(MenuOption::START_NEW_GAME_PVC):
        {
            system("cls");
            Print_Computer_Level_Menu();
            gameConfig::ComputerLevel ComuterLevel = Computer_Level_Selection();
            initializePlayers(keyPressed, ComuterLevel);
            isMenuVisible = false;
            players[0]->getPlayerBoard().setUseColor(useColors);
            players[1]->getPlayerBoard().setUseColor(useColors);
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            status = gameConfig::GameStatus::NewGame;
            GameLoop();
        }
        case static_cast<int>(MenuOption::CONTINUE_PAUSED_GAME):
        {
            if (status == gameConfig::GameStatus::Paused)
            {
                system("cls");
                isMenuVisible = false;
                players[0]->getPlayerBoard().display_board();
                players[1]->getPlayerBoard().display_board();
                players[0]->displayScore();
                players[1]->displayScore();
                GameLoop();
            }
            break;
        }
        case static_cast<int>(MenuOption::START_NEW_GAME_WITHOUT_COLORS):
        {
            useColors = false;
            status = gameConfig::GameStatus::MenuWithoutColors;
            break;
        }
        case static_cast<int>(MenuOption::PRESENT_INSTRUCTIONS):
        {
            system("cls");
            isMenuVisible = false;
            Present_instructionsand_keys();
            break;
        }
        case static_cast<int>(MenuOption::EXIT):
        {
            system("cls");
            isMenuVisible = false;
            status = gameConfig::GameStatus::Ended;
            break;
        }
        default:
            break;
        }
    }
}

void Game::startGame()
{
    bool isMenuVisible = false;
    char keyPressed = 0;
    // Main loop for game status handling
    while (status != gameConfig::GameStatus::Ended)
    {

        if (status == gameConfig::GameStatus::Finished)
        {
            // Announce the winner and reset the game
            announceWinner();
            isMenuVisible = false;
            status = gameConfig::GameStatus::Menu;
        }
        // Clear the console, print the menu, and set the menu visibility flag
        // Using isMenuVisible to prevent continuous blinking if pressing random key
        if (!isMenuVisible)
        {
            system("cls");
            if (status == gameConfig::GameStatus::MenuWithoutColors)
            {
                Print_No_Colors_Menu();
            }
            else
            {
                Print_Menu(); 
            }
            isMenuVisible = true;
        }
        keyPressed = _getch();
        // Check the pressed key for different menu options
        switch (keyPressed)
        {
        case static_cast<int>(MenuOption::START_NEW_GAME_PVP):
        {
            initializePlayers(keyPressed);
            system("cls");
            isMenuVisible = false;
            players[0]->getPlayerBoard().setUseColor(useColors);
            players[1]->getPlayerBoard().setUseColor(useColors);
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            status = gameConfig::GameStatus::NewGame;
            GameLoop();
            break;
        }
        case static_cast<int>(MenuOption::START_NEW_GAME_CVC):
        case static_cast<int>(MenuOption::START_NEW_GAME_PVC):
        {
            system("cls");
            Print_Computer_Level_Menu();
            gameConfig::ComputerLevel computerLevel = Computer_Level_Selection();
            initializePlayers(keyPressed, computerLevel);
            isMenuVisible = false;

            players[0]->getPlayerBoard().setUseColor(useColors);
            players[1]->getPlayerBoard().setUseColor(useColors);
            players[0]->getPlayerBoard().display_board();
            players[1]->getPlayerBoard().display_board();
            status = gameConfig::GameStatus::NewGame;
            GameLoop();
            break;
        }
        case static_cast<int>(MenuOption::CONTINUE_PAUSED_GAME):
        {
            if (status == gameConfig::GameStatus::Paused)
            {
                system("cls");
                isMenuVisible = false;
                players[0]->getPlayerBoard().display_board();
                players[1]->getPlayerBoard().display_board();
                players[0]->displayScore();
                players[1]->displayScore();
                GameLoop();
            }
            break;
        }
        case static_cast<int>(MenuOption::START_NEW_GAME_WITHOUT_COLORS):
        {
            useColors = false;
            isMenuVisible = false;
            status = gameConfig::GameStatus::MenuWithoutColors;
            break;
        }
        case static_cast<int>(MenuOption::PRESENT_INSTRUCTIONS):
        {
            system("cls");
            isMenuVisible = false;
            Present_instructionsand_keys();
            break;
        }
        case static_cast<int>(MenuOption::EXIT):
        {
            system("cls");
            isMenuVisible = false;
            status = gameConfig::GameStatus::Ended;
            break;
        }
        default:
            break;
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
Game::Game(bool useColors, gameConfig::GameStatus status, Shape* ShapeLeftPlayer, Shape* ShapeRightPlayer):players{nullptr, nullptr},status(status),
useColors(useColors), currentShapeLeftPlayer(ShapeLeftPlayer), currentShapeRightPlayer(ShapeRightPlayer)
{}

/**********************************************************************
Function name: Print_Menu
Input:--
Output:--
Function:Displays the main menu options
**********************************************************************/
void Game:: Print_Menu()
{
    cout <<"(1) Start a new game - Human vs Human" << endl; 
    cout <<"(2) Start a new game - Human vs Computer" << endl; 
    cout <<"(3) Start a new game - Computer vs Computer" << endl;
    if (status == gameConfig::GameStatus::Paused)
        cout <<"(4) Continue a paused game" << endl; 
    cout <<"(5) Start a new game without colors" << endl; 
    cout <<"(8) Present instructions and keys" << endl;
    cout << "(9) EXIT" << endl; 
}

void Game::Print_No_Colors_Menu()
{
    cout << "(1) Start a new game without colors- Human vs Human" << endl;
    cout << "(2) Start a new game without colors- Human vs Computer" << endl;
    cout << "(3) Start a new game without colors- Computer vs Computer" << endl;
    cout << "(8) Present instructions and keys" << endl;
    cout << "(9) EXIT" << endl;
}

void Game::Print_Computer_Level_Menu()
{
    cout << "Choose computer shall have 3 levels" << endl; 
    cout << "(a) BEST" << endl; 
    cout << "(b) GOOD" << endl; 
    cout << "(c) NOVICE" << endl; 

}

gameConfig::ComputerLevel Game::Computer_Level_Selection()
{
    gameConfig::ComputerLevel level;
    bool validInput = false;
    while (!validInput)
    {
        char selection = _getch();
        switch (selection)
        {
        case 'a':
            level = gameConfig::ComputerLevel::BEST;
            validInput = true;
            break;
        case 'b':
            level = gameConfig::ComputerLevel::GOOD;
            validInput = true;
            break;
        case 'c':
            level = gameConfig::ComputerLevel::NOVICE;
            validInput = true;
            break;
        default:
            break;
        }
    }
    system("cls");
    return level;
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
    //print menu after user finished looking at instructions
    Print_Menu();
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
    if (players[0]->getIsWinner() && players[1]->getIsWinner())
    {
        if (players[0]->getScore() > players[1]->getScore())
        {
            cout << "The winner is: Player1 with " << players[0]->getScore()<< " points."<< endl;
        }
        else if (players[1]->getScore() > players[0]->getScore())
        {
            cout << "The winner is: Player2 with " << players[1]->getScore()<< " points."<<endl;

        }
        else
        {
            cout << "It's a tie! Both players have "<< players[0]->getScore()<<  " points." << endl; 
        }
    }
    else if (players[0]->getIsWinner())
    {
        cout << "The winner is: Player1 with "<< players[0]->getScore() <<" points." << endl;
    }
    else 
    {
        cout << "The winner is: Player2 with " <<players[1]->getScore() << " points." << endl;
    }
    gotoxy(gameConfig::WINNDER_ANNOUNCEMENT_POS_X, gameConfig::WINNDER_ANNOUNCEMENT_POS_Y + 5);
    cout << "Press ANY key to return to menu...";
    char ch=_getch();

    
}

/**********************************************************************
Function name: checkGameValidity
Input:const Shape& ShapePlayer1, const Shape& ShapePlayer2, bool& isGameOver
Output:Returns true if the game is still valid; false if the game is over.
Function:Checks the validity of the game based on the current positions of player shapes.
**********************************************************************/
bool Game::checkGameValidity(bool& isGameOver)
{
   
    bool validityLeftPlayer = currentShapeLeftPlayer->check_valid_move(players[0]->getPlayerBoard());
    bool validityRightPlayer = currentShapeRightPlayer->check_valid_move(players[1]->getPlayerBoard());
    if (!validityLeftPlayer || !validityRightPlayer)
    {
        if (!validityLeftPlayer)
        {
            players[1]->setIsWinner(true);
        }
        if (!validityRightPlayer)
        {
            players[0]->setIsWinner(true);
        }
        isGameOver = true;
        status = gameConfig::GameStatus::Finished;
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
bool Game::handleInput()
{
    players[0]->updateScore(players[0]->getPlayerBoard().clearFullLines());
    players[1]->updateScore(players[1]->getPlayerBoard().clearFullLines());
    char keyPressed = 0;
    if (_kbhit()) {
        keyPressed = toupperG(_getch());
        if (keyPressed == gameConfig::ESC)
        {
            status = gameConfig::GameStatus::Paused;
            return true;
        }
    }
    players[0]->decideMove(*currentShapeLeftPlayer, keyPressed);
    players[1]->decideMove(*currentShapeRightPlayer, keyPressed);

    return false;
}

Shape* Game::createRandomShape(const Player& player)
{

    Shape* newShape = nullptr;
    bool bombppearance = isBombAppearance(); 
    /*
    bool bombppearance = false;
    static int cont = 0; 
    cont++; 
    if(cont==7)
    */
    if (bombppearance)
    {
      newShape = new Bomb(useColors, player.getStartingX(), player.getStartingY());
    }
    else
    {
        int randomShape = rand() % (int)gameConfig::NUM_OF_SHAPES + 1;
        
        switch ((gameConfig::ShapeType)randomShape)
        {
        case gameConfig::ShapeType::I:
        {
            newShape = new I_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;
        }
        case  gameConfig::ShapeType::O:
        {
            newShape = new O_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;
        }
        case  gameConfig::ShapeType::T:
        {
            newShape = new T_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;
        }

        case  gameConfig::ShapeType::S:
        {
            newShape = new S_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;
        }

        case  gameConfig::ShapeType::Z:
        {
            newShape = new Z_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;
        }
        case  gameConfig::ShapeType::J:
        {
            newShape = new J_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;

        }

        case  gameConfig::ShapeType::L:
        {
            newShape = new L_Shape(useColors, player.getStartingX(), player.getStartingY());
            break;

        }

        default:
            break;
        }
    }
    return newShape; 
}

bool Game::isBombAppearance()
{
    int randomNumber = rand() % 20 + 1; 
    if (randomNumber == 1)
        return true; 
    return false; 
}