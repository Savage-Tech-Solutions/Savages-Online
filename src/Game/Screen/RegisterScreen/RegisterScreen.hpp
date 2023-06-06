/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#ifndef RegisterScreen_hpp
#define RegisterScreen_hpp

// System Libraries
// N/A

// User Libraries
#include "../Screen.hpp"
#include "../../Component/Button/Button.hpp"

// External Libraries
// ---included in Screen.hpp---

class RegisterScreen : protected Screen {

    public:
        RegisterScreen();
        ~RegisterScreen();
        void DrawScreen();

        int getUsernameTextFieldX();
        int getUsernameTextFieldY();
        int getUsernameTextFieldWidth();
        int getUsernameTextFieldHeight();

        int getEmailTextFieldX();
        int getEmailTextFieldY();
        int getEmailTextFieldWidth();
        int getEmailTextFieldHeight();

        int getPasswordTextFieldX();
        int getPasswordTextFieldY();
        int getPasswordTextFieldWidth();
        int getPasswordTextFieldHeight();

        int getConfirmPasswordTextFieldX();
        int getConfirmPasswordTextFieldY();
        int getConfirmPasswordTextFieldWidth();
        int getConfirmPasswordTextFieldHeight();

        int getRegisterButtonX();
        int getRegisterButtonY();
        int getRegisterButtonWidth();
        int getRegisterButtonHeight();

        int getBackButtonX();
        int getBackButtonY();
        int getBackButtonWidth();
        int getBackButtonHeight();


    protected:
        void RegisterLogic();
        void RegisterDisplay();

        void HandleKeyboardInput();
        void HandleMouseInput();

    private:
        Button *registerButton;
        Button *backButton;
        
        Texture2D backgroundTexture;

        int usernameTextFieldX;
        int usernameTextFieldY;
        int usernameTextFieldWidth;
        int usernameTextFieldHeight;
        Rectangle *usernameTextFieldRec;

        int emailTextFieldX;
        int emailTextFieldY;
        int emailTextFieldWidth;
        int emailTextFieldHeight;
        Rectangle *emailTextFieldRec;

        int passwordTextFieldX;
        int passwordTextFieldY;
        int passwordTextFieldWidth;
        int passwordTextFieldHeight;
        Rectangle *passwordTextFieldRec;

        int confirmPasswordTextFieldX;
        int confirmPasswordTextFieldY;
        int confirmPasswordTextFieldWidth;
        int confirmPasswordTextFieldHeight;
        Rectangle *confirmPasswordTextFieldRec;

        Color notHovering;
        Color hovering;

        Color userHovered;
        Color emailHovered;
        Color passwordHovered;
        Color confirmPasswordHovered;

        bool hoveredAndClicked;  // Clicked on specific Text Field while hovering over it (true = yes, false = no)

        std::string username;
        std::string email;
        std::string password;
        std::string confirmPassword;

        json registerData;

        bool registerSuccess;
};


#endif /* RegisterScreen_hpp */