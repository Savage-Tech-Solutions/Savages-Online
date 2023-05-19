#ifndef CreditsScreen_hpp
#define CreditsScreen_hpp

//System Libraries
#include <iostream>
#include <string>
using namespace std;

// User Libraries
#include "../Screen.hpp"
//#include "../../ReusableComponents/Button/Button.hpp"

// External Libraries
#include "raylib.h"

struct TeamMembers {
    string name;
    string role;
    string email;
    string github;
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