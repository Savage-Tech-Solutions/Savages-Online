/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef LoginScreen_hpp
#define LoginScreen_hpp

// System Libraries
// N/A

// User Libraries
#include "../Screen.hpp"
#include "../ButtonComponent/Button.hpp"

// External Libraries
// ---included in Screen.hpp---


class LoginScreen : protected Screen {

    public:
        LoginScreen();
        ~LoginScreen();

        // RegisterScreen Function Prototypes
        void DrawScreen();
        void LoginLogic();
        void LoginDisplay();

        int getLoginTextFieldX();
        int getLoginTextFieldY();
        int getLoginTextFieldWidth();
        int getLoginTextFieldHeight();

        int getPasswordTextFieldX();
        int getPasswordTextFieldY();
        int getPasswordTextFieldWidth();
        int getPasswordTextFieldHeight();

        int getLoginNowButtonX();
        int getLoginNowButtonY();
        int getLoginNowButtonWidth();
        int getLoginNowButtonHeight();

        int getBackNowButtonX();
        int getBackNowButtonY();
        int getBackNowButtonWidth();
        int getBackNowButtonHeight();

    protected:
        // N/A

    private:
        Button *loginNowButton;
        Button *backNowButton;
        Texture2D backgroundTexture;

        int loginTextFieldX;
        int loginTextFieldY;
        int loginTextFieldWidth;
        int loginTextFieldHeight;
        Rectangle loginTextFieldRec;

        int passwordTextFieldX;
        int passwordTextFieldY;
        int passwordTextFieldWidth;
        int passwordTextFieldHeight;
        Rectangle passwordTextFieldRec;

        std::string username;
        std::string password;

        json userData;
};


#endif /* LoginScreen_hpp */