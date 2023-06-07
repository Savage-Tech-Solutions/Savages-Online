/*************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#include "InGameScreen.hpp"

/*******************************************************
 * Default Constructor
*******************************************************/
InGameScreen::InGameScreen() {
    Texture2D backgroundTexture = LoadTexture("../resources/GUI/backgrounds/InGameScreen/in_game_background.png");
    this->setBackgroundTexture(backgroundTexture);
};

/*******************************************************
 * Destructor
*******************************************************/
InGameScreen::~InGameScreen() {
  
};

/*******************************************************
 * DrawScreen() function will draw the credits screen
 ******************************************************/
void InGameScreen::DrawScreen() {
    InGameDisplay();
    InGameLogic();
};

/*******************************************************
 * DrawFrontMap() function will draw the front map, so
 * the player can NOT be seen. Walking behind trees,
 * houses, etc.
 ******************************************************/
void InGameScreen::DrawFrontMap() {
     Texture2D backgroundTexture = LoadTexture("../resources/Maps/Main-Town/v1/Main-Town.png");
    this->frontMapTexture = backgroundTexture;
    DrawTexture(this->frontMapTexture, 0, 0, WHITE);
};

/*******************************************************
 * DrawBackMap() function will draw the back map, so
 * the player can be seen. Walking in front of trees,
 * houses, ground textures, etc.
 ******************************************************/
void InGameScreen::DrawBackMap() {
    // TODO: Implement this function
};

/*******************************************************
 * InGameLogic() function will handle the logic for
 * this specific class.
 ******************************************************/
void InGameScreen::InGameLogic() {
    // TODO: Implement this function
};

/*******************************************************
 * InGameDisplay() function will display the credits
 * to the screen by the DrawScreen() function.
 ******************************************************/
void InGameScreen::InGameDisplay() {
    this->DrawBackMap();
    
    this->DrawFrontMap();
    DrawTexture(this->getBackgroundTexture(), 0, 0, WHITE);
};