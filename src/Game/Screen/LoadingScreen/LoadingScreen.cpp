#include "LoadingScreen.hpp"

LoadingScreen::LoadingScreen() :anim_counter(0) {
    // N/A
};


LoadingScreen::~LoadingScreen() {
    // N/A
};


void LoadingScreen::DrawScreen() {
    anim_counter = (anim_counter + 1) % 90;
    int row = anim_counter % 23;
    int col = anim_counter / 23;
    DrawTextureRec(this->backgroundTexture, Rectangle{col * 1280.0f, row * 720.0f, 1280, 720}, Vector2{0.0f, 0.0f}, WHITE);
};


void LoadingScreen::LoadingScreenLogic() {
    // N/A
};


void LoadingScreen::LoadingScreenDisplay() {
    // N/A
};


void LoadingScreen::setBackgroundTexture(Texture2D texture) {
    
    texture = LoadTexture("../resources/GUI/backgrounds/loading_sheet.png");
    this->backgroundTexture = texture;
};
