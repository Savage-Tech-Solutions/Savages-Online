#include "LoadingScreen.hpp"

LoadingScreen::LoadingScreen() {
    // N/A
};


LoadingScreen::~LoadingScreen() {
    // N/A
};


void LoadingScreen::DrawScreen() {
    DrawTexture(this->backgroundTexture, this->getScreenWidth(), this->getScreenHeight(), WHITE);
};


void LoadingScreen::LoadingScreenLogic() {
    // N/A
};


void LoadingScreen::LoadingScreenDisplay() {
    // N/A
};


void LoadingScreen::setBackgroundTexture(Texture2D texture) {

    texture = LoadTexture("../../../resources/GUI/backgrounds/loading.gif");
    this->backgroundTexture = texture;
};
