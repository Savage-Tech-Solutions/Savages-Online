/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include "raylib.h"
#include <iostream>
#include <string.h>
using namespace std;

// Function Prototypes

class Game {
    public:
        Game();                   // Default Constructor
        ~Game();                  // Destructor
        void run();               // Will run the game
        void printVersion();      // Shows the version
        void printHelp();         // Gives help
        void printUsersOnline();  // Prints users online
        void printLicense();      // Prints the license
        void printContributors(); // Shows the contributors

        // Setters
        void setVersion(string version);
        void setHelp(string help);
        void setUsersOnline(string usersOnline);
        void setLicense(string license);
        void setContributors(string contributors);

        // Getters
        string getVersion() const;
        string getHelp() const;
        string getUsersOnline() const;
        string getLicense() const;
        string getContributors() const;

    private:
        string version;
        string help;
        string usersOnline;
        string license;
        string contributors;
};


#endif /* Game_hpp */