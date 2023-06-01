/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef Game_hpp
#define Game_hpp

#define MAX_CONTRIBUTORS 7


//System Libraries
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

// User Libraries
#include "Screen/Screen.hpp"
#include "Screen/LoadingScreen/LoadingScreen.hpp"
#include "Screen/MainMenuScreen/MainMenuScreen.hpp"
#include "Screen/LoginScreen/LoginScreen.hpp"
#include "Screen/RegisterScreen/RegisterScreen.hpp"
#include "Screen/CreditsScreen/CreditsScreen.hpp"
#include "Screen/InGameScreen/InGameScreen.hpp"

// External Libraries
#include <raylib.h>
// #include <curl/curl.h>
// #include <nlohmann/json.hpp>
// using json = nlohmann::json;

/*********************************************/
/*            Contributor Struct             */
/*********************************************/
struct Contributor {
    string name;
    string discordUsername;
};

enum CurrentGameState{
    LOADING_SCREEN,
    MAIN_MENU_SCREEN,
    LOGIN_SCREEN,
    REGISTER_SCREEN,
    CREDITS_SCREEN,
    GAME_SCREEN,
    EXIT_SCREEN
};

/********************************************
 * Game Class
 *******************************************/
class Game {
    
    public:
        Game();                                 // Default Constructor 
        ~Game();                                // Destructor
        bool run(CurrentGameState *gameState);  // Runs the game from current state

        void printVersion();      // Shows the version
        void printHelp();         // Gives help
        void printUsersOnline();  // Prints users online
        void printLicense();      // Prints the license
        void printContributors(); // Shows the contributor

        // Setters
        void setVersion(string version);
        void setHelp(string help);
        void setUsersOnline(string usersOnline);
        void setLicense(string license);
        void setContributors(Contributor newContributor);

        // Getters
        string getVersion();
        string getHelp();
        int  getUsersOnline();
        string getLicense();
        int getNumberOfContributors();

    private:
        string license;
        string version;
        string help;
        int usersOnline;
        vector<Contributor> collaboratorArray[MAX_CONTRIBUTORS];
        LoadingScreen *loadingScreen;
        MainMenuScreen *mainMenuScreen;
        LoginScreen *loginScreen;
        RegisterScreen *registerScreen;
        CreditsScreen *creditsScreen;
        InGameScreen *inGameScreen;
        CurrentGameState *currentGameState;
        int loadingCounter;
};

#endif /* Game_hpp */