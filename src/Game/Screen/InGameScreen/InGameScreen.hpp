/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef INGAME_SCREEN_HPP
#define INGAME_SCREEN_HPP

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../Screen.hpp"

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
        void DrawScreen(); // Implementing 1 of 3 virtual functions from Screen.hpp

        /***********************************
         * 
        ***********************************/
        void DrawFrontMap(); // TODO: Implement this function

        /***********************************
         *
         ***********************************/
        void DrawBackMap();  // TODO: Implement this function

        /***********************************
         *
         ***********************************/
        void InGameLogic();  // TODO: Implement this function

        /***********************************
         *
         ***********************************/
        void InGameDisplay(); // TODO: Implement this function

    protected:
        // N/A

    private:
        // N/A

};

#endif