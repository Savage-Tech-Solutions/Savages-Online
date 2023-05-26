/*************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef CreditsScreen_hpp
#define CreditsScreen_hpp

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"

// External Libraries
// ---included in Screen.hpp---

struct TeamMembers {
    std::string name;
    std::string role;
    std::string email;
    std::string github;
    TeamMembers *next;
};

class CreditsScreen : protected Screen {

public:
    CreditsScreen();
    ~CreditsScreen();
    void DrawScreen(); // Implementing 1 of 3 virtual functions from Screen.hpp

    // CreditsScreen Function Prototypes
    void CreditsLogic();
    void CreditsDisplay();

    protected:
        // N/A

    private:
        TeamMembers *head; // TODO: Create a linked list of team members

};

#endif /* CreditsScreen_hpp */