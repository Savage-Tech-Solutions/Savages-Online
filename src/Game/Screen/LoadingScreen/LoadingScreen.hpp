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
        void LoadingScreenLogic();
        void LoadingScreenDisplay();

        void setBackgroundTexture(Texture2D texture);

            protected :
            // N/A

            private : Texture2D backgroundTexture; int anim_counter;
};




#endif /* LoadingScreen_hpp */