/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "Game.hpp"

     /*************************************************
     * Default Constructor
     ************************************************/
Game::Game() {
    version = ("0.0.1");
    help = "Type $help for help answering questions...";
    usersOnline = 0;
    license = "GNU GENERAL PUBLIC LICENSE";

    Contributor temp;
    temp.name = "Bryce";
    temp.discordUsername = "bberwald0#....";
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
};

/*************************************************
 * Destructor Constructor
 ************************************************/ 
Game::~Game(){
    // n/a
}

void Game::run() {
    DrawText("Savages-Online Client GUI", 575, 300, 20, WHITE); // Testing
}

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printVersion() {
    std::cout << "Version: " << version << std::endl;
}

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printHelp() {
    std::cout << "Help: " << help << std::endl;
}

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printUsersOnline() {
    std::cout << "Users Online: " << usersOnline << std::endl;
}

/************************************************************
* getUsersOnline() - Returns the number of users online
************************************************************/
void Game::printLicense() {
    std::cout << "License: " << license << std::endl;
}

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
}



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
}

/************************************************************
* setHelp() - Sets the help string with the help commands
************************************************************/
void Game::setHelp(string help) {
    this->help = help;
}

/************************************************************
* 
************************************************************/
void Game::setUsersOnline(string usersOnline) {
    this->usersOnline = getUsersOnline(); // Eventually this will be a vector of users being appended during game play.
}

/************************************************************
* 
************************************************************/
void Game::setLicense(string license) {
    this->license = license;
}

/************************************************************
* 
************************************************************/
void Game::setContributors(Contributor newContributor) {
     collaboratorArray->push_back(newContributor);
}


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
}

/************************************************************
* getHelp() - Returns the help string
************************************************************/
string Game::getHelp() {
    return help; // TODO: Change this to a array/vector of help commands.
}

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
}

/************************************************************
* getLicense() - Returns the license string
************************************************************/
string Game::getLicense() {
    return getLicense();
}

/************************************************************
* getContributors() - Returns the contributors array
************************************************************/
int Game::getNumberOfContributors() {
    std::cout << collaboratorArray->size() << std::endl; // Debugging
    return collaboratorArray->size();
}