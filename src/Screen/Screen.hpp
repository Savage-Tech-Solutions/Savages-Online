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
#include "../Main/main.hpp"

// External Libraries
#include "raylib.h"

/*************************************************
* Class Screen
*************************************************/
class Screen {
    public:
        /*************************************************
        * Default Constructor
        * No Parameters
        *************************************************/
        Screen();

        /*************************************************
        * Destructor
        * No Parameters
        *************************************************/
        ~Screen();

        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class.
        *************************************************/
        virtual void DrawScreen() = 0;

    protected:
        /*************************************************
        * This is a protected function within the Screen
        * class. This function may get called by the
        * derived class. This function will set the x
        * coordinate position which the screen should start
        * to be drawn from. 
        *************************************************/
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
        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class. - This function will draw the
        * front layout with all the assets,etc. Such as 
        * trees, buildings, bushes, etc.
        * ------ONLY GETS USED FROM WORLD CLASS...-------
        *************************************************/
        virtual void DrawFrontScreen() = 0;

        /*************************************************
        * Pure Virtual DrawScreen() class function. This
        * function is expected to be defined in the
        * derived class. - This function will draw the
        * back layout/ground layer. - Such as grass, dirt,
        * or any other ground texture. (Player doesn't walk)
        * over trees, buildings, etc.
        * ------ONLY GETS USED FROM WORLD CLASS...-------
        *************************************************/
        virtual void DrawBackScreen() = 0;
        int x;                   // Variable holds 'x' coordinate for draw location.
        int y;                   // Variable holds 'y' coordinate for draw location.
        int width;               // Variable holds the 'width' of the Screen object.
        int height;              // Variable holds the 'height' of the Screen object.
        Texture2D background;    // Variable holds the 'image' of the Screen object.
};

#endif /* Screen_hpp */