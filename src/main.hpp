/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef main_hpp
#define main_hpp

// System Libraries
#include <unistd.h>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using std::strchr;

// User Libraries
#include "../Game/Game.hpp"
#include "../Game/Screen/MainMenuScreen/MainMenuScreen.hpp"
#include "../Game/Screen/LoadingScreen/LoadingScreen.hpp"

// External Libraries
#include "raylib.h"

enum GameStates {
    LOADING_SCREEN,
    MAIN_MENU_SCREEN,
    GAME_SCREEN,
    EXIT_SCREEN
};



#endif /* main_hpp */