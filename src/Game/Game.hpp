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
#include <array>
#include <vector>
using namespace std;

// User Libraries
// N/A --Soon to be added--

// External Libraries
#include <raylib.h>
#include <nlohmann/json.hpp>


struct Contributor {
    string name;
    string discordUsername;
};          

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
        bool StartPlayingGame(/*   Parameters need to be added     */);  // TODO:  Needs to be implemented...
        bool StopPlayingGame(/*   Parameters need to be added     */);   // TODO:  Needs to be implemented...


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
};

#endif /* Game_hpp */