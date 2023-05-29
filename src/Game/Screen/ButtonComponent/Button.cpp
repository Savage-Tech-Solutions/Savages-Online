#include "Button.hpp"

Button::Button(){
    this->drawX = 0;
    this->drawY = 0;
    this->unpressedTexture = LoadTexture("../../resources/GUI/buttons/01/button_unpressed.png");
    this->pressedTexture = LoadTexture("../../resources/GUI/buttons/01/button_pressed.png");
    this->currentTexture = this->unpressedTexture;
    this->width = this->currentTexture.width;
    this->height = this->currentTexture.height;
};

Button::~Button(){
    UnloadTexture(this->unpressedTexture);
    UnloadTexture(this->pressedTexture);
};

// setters

void Button::setDrawPositionX(int x){
    this->drawX = x;
};

void Button::setDrawPositionY(int y){
    this->drawY = y;
};

void Button::setButtonWidth(int width){
    this->width = width;
};

void Button::setButtonHeight(int height){
    this->height = height;
};

void Button::setPressedTexture(Texture2D texture){
    this->pressedTexture = texture;
};

void Button::setUnpressedTexture(Texture2D texture){
    this->unpressedTexture = texture;
};

void Button::setCurrentTexture(Texture2D texture){
    this->currentTexture = texture;
};

// Getters

int Button::getDrawPositionX(){
    return this->drawX;
};

int Button::getDrawPositionY(){
    return this->drawY;
};

int Button::getButtonWidth(){
    return this->width;
};

int Button::getButtonHeight(){
    return this->height;
};

Texture2D Button::getPressedTexture(){
    return this->pressedTexture;
};

Texture2D Button::getUnpressedTexture(){
    return this->unpressedTexture;
};

Texture2D Button::getCurrentTexture(){
    return this->currentTexture;
};