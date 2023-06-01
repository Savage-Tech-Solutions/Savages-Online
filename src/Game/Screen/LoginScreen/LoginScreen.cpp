/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "LoginScreen.hpp"

/*******************************************************
 * Default Constructor
 *******************************************************/
LoginScreen::LoginScreen() {
    this->loginNowButton = new Button();
    this->loginNowButton->setDrawPositionX(300);
    this->loginNowButton->setDrawPositionY(500);
    this->loginNowButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->loginNowButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->loginNowButton->setButtonWidth(this->loginNowButton->getUnpressedTexture().width);
    this->loginNowButton->setButtonHeight(this->loginNowButton->getUnpressedTexture().height);
    this->loginNowButton->setCurrentTexture(this->loginNowButton->getUnpressedTexture());

    this->registerNowButton = new Button();
    this->registerNowButton->setDrawPositionX(700);
    this->registerNowButton->setDrawPositionY(500);
    this->registerNowButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->registerNowButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->registerNowButton->setButtonWidth(this->registerNowButton->getUnpressedTexture().width);
    this->registerNowButton->setButtonHeight(this->registerNowButton->getUnpressedTexture().height);
    this->registerNowButton->setCurrentTexture(this->registerNowButton->getUnpressedTexture());

    // DrawRectangle(375, 200, 500, 40, WHITE);
    // DrawRectangle(375, 300, 500, 40, WHITE);

    this->loginNowX = 375;
    this->loginNowY = 200;
    this->loginNowWidth = 500;
    this->loginNowHeight = 40;

    this->registerNowX = 375;
    this->registerNowY = 300;
    this->registerNowWidth = 500;
    this->registerNowHeight = 40;
};

/*******************************************************
 * Destructor
 *******************************************************/
LoginScreen::~LoginScreen() {
    delete this->loginNowButton;
    delete this->registerNowButton;
};

/*******************************************************
 * DrawScreen() function will draw the login screen
 *******************************************************/
void LoginScreen::DrawScreen() {
    // ClearBackground(BLACK); -- Using for debugging purposes.
    LoginDisplay() ;
    LoginLogic();
   
};

/*******************************************************
 * LoginLogic() function will handle the logic for
 * the login screen.
 *******************************************************/
void LoginScreen::LoginLogic() {

};

/*******************************************************
 * LoginDisplay() function will display the login
 * screen to be drawn on the screen by the DrawScreen()
 * function.
 *******************************************************/
void LoginScreen::LoginDisplay() {
    DrawTexture(this->getBackgroundTexture(), 0, 0, WHITE);
    DrawTexture(this->loginNowButton->getCurrentTexture(), this->loginNowButton->getDrawPositionX(), this->loginNowButton->getDrawPositionY(), WHITE);
    DrawTexture(this->registerNowButton->getCurrentTexture(), this->registerNowButton->getDrawPositionX(), this->registerNowButton->getDrawPositionY(), WHITE);

    DrawRectangle(this->loginNowX, this->loginNowY, this->loginNowWidth, this->loginNowHeight, WHITE);
    DrawRectangle(this->registerNowX, this->registerNowY, this->registerNowWidth, this->registerNowHeight, WHITE);

    DrawRectangleLines(375, 200, 500, 40, BLACK);
    DrawRectangleLines(374, 199, 500, 40, BLACK);
    DrawRectangleLines(373, 198, 500, 40, BLACK);
    DrawRectangleLines(372, 197, 500, 40, BLACK);

    DrawRectangleLines(375, 300, 500, 40, BLACK);
    DrawRectangleLines(374, 299, 500, 40, BLACK);
    DrawRectangleLines(373, 298, 500, 40, BLACK);
    DrawRectangleLines(372, 297, 500, 40, BLACK);


    DrawRectangleLines(375, 300, 500, 40, BLACK);


};