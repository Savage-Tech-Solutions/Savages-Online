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

// External Libraries
// ---included in Screen.hpp---

class MainMenuScreen : protected Screen {

    public:
        MainMenuScreen();
        ~MainMenuScreen();
        void DrawScreen();
        void MainMenuLogic();
        void MainMenuDisplay();

    protected:
        // N/A

    private:
        // N/A

};


#endif /* MainMenuScreen_hpp */