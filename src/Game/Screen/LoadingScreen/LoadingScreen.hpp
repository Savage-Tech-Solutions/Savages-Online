/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef LoadingScreen_hpp
#define LoadingScreen_hpp

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"

// External Libraries
// ---included in screen.hpp---

class LoadingScreen : protected Screen {

    public:
        LoadingScreen();
        ~LoadingScreen();
        void DrawScreen();
        void LoadingScreenLogic();    // TODO: Finish Implementation
        void LoadingScreenDisplay();  // TODO: Finish Implementation

            //protected :
            // N/A

            //private:
            // N/A
};

#endif /* LoadingScreen_hpp */