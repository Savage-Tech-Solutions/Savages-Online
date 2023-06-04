/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "RegisterScreen.hpp"

/*******************************************************
 * Default Constructor
 *******************************************************/
RegisterScreen::RegisterScreen() {

    // Register Button
    this->registerButton = new Button();
    this->registerButton->setDrawPositionX(700);
    this->registerButton->setDrawPositionY(550);
    this->registerButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->registerButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->registerButton->setButtonWidth(this->registerButton->getUnpressedTexture().width);
    this->registerButton->setButtonHeight(this->registerButton->getUnpressedTexture().height);
    this->registerButton->setCurrentTexture(this->registerButton->getUnpressedTexture());

    // Back Button
    this->backButton = new Button();
    this->backButton->setDrawPositionX(300);
    this->backButton->setDrawPositionY(550);
    this->backButton->setUnpressedTexture(LoadTexture("../resources/GUI/buttons/01/button_unpressed.png"));
    this->backButton->setPressedTexture(LoadTexture("../resources/GUI/buttons/01/button_pressed.png"));
    this->backButton->setButtonWidth(this->backButton->getUnpressedTexture().width);
    this->backButton->setButtonHeight(this->backButton->getUnpressedTexture().height);
    this->backButton->setCurrentTexture(this->backButton->getUnpressedTexture());

    // Username Text Field
    this->usernameTextFieldX = 375;
    this->usernameTextFieldY = 100;
    this->usernameTextFieldWidth = 500;
    this->usernameTextFieldHeight = 40;
    this->usernameTextFieldRec = new Rectangle{375, 100, 500, 40};

    // Email Text Field
    this->emailTextFieldX = 375;
    this->emailTextFieldY = 200;
    this->emailTextFieldWidth = 500;
    this->emailTextFieldHeight = 40;
    this->emailTextFieldRec = new Rectangle{375, 200, 500, 40};

    // Password Text Field
    this->passwordTextFieldX = 375;
    this->passwordTextFieldY = 300;
    this->passwordTextFieldWidth = 500;
    this->passwordTextFieldHeight = 40;
    this->passwordTextFieldRec = new Rectangle{375, 300, 500, 40};

    // Confirm Password Text Field
    this->confirmPasswordTextFieldX = 375;
    this->confirmPasswordTextFieldY = 400;
    this->confirmPasswordTextFieldWidth = 500;
    this->confirmPasswordTextFieldHeight = 40;
    this->confirmPasswordTextFieldRec = new Rectangle{375, 400, 500, 40};     
    
    // Text Field Colors
    this->notHovering = {197, 211, 212, 255};
    this->hovering = {163, 204, 207, 255};

    // Set initial Text Field Colors to not hovering
    this->userHovered = this->notHovering;
    this->emailHovered = this->notHovering;
    this->passwordHovered = this->notHovering;
    this->confirmPasswordHovered = this->notHovering;

    // Setting hoveredAndClicked to false since no text field is clicked on yet
    this->hoveredAndClicked = false;

    // User input data (to be stored in json)
    this->username = "";
    this->email = "";   
    this->password = "";
    this->confirmPassword = "";

    // Register Data (JSON Object)
    this->registerData = {
        {"user", this->username},
        {"email", this->email},
        {"pass", this->password},
        {"confirmPass", this->confirmPassword}
    };

    // Was registration a success?
    this->registerSuccess = true;   // Change to false later...

    // Output JSON data to console
    std::cout << registerData.dump(4) << std::endl;

};

/*******************************************************
 * Destructor
 *******************************************************/
RegisterScreen::~RegisterScreen() {
    
    //Buttons
    delete this->registerButton;
    delete this->backButton;

    // Text Fields
    delete this->usernameTextFieldRec;
    delete this->emailTextFieldRec;
    delete this->passwordTextFieldRec;
    delete this->confirmPasswordTextFieldRec;

};

/*******************************************************
 * DrawScreen() function will draw the register screen
 *******************************************************/
void RegisterScreen::DrawScreen() {
    this->RegisterDisplay();
    this->RegisterLogic();
};

/*******************************************************
 * RegisterLogic() function will handle the logic for
 * the register screen.
 *******************************************************/
void RegisterScreen::RegisterLogic() {

    /******************************************************************************************************************/
    /********************************** Register Button Logic (Pressed/Unpressed) *************************************/
    /******************************************************************************************************************/

    if(GetMouseX() >= this->registerButton->getDrawPositionX() && GetMouseX() <= this->registerButton->getDrawPositionX() + this->registerButton->getButtonWidth() && GetMouseY() >= this->registerButton->getDrawPositionY() && GetMouseY() <= this->registerButton->getDrawPositionY() + this->registerButton->getButtonHeight()) {
        this->registerButton->setCurrentTexture(this->registerButton->getPressedTexture());
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // TODO: Add logic here (What to do next...)
        }
    } else {
        this->registerButton->setCurrentTexture(this->registerButton->getUnpressedTexture());
    }
    
    /******************************************************************************************************************/
    /********************************** Back Button Logic (Pressed/Unpressed) *****************************************/
    /******************************************************************************************************************/

    if(GetMouseX() >= this->backButton->getDrawPositionX() && GetMouseX() <= this->backButton->getDrawPositionX() + this->backButton->getButtonWidth() && GetMouseY() >= this->backButton->getDrawPositionY() && GetMouseY() <= this->backButton->getDrawPositionY() + this->backButton->getButtonHeight()) {
        this->backButton->setCurrentTexture(this->backButton->getPressedTexture());
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // TODO: Go back to the main menu
        }
    } else {
        this->backButton->setCurrentTexture(this->backButton->getUnpressedTexture());
    };



    /******************************************************************************************************************/
    /************************************ Username Text Field Logic (Hover/Un-Hover ***********************************/
    /******************************************************************************************************************/

    // Username Text Field Logic
    if(GetMouseX() >= this->usernameTextFieldX && GetMouseX() <= this->usernameTextFieldX + this->usernameTextFieldWidth && GetMouseY() >= this->usernameTextFieldY && GetMouseY() <= this->usernameTextFieldY + this->usernameTextFieldHeight) {
        this->userHovered = this->hovering;
    
    // Email Text Field Logic
    } else if(GetMouseX() >= this->emailTextFieldX && GetMouseX() <= this->emailTextFieldX + this->emailTextFieldWidth && GetMouseY() >= this->emailTextFieldY && GetMouseY() <= this->emailTextFieldY + this->emailTextFieldHeight) {
        this->emailHovered = this->hovering;
    
    // Password Text Field Logic
    } else if(GetMouseX() >= this->passwordTextFieldX && GetMouseX() <= this->passwordTextFieldX + this->passwordTextFieldWidth && GetMouseY() >= this->passwordTextFieldY && GetMouseY() <= this->passwordTextFieldY + this->passwordTextFieldHeight) {
        this->passwordHovered = this->hovering;
    
    // Confirm Password Text Field Logic
    } else if (GetMouseX() >= this->confirmPasswordTextFieldX && GetMouseX() <= this->confirmPasswordTextFieldX + this->confirmPasswordTextFieldWidth && GetMouseY() >= this->confirmPasswordTextFieldY && GetMouseY() <= this->confirmPasswordTextFieldY + this->confirmPasswordTextFieldHeight) {
        this->confirmPasswordHovered = this->hovering;
    
    // The cursor is not inside any Text Fields
    } else {
        this->userHovered = this->notHovering;
        this->emailHovered = this->notHovering;
        this->passwordHovered = this->notHovering;
        this->confirmPasswordHovered = this->notHovering;
    }

    /******************************************************************************************************************/
    /******************************************************************************************************************/
    /******************************************************************************************************************/

};

/*******************************************************
 * RegisterDisplay() function will display the register
 * screen
 *******************************************************/
void RegisterScreen::RegisterDisplay() {
    
    // Background Texture
    DrawTexture(this->getBackgroundTexture(), 0, 0, WHITE);

    // Username Text Field
    DrawRectangleRec(*this->usernameTextFieldRec, this->userHovered); // Username Text Field
    DrawRectangleLines(375, 100, 500, 40, BLACK);
    DrawRectangleLines(374, 99, 500, 40, BLACK);
    DrawRectangleLines(373, 98, 500, 40, BLACK);
    DrawRectangleLines(372, 97, 500, 40, BLACK);

    // Email Text Field
    DrawRectangleRec(*this->emailTextFieldRec, this->emailHovered); // Email Text Field
    DrawRectangleLines(375, 200, 500, 40, BLACK);
    DrawRectangleLines(374, 199, 500, 40, BLACK);
    DrawRectangleLines(373, 198, 500, 40, BLACK);
    DrawRectangleLines(372, 197, 500, 40, BLACK);

    // Password Text Field
    DrawRectangleRec(*this->passwordTextFieldRec, this->passwordHovered); // Password Text Field
    DrawRectangleLines(375, 300, 500, 40, BLACK);
    DrawRectangleLines(374, 299, 500, 40, BLACK);
    DrawRectangleLines(373, 298, 500, 40, BLACK);
    DrawRectangleLines(372, 297, 500, 40, BLACK);

    // Confirm Password Text Field
    DrawRectangleRec(*this->confirmPasswordTextFieldRec, this->confirmPasswordHovered); // Confirm Password Text Field
    DrawRectangleLines(375, 400, 500, 40, BLACK);
    DrawRectangleLines(374, 399, 500, 40, BLACK);
    DrawRectangleLines(373, 398, 500, 40, BLACK);
    DrawRectangleLines(372, 397, 500, 40, BLACK);

    // Register Button (Button Texture/ Button Text)
    DrawTexture(this->registerButton->getCurrentTexture(), this->registerButton->getDrawPositionX(), this->registerButton->getDrawPositionY(), WHITE); // Register Button
    DrawText("Register", this->registerButton->getDrawPositionX() + 90, this->registerButton->getDrawPositionY() + 15, 26, WHITE);

    // Back Button (Button Texture/ Button Text)
    DrawTexture(this->backButton->getCurrentTexture(), this->backButton->getDrawPositionX(), this->backButton->getDrawPositionY(), WHITE); // Back Button
    DrawText("Back", this->backButton->getDrawPositionX() + 110, + this->backButton->getDrawPositionY() + 15, 26, WHITE);

};

/*******************************************************
 * TODO: Finish Documentation
 *******************************************************/
void RegisterScreen::HandleKeyboardInput(){

};

/*******************************************************
 * TODO: Finish Documentation
 *******************************************************/
void RegisterScreen::HandleMouseInput(){
    
};


/*******************************************************************************************/
/*******************************************
 * GETTERS FOR DIMENSIONS OF THE COMPONENTS
********************************************/
/*******************************************************************************************/

/******************************************************/
/******************** TEXT FIELDS *********************/
/******************************************************/

// Username Text Field
int RegisterScreen::getUsernameTextFieldX(){
    return this->usernameTextFieldX;
};

int RegisterScreen::getUsernameTextFieldY(){
    return this->usernameTextFieldY;
};

int RegisterScreen::getUsernameTextFieldWidth(){
    return this->usernameTextFieldWidth;
};

int RegisterScreen::getUsernameTextFieldHeight(){
    return this->usernameTextFieldHeight;
};

// Email Text Field
int RegisterScreen::getEmailTextFieldX(){
    return this->emailTextFieldX;
};

int RegisterScreen::getEmailTextFieldY(){
    return this->emailTextFieldY;
};

int RegisterScreen::getEmailTextFieldWidth(){
    return this->emailTextFieldWidth;
};

int RegisterScreen::getEmailTextFieldHeight(){
    return this->emailTextFieldHeight;
};

// Password Text Field
int RegisterScreen::getPasswordTextFieldX(){
    return this->passwordTextFieldHeight;
};

int RegisterScreen::getPasswordTextFieldY(){
    return this->passwordTextFieldY;
};

int RegisterScreen::getPasswordTextFieldWidth(){
    return this->passwordTextFieldWidth;
};

int RegisterScreen::getPasswordTextFieldHeight(){
    return this->passwordTextFieldHeight;
};

// Confirm Password Text Field
int RegisterScreen::getConfirmPasswordTextFieldX(){
    return this->confirmPasswordTextFieldX;
};

int RegisterScreen::getConfirmPasswordTextFieldY(){
    return this->confirmPasswordTextFieldY;
};

int RegisterScreen::getConfirmPasswordTextFieldWidth(){
    return this->confirmPasswordTextFieldWidth;
};

int RegisterScreen::getConfirmPasswordTextFieldHeight(){
    return this->confirmPasswordTextFieldHeight;
};

/******************************************************/
/********************* BUTTONS ************************/
/******************************************************/

// Register Button
int RegisterScreen::getRegisterButtonX(){
    return this->registerButton->getDrawPositionX();
};

int RegisterScreen::getRegisterButtonY(){
    return this->registerButton->getDrawPositionY();
};

int RegisterScreen::getRegisterButtonWidth(){
    return this->registerButton->getButtonWidth();
};

int RegisterScreen::getRegisterButtonHeight(){
    return this->registerButton->getButtonHeight();
};

// Back Button
int RegisterScreen::getBackButtonX(){
    return this->backButton->getDrawPositionX();
};

int RegisterScreen::getBackButtonY(){
    return this->backButton->getDrawPositionY();
};

int RegisterScreen::getBackButtonWidth(){
    return this->backButton->getButtonWidth();
};

int RegisterScreen::getBackButtonHeight(){
    return this->backButton->getButtonHeight();
};