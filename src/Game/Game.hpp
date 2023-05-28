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
#include "Screen/InGameScreen/InGameScreen.hpp"
#include "Screen/CreditsScreen/CreditsScreen.hpp"
#include "Screen/MainMenuScreen/MainMenuScreen.hpp"
#include "Screen/LoginScreen/LoginScreen.hpp"
#include "Screen/RegisterScreen/RegisterScreen.hpp"
#include "Screen/Screen.hpp"
#include "Screen/MainMenuScreen/MainMenuScreen.hpp"
#include "Screen/InGameScreen/InGameScreen.hpp"

// External Libraries
#include <raylib.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/*********************************************/
/*            Contributor Struct             */
/*********************************************/
struct Contributor {
    string name;
    string discordUsername;
};

enum GUI_STATE {
    MAIN_MENU,      // 0
    PLAYING_GAME,   // 1
    EXITING_GAME    // 2
};

/********************************************
 * Game Class
 *******************************************/
class Game {
    
    public:
        Game();                   // Default Constructor 
        ~Game();                  // Destructor
        void run();               // Will run the game and/or stop the game.
        void printVersion();      // Shows the version
        void printHelp();         // Gives help
        void printUsersOnline();  // Prints users online
        void printLicense();      // Prints the license
        void printContributors(); // Shows the contributor
        

        // NEW - ADDED:/ 05/24/23 @ 3:45am
        int StartPlayingGame(GUI_STATE gui);
        int StopPlayingGame(GUI_STATE gui);


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
        GUI_STATE guiState;
        MainMenuScreen *mainMenuScreen;
        InGameScreen *inGameScreen;
};

#endif /* Game_hpp */