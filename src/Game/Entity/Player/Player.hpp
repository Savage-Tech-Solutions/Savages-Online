/*************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : //TODO: Finish Documentation
 **************************************************************/

#ifndef Player_hpp
#define Player_hpp

// System Libraries
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// User Libraries
//#include "Map.h"

// External Libraries
#include "raylib.h"
//#include "api.h"

using std::string;
using std::vector;
using std::stringstream;

// Template to parse data types from the database.
template <class S>
S parseData(const std::string& s){
  S out;
  std::stringstream ss(s);
  ss >> out;
  return out;
}

int TOTAL_BLOCKED_LOCATIONS = 625;

/*************************************************
* Class Player
*************************************************/
class Player {
    public:
        /*************************************************
        * Default Constructor
        *************************************************/
        Player();

        /*************************************************
        * Destructor
        *************************************************/
        ~Player();

        /*************************************************
        * This class function is for drawing the player to
        * the game screen. The functions to handle the
        * logic behind different movement keys pressed, etc
        * will reside in this function to keep player
        * always updated to current state required. This
        * function is of type void and does not return
        * anything.
        *************************************************/
        void DrawPlayer();

        /*************************************************
        * This is the Player class function for returning
        * the Camera. This camera follows the player during
        * the game, and will be needed in main. This
        * function is read-only.
        *************************************************/
        Camera2D getCamera()const;

        /*************************************************
        * This is the class function for setting the 
        * blocked locations for the player using a passed
        * array as a parameter from the Map object which
        * originally creates the locations blocked on the
        * map from a file. This function is of type void
        * does not return anything.
        *************************************************/
        void setBlockedLocations(Rectangle recArr[], const int MAX_SIZE);

        /*************************************************
        * This is the class function for setting the total
        * number of blocked locations on the current map.
        * The number of blocked locations from the map
        * object needs to be transferred with this function.
        *************************************************/
        void setTotalBlockedLocations(int numberOfLocations);

        /*************************************************
        * This is the Player class function for getting
        * the Player's 'x' coordinate for returning.
        *************************************************/
        int getPlayerX()const;

        /*************************************************
        * This is the Player class function for getting
        * the Player's 'y' coordinate for returning.
        *************************************************/
        int getPlayerY()const;

        /*************************************************
        * This is the Player class function for getting
        * the Player's facing direction to be returned
        * as char data type.
        *************************************************/
        char getPlayerDirection()const;

        /*************************************************
        * This is the Player class function for getting
        * the Player's (x,y) location as a Vector2 data
        * type to be returned.
        *************************************************/
        Vector2 getPlayerPosition()const;

        /*************************************************
        * This is the Player class function for getting
        * the camera 'x' coordinate for returning.
        *************************************************/
        float getCameraX()const;

        /*************************************************
        * This is the Player class function for getting
        * the camera 'y' coordinate for returning.
        *************************************************/
        float getCameraY()const;

        /*************************************************
        * This is the Player class function for getting
        * the players surrounding rectangle to be used
        * for collision checking. This function is of 
        * type rectangle and the same data type will be
        * returned.
        *************************************************/
        Rectangle getPlayerSurroundingRec()const;

        /*************************************************
        * This is the Player class function for setting 
        * the 'x' coordinate location. This function is
        * of type void and does not return anything.
        *************************************************/
        void setPositionX(int x);

        /*************************************************
        * This is the Player class function for setting 
        * the 'y' coordinate location. This function is
        * of type void and does not return anything.
        *************************************************/
        void setPositionY(int y);

        /*************************************************
        * This is the Player class function for setting
        * the players direction. This function is of type
        * void and does not return anything.
        *************************************************/
        void setPlayerDirection(char direction);
        
        /*************************************************
        * This is the Player class function for setting 
        * the players camera 'x' location. This function is
        * of type void and does not return anything.
        *************************************************/
        void setCameraX(float x);

        /*************************************************
        * This is the Player class function for setting
        * the camera 'y' location. This function is of 
        * type void and does not return anything.
        *************************************************/
        void setCameraY(float y);

        /*************************************************
        * This is the Player class function for setting 
        * the frameX coordinate position to set the facing
        * direction for the player when the game loads. 
        * The facing direction is loaded from the database
        * and depending on the direction a frameX will be
        * set for the players sprite sheet.
        *************************************************/
        void setFrameX(float x);
        
        /*************************************************
        * This is the Player class function for setting 
        * the frameY coordinate position to set the facing
        * direction for the player when the game loads. 
        * The facing direction is loaded from the database
        * and depending on the direction a frameY will be
        * set for the players sprite sheet.
        *************************************************/
        void setFrameY(float y);
        
        /*************************************************
        * This is the Player class function for setting 
        * the logged in players username in Game class.
        * This function is of type void and nothing will
        * be returned.
        *************************************************/
        void setUsernameLoggedIn(string username);

    private:
        /*************************************************
        * This PRIVATE class function is for handling the
        * logic associated with player walking movements.
        * This function is of type void and does not
        * return anything.
        *************************************************/
        void HandlePlayerWalking();

        /*************************************************
        * This PRIVATE class function is for handling the
        * logic associated with player attacking movements
        * and animations. This function is of type void 
        * and does not return anything.
        *************************************************/
        void HandlePlayerAttacking();

        /*************************************************
        * This is a PRIVATE class function for handing
        * all logic associated with the player to allow
        * for easier code readability. All functions that
        * handle different logic associated with player
        * should reside in this function. This function is
        * of type void and does not return anything.
        *************************************************/
        void HandlePlayerLogic();

        // Variables hold sprite sheet images.
        Texture2D HumanSpriteSheet;              // Image/Texture for the Human Sprite sheet.
        Texture2D DemonSpriteSheet;              // Image/Texture for the Demon Sprite sheet.
        Texture2D CurrentSpriteSheet;            // A Re-assignable Image/Texture for the current sprite sheet.
        
        // Variables associated w/ sprite sheet.
        float FrameX;                            // Variable associated with the current 'X' position in the frameRec.
        float FrameY;                            // Variable associated with the current 'Y' position in the frameRec.
        Rectangle frameRec;                      // Variable associated with the entire frameRec rectangle.

        // Variables used for Player Walking.
        string firstMovementKeyPressed;         // Variable used to determine which movement key is being pressed first.
        bool walkingMode;                       // Variable used to determine if player is walking or not.
        int walkingAnimationTimer;              // Variable used for animating the player walking.

        // Variables used for Player Attacking.
        bool attackMode;                        // Variable used for determining if the player is attacking or not.
        int attackAnimationTimer;               // Variable used for animating the player attacking.

        int PlayerX;                     // Variable used to hold Player's X coordinate location.
        int PlayerY;                     // Variable used to hold Player's Y coordinate location.
        char PlayerDirection;            // Variable used to hold Player's Facing Cardinal Direction.
        Vector2 PlayerPosition;          // Variable used to hold Player's (X,Y) coordinate location.
        Rectangle PlayerSurroundingRec;  // Variable holds rectangle around the player on the screen (used for collision detection, etc.)

        float CameraX;              // Variable used to store the Camera X coordinate location 
        float CameraY;              // Variable used to store the Camera Y coordinate location 
        Camera2D CameraPosition;    // Variable used to store the Camera2D Camera object as a whole.

        Rectangle *BlockedLocations;   // Array holds ALL locations on CURRENT map that are blocked for player.
        int totalBlockedLocations;     // Total number of blocked locations on current map.

        string UsernameLoggedIn;    // Variable used for storing username currently logged in game client.
};

#endif