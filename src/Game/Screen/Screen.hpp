/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef Screen_hpp
#define Screen_hpp

// System Libraries
// N/A

// User Libraries
<<<<<<< HEAD
//#include "../../main.hpp"
=======
// N/A
>>>>>>> 83dea1bf79524c18656494b749329a03a9103f8e

// External Libraries
#include <raylib.h>

/*************************************************
* Class Screen
*************************************************/
class Screen {
    public:
        /*************************************************
        * Default Constructor
        *************************************************/
        Screen();

        /*************************************************
        * Destructor
        *************************************************/
        ~Screen();

        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class.
        *************************************************/
        virtual void DrawScreen() = 0; // IMPLEMENTATION is in all classes derived from the Screen.cpp

<<<<<<< HEAD
        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class.
        *************************************************/
        // virtual void DrawFrontMap() = 0; // IMPLEMENTATION is in InGameScreen.cpp ONLY!!!

        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class.
        ************************************************/
        // virtual void DrawBackMap() = 0; // IMPLEMENTATION is in InGameScreen.cpp

    protected:
        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the x
        * coordinate position which the screen should start
        * to be drawn from. 
        *************************************************/
=======
    //     /*************************************************
    //     * Pure Virtual DrawScreen() class function. This
    //     * function is expected to be defined in the
    //     * derived class.
    //     *************************************************/
    //     virtual void DrawFrontMap() = 0; // IMPLEMENTATION is in InGameScreen.cpp ONLY!!!

    //     /*************************************************
    //     * Pure Virtual DrawScreen() class function. This
    //     * function is expected to be defined in the
    //     * derived class.
    //     ************************************************/
    //    virtual void DrawBackMap() = 0; // IMPLEMENTATION is in InGameScreen.cpp
    protected:

        /*************************************************
         * This is a protected function within the Screen
         * class. This function may get called by the
         * derived class. This function will set the x
         * coordinate position which the screen should start
         * to be drawn from.
         *************************************************/
>>>>>>> 83dea1bf79524c18656494b749329a03a9103f8e
        void setDrawPositionX(int x);

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the y
        * coordinate position which the screen should start
        * to be drawn from.
        *************************************************/
        void setDrawPositionY(int y);

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the width
        * of the screen.
        *************************************************/
        void setScreenWidth(int width);

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the height
        * of the screen.
        *************************************************/
        void setScreenHeight(int height);

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the 
        * background image texture with the passed
        * Texture2D data type as the parameter.
        *************************************************/
        void setBackgroundTexture(Texture2D texture);

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will return the x
        * coordinate for start draw location. 
        *************************************************/
        int getDrawPositionX()const;

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will return the y
        * coordinate for the start draw location. 
        *************************************************/
        int getDrawPositionY()const;

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will return the
        * width of the Screen object.
        *************************************************/
        int getScreenWidth()const;

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will return the
        * height of the Screen object.
        *************************************************/
        int getScreenHeight()const;

        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will return the
        * background texture of the Screen object.
        *************************************************/
        Texture2D getBackgroundTexture()const;

    protected:
        Font userInputFontStyle; // Font used for user input in derived Screen classes.

    private:
        int x;                   // Variable holds 'x' coordinate for draw location.
        int y;                   // Variable holds 'y' coordinate for draw location.
        int width;               // Variable holds the 'width' of the Screen object.
        int height;              // Variable holds the 'height' of the Screen object.
        Texture2D background;    // Variable holds the 'image' of the Screen object.
};

#endif /* Screen_hpp */