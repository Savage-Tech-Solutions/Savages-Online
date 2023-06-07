#ifndef Button_hpp
#define Button_hpp

// System Libraries
#include <iostream>
#include <string>

// User Libraries
#include "../../Screen/Screen.hpp"

// External Libraries
// ---included in Screen.hpp---

class Button {

    public:
        Button();
        ~Button();

        void setDrawPositionX(int x);
        void setDrawPositionY(int y);
        void setButtonWidth(int width);
        void setButtonHeight(int height);
        void setUnpressedTexture(Texture2D texture);
        void setPressedTexture(Texture2D texture);
        void setCurrentTexture(Texture2D texture);

        int getDrawPositionX();
        int getDrawPositionY();
        int getButtonWidth();
        int getButtonHeight();
        Texture2D getUnpressedTexture();
        Texture2D getPressedTexture();
        Texture2D getCurrentTexture();

    private:
        int drawX;
        int drawY;
        int width;
        int height;
        Texture2D unpressedTexture;
        Texture2D pressedTexture;
        Texture2D currentTexture;
};

#endif /* Button_hpp */