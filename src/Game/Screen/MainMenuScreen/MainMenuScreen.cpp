/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "MainMenuScreen.hpp"

/*******************************************************
 * Default Constructor
*******************************************************/
MainMenuScreen::MainMenuScreen() {
    Texture2D backgroundTexture = LoadTexture("../resources/GUI/backgrounds/MainMenuScreen/main_menu_screen_background.png");
    this->setBackgroundTexture(backgroundTexture);
};

/*******************************************************
 * Destructor
*******************************************************/
MainMenuScreen::~MainMenuScreen() {
    // N/A
};

/*******************************************************
 * DrawScreen() function will draw the main menu screen
 * using the pure virtual function from the Screen class.
*******************************************************/
void MainMenuScreen::DrawScreen() {
    DrawTexture(this->getBackgroundTexture(), this->getDrawPositionX(), this->getDrawPositionY(), WHITE);
};

/*******************************************************
 * MainMenuLogic() function will handle the logic for
 * the main menu.
*******************************************************/
void MainMenuScreen::MainMenuLogic() {
    // N/A
};

/*******************************************************
 * MainMenuDisplay() function will display the main menu
*******************************************************/
void MainMenuScreen::MainMenuDisplay() {
    // N/A
};