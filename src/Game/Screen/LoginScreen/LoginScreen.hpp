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
        //TODO: Finish code for RegisterScreen

    private:
        //TODO: Finish code for RegisterScreen

};


#endif /* LoginScreen_hpp */