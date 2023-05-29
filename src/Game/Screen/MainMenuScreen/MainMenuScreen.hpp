/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef MainMenuScreen_hpp
#define MainMenuScreen_hpp

// System Libraries
#include <iostream>
#include <iomanip>
#include <string>

// User Libraries
#include "../Screen.hpp"
#include "../ButtonComponent/Button.hpp"

// External Libraries
// ---included in Screen.hpp---

class MainMenuScreen : protected Screen {

    public:
        MainMenuScreen();
        ~MainMenuScreen();
        void DrawScreen();
        void MainMenuLogic();    // TODO: Finish Implementation
        void MainMenuDisplay();  // TODO: Finish Implementation

    protected:
        // N/A

    private:
        // N/A
        Button *loginButton;
        Button *registerButton;
        Button *creditsButton;
        Button *exitButton;

};


#endif /* MainMenuScreen_hpp */