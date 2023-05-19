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
    setVersion("0.0.1"); // TODO: Change this to a version number
    setHelp("help"); // TODO: Change this to a vector of help commands
    setUsersOnline("usersOnline");  // TODO: Change this to a vector of users
    setLicense("license"); // TODO: Change this to a license
    setContributors("contributors"); // TODO: Change this to a vector of contributors
}

/*************************************************
 * Destructor Constructor
 ************************************************/ 
Game::~Game() {
    // Nothing to do here yet
}

void Game::run() {
    DrawText("Savages-Online Client GUI", 575, 300, 20, WHITE);
}

void Game::printVersion() {
    cout << "Version: " << version << endl;
}

void Game::printHelp() {
    cout << "Help: " << help << endl;
}

void Game::printUsersOnline() {
    cout << "Users Online: " << usersOnline << endl;
}

void Game::printLicense() {
    cout << "License: " << license << endl;
}

void Game::printContributors() {
    cout << "Contributors: " << contributors << endl;
}

/*************************************************
 * Mutator Functions
 *************************************************/

void Game::setVersion(string version) {
    this->version = version;
}

void Game::setHelp(string help) {
    this->help = help;
}

void Game::setUsersOnline(string usersOnline) {
    this->usersOnline = usersOnline;
}

void Game::setLicense(string license) {
    this->license = license;
}

void Game::setContributors(string contributors) {
    this->contributors = contributors;
}

/*************************************************
 * Accessor Functions
 *************************************************/

string Game::getVersion() const {
    return version;
}

string Game::getHelp() const {
    return help;
}

string Game::getUsersOnline() const {
    return usersOnline;
}

string Game::getLicense() const {
    return license;
}

string Game::getContributors() const {
    return contributors;
}
