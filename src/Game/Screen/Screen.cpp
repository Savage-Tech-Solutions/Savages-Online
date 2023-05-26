/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "Screen.hpp"

/*************************************************************
 * This is the default constructor function for the Screen
 * class. This function will initialize the class attribute
 * to a few default values. If values are needed to be changed, 
 * a class function must be called.
 *************************************************************/
Screen::Screen(){
    this->x = 0;
    this->y = 0;
    this->width = 1280;
    this->height = 720;
    this->background = LoadTexture("resources/GUI/backgrounds/paper_background.png");  // edit this later
    this->userInputFontStyle = LoadFont("resources/Fonts/PathwayGothicOne-Regular.ttf"); // edit this later
}


/*************************************************************
 * This is the destructor function for the Screen class
 * object. This function will get called when the Screen class
 * is out of scope. The background texture must get unloaded.
 *************************************************************/
Screen::~Screen(){
    UnloadTexture(this->background);
    UnloadFont(this->userInputFontStyle);
}


/*************************************************************
 * This is the Screen class function for setting the drawing
 * x coordinate location. One parameter is passed by value which
 * is used to set the starting x coordinate. This function is
 * void, nothing gets returned.
 *************************************************************/
void Screen::setDrawPositionX(int x){
    this->x = x;
}


/*************************************************************
 * This is the Screen class function for setting the drawing
 * y coordinate location. One parameter is passed by value which
 * is used to set the starting y coordinate. This function is
 * void, nothing gets returned.
 *************************************************************/
void Screen::setDrawPositionY(int y){
    this->y = y;
}


/*************************************************************
 * This is the Screen class function for setting the width of
 * the Screen object. Default value is used unless class
 * function gets called to change its value. This function is
 * void, nothing gets returned.
 *************************************************************/
void Screen::setScreenWidth(int width){
    this->width = width;
}


/*************************************************************
 * This is the Screen class function for setting the height of
 * the Screen object. Default value is used unless class
 * function gets called to change its value. This function is
 * void, nothing gets returned.
 *************************************************************/
void Screen::setScreenHeight(int height){
    this->height = height;
}


/*************************************************************
 * This is the Screen class function for setting the background
 * texture image of the Screen object. The screen class object
 * uses a default image for the screen background, unless this
 * class function gets called to change the default texture.
 * This function is void, nothing gets returned.
 *************************************************************/
void Screen::setBackgroundTexture(Texture2D texture){
    this->background = texture;
}


/*************************************************************
 * This is the Screen class function for returning the starting
 * x draw coordinate. This function returns type integer.
 *************************************************************/
int Screen::getDrawPositionX()const{
    return this->x;
}


/*************************************************************
 * This is the Screen class function for returning the starting
 * y draw coordinate. This function returns type integer.
 *************************************************************/
int Screen::getDrawPositionY()const{
    return this->y;
}


/*************************************************************
 * This is the Screen class function for returning the width
 * of the screen object. This function returns type integer.
 *************************************************************/
int Screen::getScreenWidth()const{
    return this->width;
}


/*************************************************************
 * This is the Screen class function for returning the height
 * of the screen object. This function returns type integer.
 *************************************************************/
int Screen::getScreenHeight()const{
    return this->height;
}


/*************************************************************
 * This is the Screen class function for returning the texture
 * image of the Screen object. This function returns type
 * Texture2D.
 *************************************************************/
Texture2D Screen::getBackgroundTexture()const{
    return this->background;
}

