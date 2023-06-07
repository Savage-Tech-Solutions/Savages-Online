/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#include "LoadingScreen.hpp"

/**********************************************************
 * 
**********************************************************/
LoadingScreen::LoadingScreen() /*:anim_counter(0) */{
    Texture2D backgroundTexture = LoadTexture("../resources/GUI/backgrounds/LoadingScreen/loading_screen_background.png");
    this->setBackgroundTexture(backgroundTexture);
};

/**********************************************************
 *
 **********************************************************/
LoadingScreen::~LoadingScreen() {
    // N/A
};

/**********************************************************
 *
 **********************************************************/
void LoadingScreen::DrawScreen() {
    DrawTexture(this->getBackgroundTexture(), this->getDrawPositionX(), this->getDrawPositionY(), WHITE);
};

/**********************************************************
 *
 **********************************************************/
void LoadingScreen::LoadingScreenLogic() {
    // N/A
};

/**********************************************************
 *
 **********************************************************/
void LoadingScreen::LoadingScreenDisplay() {
    // N/A
};

