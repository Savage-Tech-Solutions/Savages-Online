/* ************************************************************
 * PROGRAMMER  : TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : TODO: Finish Documentation
 **************************************************************/

#include "MainMenuScreen.hpp"

/*******************************************************
 * Default Constructor
*******************************************************/
MainMenuScreen::MainMenuScreen() {
    Texture2D backgroundTexture = LoadTexture("../resources/GUI/backgrounds/MainMenuScreen/main_menu_screen_background.png");
    this->setBackgroundTexture(backgroundTexture);

    this->loginButton = new Button();
    this->loginButton->setDrawPositionX(490);
    this->loginButton->setDrawPositionY(200);
    this->loginButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->loginButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->loginButton->setButtonWidth(this->loginButton->getUnpressedTexture().width);
    this->loginButton->setButtonHeight(this->loginButton->getUnpressedTexture().height);
    this->loginButton->setCurrentTexture(this->loginButton->getUnpressedTexture());

    this->registerButton = new Button();
    this->registerButton->setDrawPositionX(490);
    this->registerButton->setDrawPositionY(300);
    this->registerButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->registerButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->registerButton->setButtonWidth(this->registerButton->getUnpressedTexture().width);
    this->registerButton->setButtonHeight(this->registerButton->getUnpressedTexture().height);
    this->registerButton->setCurrentTexture(this->registerButton->getUnpressedTexture());

    this->creditsButton = new Button();
    this->creditsButton->setDrawPositionX(490);
    this->creditsButton->setDrawPositionY(400);
    this->creditsButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->creditsButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->creditsButton->setButtonWidth(this->creditsButton->getUnpressedTexture().width);
    this->creditsButton->setButtonHeight(this->creditsButton->getUnpressedTexture().height);
    this->creditsButton->setCurrentTexture(this->creditsButton->getUnpressedTexture());

    this->exitButton = new Button();
    this->exitButton->setDrawPositionX(490);
    this->exitButton->setDrawPositionY(500);
    this->exitButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->exitButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->exitButton->setButtonWidth(this->exitButton->getUnpressedTexture().width);
    this->exitButton->setButtonHeight(this->exitButton->getUnpressedTexture().height);
    this->exitButton->setCurrentTexture(this->exitButton->getUnpressedTexture());

};

/*******************************************************
 * Destructor
*******************************************************/
MainMenuScreen::~MainMenuScreen() {
    delete this->loginButton;
    delete this->registerButton;
    delete this->creditsButton;
    delete this->exitButton;
};

/*******************************************************
 * DrawScreen() function will draw the main menu screen
 * using the pure virtual function from the Screen class.
*******************************************************/
void MainMenuScreen::DrawScreen() {
    MainMenuDisplay();
    MainMenuLogic();
};

/*******************************************************
 * MainMenuLogic() function will handle the logic for
 * the main menu.
*******************************************************/
void MainMenuScreen::MainMenuLogic() {
    if(GetMouseX() >= this->loginButton->getDrawPositionX() && GetMouseX() <= this->loginButton->getDrawPositionX() + this->loginButton->getButtonWidth() &&
       GetMouseY() >= this->loginButton->getDrawPositionY() && GetMouseY() <= this->loginButton->getDrawPositionY() + this->loginButton->getButtonHeight()) {
        this->loginButton->setCurrentTexture(this->loginButton->getPressedTexture());
       } else {
        this->loginButton->setCurrentTexture(this->loginButton->getUnpressedTexture());
       }

    if(GetMouseX() >= this->registerButton->getDrawPositionX() && GetMouseX() <= this->registerButton->getDrawPositionX() + this->registerButton->getButtonWidth() &&
       GetMouseY() >= this->registerButton->getDrawPositionY() && GetMouseY() <= this->registerButton->getDrawPositionY() + this->registerButton->getButtonHeight()) {
        this->registerButton->setCurrentTexture(this->registerButton->getPressedTexture());
       } else {
        this->registerButton->setCurrentTexture(this->registerButton->getUnpressedTexture());
       }

    if(GetMouseX() >= this->creditsButton->getDrawPositionX() && GetMouseX() <= this->creditsButton->getDrawPositionX() + this->creditsButton->getButtonWidth() &&
       GetMouseY() >= this->creditsButton->getDrawPositionY() && GetMouseY() <= this->creditsButton->getDrawPositionY() + this->creditsButton->getButtonHeight()) {
        this->creditsButton->setCurrentTexture(this->creditsButton->getPressedTexture());
       } else {
        this->creditsButton->setCurrentTexture(this->creditsButton->getUnpressedTexture());
       }    

    if(GetMouseX() >= this->exitButton->getDrawPositionX() && GetMouseX() <= this->exitButton->getDrawPositionX() + this->exitButton->getButtonWidth() &&
       GetMouseY() >= this->exitButton->getDrawPositionY() && GetMouseY() <= this->exitButton->getDrawPositionY() + this->exitButton->getButtonHeight()) {
           this->exitButton->setCurrentTexture(this->exitButton->getPressedTexture());
       } else {
        this->exitButton->setCurrentTexture(this->exitButton->getUnpressedTexture());
    }
};

/*******************************************************
 * MainMenuDisplay() function will display the main menu
*******************************************************/
void MainMenuScreen::MainMenuDisplay() {
    DrawTexture(this->getBackgroundTexture(), this->getDrawPositionX(), this->getDrawPositionY(), WHITE);
    DrawTexture(this->loginButton->getCurrentTexture(), this->loginButton->getDrawPositionX(), this->loginButton->getDrawPositionY(), WHITE);
    DrawTexture(this->registerButton->getCurrentTexture(), this->registerButton->getDrawPositionX(), this->registerButton->getDrawPositionY(), WHITE);
    DrawTexture(this->creditsButton->getCurrentTexture(), this->creditsButton->getDrawPositionX(), this->creditsButton->getDrawPositionY(), WHITE);
    DrawTexture(this->exitButton->getCurrentTexture(), this->exitButton->getDrawPositionX(), this->exitButton->getDrawPositionY(), WHITE);
};

int MainMenuScreen::getLoginButtonPositionX(){
    return this->loginButton->getDrawPositionX();
};

int MainMenuScreen::getLoginButtonPositionY(){
    return this->loginButton->getDrawPositionY();
};

int MainMenuScreen::getLoginButtonWidth(){
    return this->loginButton->getButtonWidth();
};

int MainMenuScreen::getLoginButtonHeight(){
    return this->loginButton->getButtonHeight();
};

int MainMenuScreen::getRegisterButtonPositionX(){
    return this->registerButton->getDrawPositionX();
};

int MainMenuScreen::getRegisterButtonPositionY(){
    return this->registerButton->getDrawPositionY();
};

int MainMenuScreen::getRegisterButtonWidth(){
    return this->registerButton->getButtonWidth();
};

int MainMenuScreen::getRegisterButtonHeight(){
    return this->registerButton->getButtonHeight();
};