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

    this->backNowButton = new Button();
    this->backNowButton->setDrawPositionX(700);
    this->backNowButton->setDrawPositionY(500);
    this->backNowButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->backNowButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->backNowButton->setButtonWidth(this->backNowButton->getUnpressedTexture().width);
    this->backNowButton->setButtonHeight(this->backNowButton->getUnpressedTexture().height);
    this->backNowButton->setCurrentTexture(this->backNowButton->getUnpressedTexture());

    this->loginTextFieldX = 375;
    this->loginTextFieldY = 200;
    this->loginTextFieldWidth = 500;
    this->loginTextFieldHeight = 40;

    this->loginTextFieldRec = {375, 200, 500, 40};  // Type Rectangle

    this->passwordTextFieldX = 375;
    this->passwordTextFieldY = 300;
    this->passwordTextFieldWidth = 500;
    this->passwordTextFieldHeight = 40;

    this->passwordTextFieldRec = {375, 300, 500, 40}; // Type: Rectangle
};

/*******************************************************
 * Destructor
 *******************************************************/
LoginScreen::~LoginScreen() {
    delete this->loginNowButton;
    delete this->backNowButton;

};

/*******************************************************
 * DrawScreen() function will draw the login screen
 *******************************************************/
void LoginScreen::DrawScreen() {
    LoginDisplay() ;
    LoginLogic();
};

/*******************************************************
 * LoginLogic() function will handle the logic for
 * the login screen.
 *******************************************************/
void LoginScreen::LoginLogic() {
    if(GetMouseX() >= this->loginNowButton->getDrawPositionX() && GetMouseX() <= this->loginNowButton->getDrawPositionX() + this->loginNowButton->getButtonWidth() && GetMouseY() >= this->loginNowButton->getDrawPositionY() && GetMouseY() <= this->loginNowButton->getDrawPositionY() + this->loginNowButton->getButtonHeight()) {
        this->loginNowButton->setCurrentTexture(this->loginNowButton->getPressedTexture());
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // TODO: Add logic here (What to do next...)
        }
    } else {
        this->loginNowButton->setCurrentTexture(this->loginNowButton->getUnpressedTexture());
        // TODO: Add logic here
    }

    // TODO: Add logic here
    

    if(GetMouseX() >= this->backNowButton->getDrawPositionX() && GetMouseX() <= this->backNowButton->getDrawPositionX() + this->backNowButton->getButtonWidth() && GetMouseY() >= this->backNowButton->getDrawPositionY() && GetMouseY() <= this->backNowButton->getDrawPositionY() + this->backNowButton->getButtonHeight()) {
        this->backNowButton->setCurrentTexture(this->backNowButton->getPressedTexture());
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // TODO: Go back to the main menu
        }
    } else {
        this->backNowButton->setCurrentTexture(this->backNowButton->getUnpressedTexture());
        // TODO: Stay on the login screen
    }
    // TODO: Add logic here
};

/*******************************************************
 * LoginDisplay() function will display the login
 * screen to be drawn on the screen by the DrawScreen()
 * function.
 *******************************************************/
void LoginScreen::LoginDisplay() {
    DrawTexture(this->getBackgroundTexture(), 0, 0, WHITE);
    DrawTexture(this->loginNowButton->getCurrentTexture(), this->loginNowButton->getDrawPositionX(), this->loginNowButton->getDrawPositionY(), WHITE);
    DrawTexture(this->backNowButton->getCurrentTexture(), this->backNowButton->getDrawPositionX(), this->backNowButton->getDrawPositionY(), WHITE);

    DrawRectangle(this->loginTextFieldX, this->loginTextFieldY, this->loginTextFieldWidth, this->loginTextFieldHeight, WHITE);
    DrawRectangle(this->passwordTextFieldX, this->passwordTextFieldY, this->passwordTextFieldWidth, this->passwordTextFieldHeight, WHITE);

    DrawRectangleLines(375, 200, 500, 40, BLACK);
    DrawRectangleLines(374, 199, 500, 40, BLACK);
    DrawRectangleLines(373, 198, 500, 40, BLACK);
    DrawRectangleLines(372, 197, 500, 40, BLACK);

    DrawRectangleLines(375, 300, 500, 40, BLACK);
    DrawRectangleLines(374, 299, 500, 40, BLACK);
    DrawRectangleLines(373, 298, 500, 40, BLACK);
    DrawRectangleLines(372, 297, 500, 40, BLACK);
};