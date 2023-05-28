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
        int anim_counter;
        LoadingScreen();
        ~LoadingScreen();
        void DrawScreen();
        void LoadingScreenLogic();
        void LoadingScreenDisplay();

            protected :
            // N/A

            //private : Texture2D backgroundTexture; 
};




#endif /* LoadingScreen_hpp */