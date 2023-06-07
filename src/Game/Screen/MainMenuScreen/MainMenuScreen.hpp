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
#include <vector>
using std::string;
using std::vector;

// User Libraries
#include "../Screen.hpp"
#include "../../Component/Button/Button.hpp"

// External Libraries
// ---included in Screen.hpp---

class MainMenuScreen : protected Screen {

    public:
        MainMenuScreen();
        ~MainMenuScreen();
        void DrawScreen();
        void MainMenuLogic();    // TODO: Finish Implementation
        void MainMenuDisplay();  // TODO: Finish Implementation

        // New Functions --GETTERS--
        int getLoginButtonPositionX();
        int getLoginButtonPositionY();
        int getLoginButtonWidth();
        int getLoginButtonHeight();

        int getRegisterButtonPositionX();
        int getRegisterButtonPositionY();
        int getRegisterButtonWidth();
        int getRegisterButtonHeight();

        int getCreditsButtonPositionX();
        int getCreditsButtonPositionY();
        int getCreditsButtonWidth();
        int getCreditsButtonHeight();

        int getExitButtonPositionX();
        int getExitButtonPositionY();
        int getExitButtonWidth();
        int getExitButtonHeight();

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