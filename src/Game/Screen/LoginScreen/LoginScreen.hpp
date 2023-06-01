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

    protected:
        // N/A

    private:
        Button *loginNowButton;
        Button *registerNowButton;
        Texture2D backgroundTexture;

        int loginNowX;
        int loginNowY;
        int loginNowWidth;
        int loginNowHeight;

        int registerNowX;
        int registerNowY;
        int registerNowWidth;
        int registerNowHeight;
};


#endif /* LoginScreen_hpp */