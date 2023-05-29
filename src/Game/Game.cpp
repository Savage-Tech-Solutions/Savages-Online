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
    temp.discordUsername = "bberwald0#7777";
    collaboratorArray->push_back(temp);
    
    temp.name = "Julien";
    temp.discordUsername = "Julien#8652";
    collaboratorArray->push_back(temp);

    temp.name = "flaschenholz";
    temp.discordUsername = "flaschenholz#1893";
    collaboratorArray->push_back(temp);

    temp.name = "Bronson";
    temp.discordUsername = "Bronson#5292";
    collaboratorArray->push_back(temp);

    temp.name = "Andrew";
    temp.discordUsername = "miranda#4988";
    collaboratorArray->push_back(temp);

    temp.name = "NudistRahip";
    temp.discordUsername = "NudistRahip#3651";
    collaboratorArray->push_back(temp);

    temp.name = "Hoya";
    temp.discordUsername = "hoya#3909";
    collaboratorArray->push_back(temp);

    this->loadingScreen = new LoadingScreen();
    this->mainMenuScreen = new MainMenuScreen();
    this->inGameScreen = new InGameScreen();

    this->currentGameState = new CurrentGameState();

    *currentGameState = LOADING_SCREEN;

    this->loadingCounter = 0;

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
            if(loadingCounter < 150) {
                loadingCounter++;
            } else {
                *gameState = MAIN_MENU_SCREEN;
            }
            loadingScreen->DrawScreen();
            return true;
            break;
        case MAIN_MENU_SCREEN:
            mainMenuScreen->DrawScreen();
            return true;
            break;
        case GAME_SCREEN:
            inGameScreen->DrawScreen();
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