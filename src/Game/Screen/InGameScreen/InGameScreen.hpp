/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef InGameScreen_hpp
#define InGameScreen_hpp

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"
#include "../../Component/Button/Button.hpp"

// External Libraries
// ---included in Screen.hpp---

class InGameScreen : protected Screen {

    public:
        /***********************************
         * Default Constructor
         ***********************************/
        InGameScreen();

        /***********************************
         * Destructor
         ***********************************/
        ~InGameScreen(); // Destructor

        /***********************************
         * Implementing pure virtual function
         ***********************************/
        void DrawScreen();

        /***********************************
         * TODO: Finish Documentation
        ***********************************/
        void DrawFrontMap(); 

        /***********************************
         * TODO: Finish Documentation
         ***********************************/
        void DrawBackMap();  // TODO: Implement this function

        /***********************************
         * TODO: Finish Documentation
         ***********************************/
        void InGameLogic();  // TODO: Implement this function

        /***********************************
         * TODO: Finish Documentation
         ***********************************/
        void InGameDisplay(); // TODO: Implement this function

    protected:
        // N/A

    private:
        Texture2D frontMapTexture;

};

#endif