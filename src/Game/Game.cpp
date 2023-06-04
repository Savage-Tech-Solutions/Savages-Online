/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "Game.hpp"

/*************************************************
* Default Constructor
*************************************************/
Game::Game() {
    this->version = ("0.0.1");
    this->help = "Type $help for help answering questions...";
    this->usersOnline = 0;
    this->license = "GNU GENERAL PUBLIC LICENSE";

    Contributor temp;  // Temp variable to push new Contributors into vector.

    temp.name = "Bryce";
    temp.discordUsername = "Bryce#7777";
    collaboratorArray->push_back(temp);
    
    temp.name = "Julien";
    temp.discordUsername = "Julien#8652";
    collaboratorArray->push_back(temp);

    temp.name = "Bronson";
    temp.discordUsername = "Bronson#5292";
    collaboratorArray->push_back(temp);

    temp.name = "Andrew";
    temp.discordUsername = "miranda#4988";
    collaboratorArray->push_back(temp);

    this->loadingScreen = new LoadingScreen();
    this->mainMenuScreen = new MainMenuScreen();
    this->loginScreen = new LoginScreen();
    this->registerScreen = new RegisterScreen();
    this->creditsScreen = new CreditsScreen();
    this->inGameScreen = new InGameScreen();

    this->currentGameState = new CurrentGameState();

    *currentGameState = LOADING_SCREEN;

    this->loadingCounter = 0;

    this->registerSuccessCounter = 0;
    this->isRegisterSuccess = false;

};

/*************************************************
 * Destructor Constructor
 ************************************************/ 
Game::~Game(){
    // n/a
};

/*************************************************
 * run() - Runs the game from current state
 ************************************************/
bool Game::run(CurrentGameState *gameState) {
    switch (*gameState){
        case LOADING_SCREEN:

            /************************************/
            if(loadingCounter < 150) {
                *gameState = LOADING_SCREEN;
                loadingCounter++;
            } else {
                *gameState = MAIN_MENU_SCREEN;
            }
            /************************************/

            /************************************/
            switch (*gameState){
                case LOADING_SCREEN:
                    loadingScreen->DrawScreen();
                    break;
                case MAIN_MENU_SCREEN:
                    mainMenuScreen->DrawScreen();
                    loadingCounter = 0;
                    break;
                default:
                    loadingScreen->DrawScreen();
                    std::cout << "Something went wrong in loading screen CASE Statement in Game::run()" << std::endl;
                    break;
            };
            /************************************/

            return true;
            break;
        case MAIN_MENU_SCREEN:

            /************************************************************************************************************************************************************************/
            if (GetMouseX() >= this->mainMenuScreen->getLoginButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getLoginButtonPositionX() + this->mainMenuScreen->getLoginButtonWidth() &&
                GetMouseY() >= this->mainMenuScreen->getLoginButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getLoginButtonPositionY() + this->mainMenuScreen->getLoginButtonHeight()) {
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    *gameState = LOGIN_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            } else if (GetMouseX() >= this->mainMenuScreen->getRegisterButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getRegisterButtonPositionX() + this->mainMenuScreen->getRegisterButtonWidth() &&
                     GetMouseY() >= this->mainMenuScreen->getRegisterButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getRegisterButtonPositionY() + this->mainMenuScreen->getRegisterButtonHeight()) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    *gameState = REGISTER_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            } else if (GetMouseX() >= this->mainMenuScreen->getCreditsButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getCreditsButtonPositionX() + this->mainMenuScreen->getCreditsButtonWidth() &&
                GetMouseY() >= this->mainMenuScreen->getCreditsButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getCreditsButtonPositionY() + this->mainMenuScreen->getCreditsButtonHeight()) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    *gameState = CREDITS_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            } else if (GetMouseX() >= this->mainMenuScreen->getExitButtonPositionX() && GetMouseX() <= this->mainMenuScreen->getExitButtonPositionX() + this->mainMenuScreen->getExitButtonWidth() &&
                GetMouseY() >= this->mainMenuScreen->getExitButtonPositionY() && GetMouseY() <= this->mainMenuScreen->getExitButtonPositionY() + this->mainMenuScreen->getExitButtonHeight()) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    *gameState = EXIT_SCREEN;
                } else {
                    *gameState = MAIN_MENU_SCREEN;
                }
            } else {
                *gameState = MAIN_MENU_SCREEN;
            }
            /*************************************************************************************************************************************************************************/

            /******************************************/
            if(*gameState == MAIN_MENU_SCREEN) {
                mainMenuScreen->DrawScreen();
            } else if(*gameState == LOGIN_SCREEN) {
                loginScreen->DrawScreen();
            } else if(*gameState == REGISTER_SCREEN) {
                registerScreen->DrawScreen();
            } else if(*gameState == CREDITS_SCREEN) {
                creditsScreen->DrawScreen();
            } else if(*gameState == EXIT_SCREEN) {
                return false;
            }
            /*******************************************/

            return true;
            break;
        case LOGIN_SCREEN:

            /********************************************************************************************************************************************************/
            if (GetMouseX() >= this->loginScreen->getBackNowButtonX() && GetMouseX() <= this->loginScreen->getBackNowButtonX() + this->loginScreen->getBackNowButtonWidth() &&
                GetMouseY() >= this->loginScreen->getBackNowButtonY() && GetMouseY() <= this->loginScreen->getBackNowButtonY() + this->loginScreen->getBackNowButtonHeight()) {
                
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    *gameState = MAIN_MENU_SCREEN;
                } else {
                    *gameState = LOGIN_SCREEN;
                }

            } else if(GetMouseX() >= this->loginScreen->getLoginNowButtonX() && GetMouseX() <= this->loginScreen->getLoginNowButtonX() + this->loginScreen->getLoginNowButtonWidth() &&
                GetMouseY() >= this->loginScreen->getLoginNowButtonY() && GetMouseY() <= this->loginScreen->getLoginNowButtonY() + this->loginScreen->getLoginNowButtonHeight()) {
                    
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        *gameState = GAME_SCREEN;
                    } else {
                        *gameState = LOGIN_SCREEN;
                    }
            } else {
                *gameState = LOGIN_SCREEN;
            }
            /***********************************************************************************************************************************************************/

            /***********************************************/
            if(*gameState == LOGIN_SCREEN) {
                loginScreen->DrawScreen();
            } else if (*gameState == MAIN_MENU_SCREEN) {
                mainMenuScreen->DrawScreen();
            } else if(*gameState == GAME_SCREEN) {
                inGameScreen->DrawScreen();
            } else {
                loginScreen->DrawScreen();
            }
            /**********************************************/

            /**********************************************************************************************************/
            /***************************** IS ENTRY FROM REGISTRATION SCREEN??? ***************************************/
            /**********************************************************************************************************/
            if(isRegisterSuccess){
                if(isRegisterSuccess && registerSuccessCounter <= 150){
                    DrawText("Register Success!", 10, 10, 24, BLACK);
                    registerSuccessCounter++;
                } else {
                    isRegisterSuccess = false;
                    registerSuccessCounter = 0;
                }
            }
            /**********************************************************************************************************/
            /**********************************************************************************************************/
            /**********************************************************************************************************/

            return true;
            break;
        case REGISTER_SCREEN:

            /********************************************************************************************************************************************************/
            if (GetMouseX() >= this->registerScreen->getBackButtonX() && GetMouseX() <= this->registerScreen->getBackButtonX() + this->registerScreen->getBackButtonWidth() &&
                GetMouseY() >= this->registerScreen->getBackButtonY() && GetMouseY() <= this->registerScreen->getBackButtonY() + this->registerScreen->getBackButtonHeight()) {
                
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    *gameState = MAIN_MENU_SCREEN;
                } else {
                    *gameState = REGISTER_SCREEN;
                }

            } else if(GetMouseX() >= this->registerScreen->getRegisterButtonX() && GetMouseX() <= this->registerScreen->getRegisterButtonX() + this->registerScreen->getRegisterButtonWidth() &&
                GetMouseY() >= this->registerScreen->getRegisterButtonY() && GetMouseY() <= this->registerScreen->getRegisterButtonY() + this->registerScreen->getRegisterButtonHeight()) {
                    
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        *gameState = LOGIN_SCREEN;
                    } else {
                        *gameState = REGISTER_SCREEN;
                    }
            } else {
                *gameState = REGISTER_SCREEN;
            }
            /***********************************************************************************************************************************************************/

            /***********************************************/
            if(*gameState == REGISTER_SCREEN) {
                this->registerScreen->DrawScreen();
            } else if (*gameState == MAIN_MENU_SCREEN) {
                this->mainMenuScreen->DrawScreen();
            } else if(*gameState == LOGIN_SCREEN) {
                this->loginScreen->DrawScreen();
                this->isRegisterSuccess = true;
            } else {
                this->registerScreen->DrawScreen();
            }
            /**********************************************/

            return true;
            break;
        case CREDITS_SCREEN:
            this->creditsScreen->DrawScreen();
            return true;
            break;
        case GAME_SCREEN:
            this->inGameScreen->DrawScreen();
            return true;
            break;
        case EXIT_SCREEN:
            return false;
            break;
        default:
            std::cout << "ERROR: Invalid Game State" << std::endl;
            break;
    }
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printVersion() {
    std::cout << "Version: " << version << std::endl;
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printHelp() {
    std::cout << "Help: " << help << std::endl;
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printUsersOnline() {
    std::cout << "Users Online: " << usersOnline << std::endl;
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printLicense() {
    std::cout << "License: " << license << std::endl;
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printContributors() {
    std::cout << "All Contributors:\n";
    std::cout << "--------------------------------\n";
    for(int i = 0; i <= collaboratorArray->size() - 1; i++) {
        std::cout << collaboratorArray->at(i).name << " || Discord Username: " << collaboratorArray->at(i).discordUsername << std::endl;
    }
    return;
};


/************************************************/
/*************************************************
 *             Mutator Functions                 *
 *************************************************/
/*************************************************/


/************************************************************
* setVersion() - Sets the version of the game
************************************************************/
void Game::setVersion(string version) {
    this->version = version;
};

/************************************************************
* setHelp() - Sets the help string with the help commands
************************************************************/
void Game::setHelp(string help) {
    this->help = help;
};

/************************************************************
* TODO: Finish documentation
************************************************************/
void Game::setUsersOnline(string usersOnline) {
    this->usersOnline = getUsersOnline(); // Eventually this will be a vector of users being appended during game play.
};

/************************************************************
* TODO: Finish documentation
************************************************************/
void Game::setLicense(string license) {
    this->license = license;
};

/************************************************************
* TODO: Finish documentation
************************************************************/
void Game::setContributors(Contributor newContributor) {
     collaboratorArray->push_back(newContributor);
};


/************************************************/
/*************************************************
 *              Accessor Functions               *
 *************************************************/
 /************************************************/


/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
string Game::getVersion(){
    return version;
};

/************************************************************
* getHelp() - Returns the help string
************************************************************/
string Game::getHelp() {
    return help; // TODO: Change this to a array/vector of help commands.
};

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
int Game::getUsersOnline(){
    if(getUsersOnline() == 0) {
        std::cout << "No users online." << std::endl;
        return 0;
    } else {
        std::cout << "Users Online: " << usersOnline << std::endl;
        return 1;
    }
};

/************************************************************
* getLicense() - Returns the license string
************************************************************/
string Game::getLicense() {
    return getLicense();
};

/************************************************************
* getContributors() - Returns the contributors array
************************************************************/
int Game::getNumberOfContributors() {
    std::cout << collaboratorArray->size() << std::endl; // Debugging
    return collaboratorArray->size();
};