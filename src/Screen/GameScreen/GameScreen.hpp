#ifndef GameScreen_hpp
#define GameScreen_hpp

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"

// External Libraries
#include "raylib.h"

class GameScreen : protected Screen {

    public:
        GameScreen();
        ~GameScreen();
        void DrawScreen();
        void GameLogic();
        void GameDisplay();

    protected:
        // N/A

    private:
        // World world;


};



#endif /* GameScreen_hpp */