/*************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "InGameScreen.hpp"
#include <iostream>
/*******************************************************
 * Default Constructor
*******************************************************/
InGameScreen::InGameScreen() {    

};

/*******************************************************
 * Destructor
*******************************************************/
InGameScreen::~InGameScreen() {
}

/*******************************************************
 * DrawScreen() function will draw the credits screen
 ******************************************************/
void InGameScreen::DrawScreen() {
    std::cout << "DrawScreen() function being called..." << std::endl;
};

/*******************************************************
 * DrawFrontMap() function will draw the front map, so
 * the player can NOT be seen. Walking behind trees,
 * houses, etc.
 ******************************************************/
void InGameScreen::DrawFrontMap() {
    std::cout << "DrawFrontMap() function being called..." << std::endl;
};

/*******************************************************
 * DrawBackMap() function will draw the back map, so
 * the player can be seen. Walking in front of trees,
 * houses, ground textures, etc.
 ******************************************************/
void InGameScreen::DrawBackMap() {
    std::cout << "DrawBackMap() function being called..." << std::endl;
};

/*******************************************************
 * InGameLogic() function will handle the logic for
 * this specific class.
 ******************************************************/
void InGameScreen::InGameLogic() {
    std::cout << "InGameLogic() function being called..." << std::endl;
};

/*******************************************************
 * InGameDisplay() function will display the credits
 * to the screen by the DrawScreen() function.
 ******************************************************/
void InGameScreen::InGameDisplay() {
    std::cout << "InGameDisplay() function being called..." << std::endl;
};

