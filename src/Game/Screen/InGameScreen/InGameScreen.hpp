#ifndef INGAME_SCREEN_HPP
#define INGAME_SCREEN_HPP
/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

// System Libraries
// N/A

// User Libraries
#include "../Screen.hpp"

// External Libraries
// ---included in Screen.hpp---

class InGameScreen : protected Screen {

    public:
        InGameScreen();  // Constructor
        ~InGameScreen(); // Destructor

        /********************************************************************************
         * DrawScreen() function will draw the all contents to the screen. (Front and Back)
         * Draw Map functions will be drawn here. Also, the player will be drawn here. 
        ********************************************************************************/
        void DrawScreen(); // Implementing 1 of 3 virtual functions from Screen.hpp

        /********************************************************************************
         * These functions will allow two different maps to be drawn. One map will be
         * for walking behind objects, and the other map will be for walking in front of
         * objects.
        ********************************************************************************/
        void DrawFrontMap(); // Implementing 2 of 3 virtual functions from Screen.hpp
        void DrawBackMap(); // Implementing 3 of 3 virtual functions from Screen.hpp
        
        // Function Prototypes
        void InGameLogic();
        void InGameDisplay();

    protected:
        // N/A

    private:
        // N/A

};
#endif