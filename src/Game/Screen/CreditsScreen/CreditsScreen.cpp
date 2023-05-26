/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "CreditsScreen.hpp"

/*******************************************************
 * Default Constructor
*******************************************************/
CreditsScreen::CreditsScreen() {
    this->head = NULL;
};

/*******************************************************
 * Destructor Constructor
*******************************************************/
CreditsScreen::~CreditsScreen() {
    delete this->head;
};

/*******************************************************
 * DrawScreen() function will draw the credits screen
*******************************************************/
void CreditsScreen::DrawScreen() {
    std::cout << "DrawScreen() function being called..." << std::endl;
};

/*******************************************************
 * CreditsLogic() function will handle the logic for
 * this specific class.
*******************************************************/
void CreditsScreen::CreditsLogic() {
    std::cout << "CreditsLogic() function being called..." << std::endl;
};

/*******************************************************
 * CreditsDisplay() function will display the credits
 * to the screen by the DrawScreen() function.
*******************************************************/
void CreditsScreen::CreditsDisplay() {
    std::cout << "CreditsDisplay() function being called..." << std::endl;
};