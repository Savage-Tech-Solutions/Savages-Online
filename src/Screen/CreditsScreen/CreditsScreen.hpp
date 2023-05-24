#ifndef CreditsScreen_hpp
#define CreditsScreen_hpp

//System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"
//#include "../../ReusableComponents/Button/Button.hpp"

// External Libraries
#include "raylib.h"

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
    void DrawScreen();
    void CreditsLogic();
    void CreditsDisplay();

    protected:
        // N/A

    private:
        TeamMembers *head; // TODO: Create a linked list of team members
     // Button buttons;

};

#endif /* CreditsScreen_hpp */