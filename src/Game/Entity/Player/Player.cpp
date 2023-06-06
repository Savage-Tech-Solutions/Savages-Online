/* ************************************************************
 * PROGRAMMER  : Bryce Berwald
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : A multiplayer RPG game created with C++ and
 * a gaming library called "raylib". This game is being built to
 * help my overall understanding of the C++ programming language,
 * and for my own fun along the way.
 **************************************************************/

#include "Player.hpp"

/*************************************************************
 * This is the default constructor for the Player class. This
 * function will initialize all the attributes associated with
 * the player.
 *************************************************************/
Player::Player(){
    this->HumanSpriteSheet = LoadTexture("../resources/Spritesheets/human_spritesheet.png");
    this->DemonSpriteSheet = LoadTexture("../resources/Spritesheets/demon_spritesheet.png");
    this->CurrentSpriteSheet = HumanSpriteSheet;

    this->FrameX = (float)CurrentSpriteSheet.width/8;
    this->FrameY = (float)CurrentSpriteSheet.height/8;
    this->frameRec = { 0.0f, 0.0f, this->FrameX, this->FrameY };

    this->firstMovementKeyPressed = "NONE";
    this->walkingMode = false;
    this->walkingAnimationTimer = 0;

    this->attackMode = false;
    this->attackAnimationTimer = 0;

    this->PlayerX = GetScreenWidth() / 2 - 16;
    this->PlayerY = 200;
    this->PlayerDirection = 'S';
    this->PlayerPosition = {(float)this->PlayerX, (float)this->PlayerY};

    this->CameraX = 670;
    this->CameraY = 190;
    this->CameraPosition = {{ this->CameraX, this->CameraY }, { this->CameraX, this->CameraY }, 0.0f, 2.5f };

    this->totalBlockedLocations = 0;

    this->PlayerSurroundingRec = {(float)PlayerX+24, (float)PlayerY+16, 14, 28};
}


/*************************************************************
 * This is the destructor for the Player class. This function
 * will get called when the Player class goes out of scope.
 *************************************************************/
Player::~Player(){

}


/*************************************************************
 * This class function will draw the current player to the
 * screen with handled logic to be called as well to update
 * the current state of the player. This function should be
 * called in main. This function is of type void and does not
 * return anything.
 *************************************************************/
void Player::DrawPlayer(){

    // Call function to handle all logic associated with player.
    HandlePlayerLogic();

    // Call function to draw current state of player to the screen.
    DrawTextureRec(this->CurrentSpriteSheet, this->frameRec, {(float)PlayerX, (float)PlayerY}, WHITE);
    
    // Create rectangle around the player.
    // DrawRectanglePro(PlayerSurroundingRec, {0,0}, 0.0f, Fade(RED, 0.5f));

}


/*************************************************************
 * This function is for returning the Camera of Camera2D type.
 * This camera will be needed in main to display the camera.
 *************************************************************/
Camera2D Player::getCamera()const{
    return CameraPosition;
}


/*************************************************************
 * This is the Player class function for setting the blocked
 * locations on the map for the blocked using the passed array
 * as a parameter. This function is of type void and does not
 * return anything.
 *************************************************************/
void Player::setBlockedLocations(Rectangle recArr[], const int MAX_SIZE){
    for(int i = 0; i < MAX_SIZE; i++){
        this->BlockedLocations[i] = recArr[i];
    }
}


/*************************************************************
 * This is the function for setting the total number of
 * blocked locations for the player, which was calculated in
 * the Player class. This function is of type void and does
 * not return anything.
 *************************************************************/
void Player::setTotalBlockedLocations(int numberOfLocations){
    this->totalBlockedLocations = numberOfLocations;
}


/*************************************************************
 * This is the Player class function for getting the Player's
 * 'x' coordinate location. Will need in future classes to pin
 * point collisions against NPCs, etc. This function is of
 * type integer and will return a integer.
 *************************************************************/
int Player::getPlayerX()const{
    return this->PlayerX;
}


/*************************************************************
 * This is the class function for getting the Player's 'y'
 * coordinate location. Will need later to pin point the
 * players location for game content/collisions against NPCs.
 * This function is of type integer and will return the same.
 *************************************************************/
int Player::getPlayerY()const{
    return this->PlayerY;
}


/*************************************************************
 * This is the class function for getting the players current
 * direction. This function is of type char and will be 
 * returned the same data type.
 *************************************************************/
char Player::getPlayerDirection()const{
    return this->PlayerDirection;
}


/*************************************************************
 * This is the Player class function for getting the player's
 * position. This function is of type Vector2 holding the (x,y)
 * location of the player and will be returned as a Vector2.
 *************************************************************/
Vector2 Player::getPlayerPosition()const{
    return this->PlayerPosition;
}


/*************************************************************
 * This is the Player class function for getting the camera
 * 'x' coordinate that follows the player. This function is
 * of type floating point and will be returned as the same 
 * data type.
 *************************************************************/
float Player::getCameraX()const{
    return this->CameraX;
}


/*************************************************************
 * This is the class function for getting the cameras 'y'
 * coordinate location that follows the player. This function
 * is of type floating point and the same data type value will
 * be returned the same.
 *************************************************************/
float Player::getCameraY()const{
    return this->CameraY;
}


/*************************************************************
 * This is the class function for getting the players
 * surrounding rectangle to be used for collision checking.
 * This function is of type void and nothing is returned.
 *************************************************************/
Rectangle Player::getPlayerSurroundingRec()const{
    return this->PlayerSurroundingRec;
}


/*************************************************************
 * This is the Player class function for setting the 'x'
 * coordinate position for the player. One parameter is passed
 * and nothing is returned.
 *************************************************************/
void Player::setPositionX(int x){
    this->PlayerX = x;
}


/*************************************************************
 * This is the Player class function for setting the players
 * 'y' coordinate location. One parameter is passed and nothing
 * is returned.
 *************************************************************/
void Player::setPositionY(int y){
 this->PlayerY = y;
}


/*************************************************************
 * This is the Player class function for setting the players
 * direction. One parameter is passed (char) and nothing is
 * returned.
 *************************************************************/
void Player::setPlayerDirection(char direction){
    this->PlayerDirection = direction;
}


/*************************************************************
 * This is the Player class function for setting the camera
 * 'x' coordinate location. This function has one parameter
 * being passed and is of type void, so nothing is returned.
 *************************************************************/
void Player::setCameraX(float x){
    this->CameraX = x;
}


/*************************************************************
 * This is the Player class function for setting the players
 * 'y' coordinate location. This function has one parameter
 * passed and does not return anything as it's type void.
 *************************************************************/
void Player::setCameraY(float y){
    this->CameraY = y;
}


/*************************************************************
 * This is the class function for setting the frame x position
 * for the sprite sheets used by the player. This function is
 * of type void and does not return anything.
 *************************************************************/
void Player::setFrameX(float x){
    this->FrameX = x;
}


/*************************************************************
 * This is the class function for setting the frame y position
 * for the sprite sheets used by the player. This function is
 * of type void and does not return anything.
 *************************************************************/
void Player::setFrameY(float y){
    this->FrameY = y;
}


/*************************************************************
 * This PRIVATE class function is for handing the walking
 * movements associated with the player. Depending on the first
 * movement key pressed and if the movement key has been
 * released, etc. This function will keep the moving state of
 * player walking in check. This function is of type void and
 * does not return anything.
 *************************************************************/
void Player::HandlePlayerWalking(){

    // Variables used to help support collision detection against player.
    int new_PlayerX = PlayerX;
    int new_PlayerY = PlayerY;
    int new_CameraX = CameraX;
    int new_CameraY = CameraY;
    
    // Reset movement key pressed to a starting value of 'NONE'.
    this->firstMovementKeyPressed = "NONE";
    
    // Make sure one of the player movement keys is being pressed before proceeding.
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN)) {

        // Update sprite sheet frameRec to fit player walking animations.
        FrameX = (float)CurrentSpriteSheet.width/8;
        FrameY = (float)CurrentSpriteSheet.height/4;

        // Change players current direction when necessary.
        if(IsKeyDown(KEY_LEFT)){
            this->PlayerDirection = 'W';
        } else if(IsKeyDown(KEY_RIGHT)){
            this->PlayerDirection = 'E';
        } else if(IsKeyDown(KEY_UP)){
            this->PlayerDirection = 'N';
        } else if(IsKeyDown(KEY_DOWN)){
            this->PlayerDirection = 'S';
        }

        // Find the first movement key pressed to be used for player walking only.
        if (firstMovementKeyPressed != "NONE") {
            if (firstMovementKeyPressed == "RIGHT" && !IsKeyDown(KEY_RIGHT)) {
                firstMovementKeyPressed = "NONE";
            }
            if (firstMovementKeyPressed == "LEFT" && !IsKeyDown(KEY_LEFT)) {
                firstMovementKeyPressed = "NONE";
            }  
            if (firstMovementKeyPressed == "UP" && !IsKeyDown(KEY_UP)) {
                firstMovementKeyPressed = "NONE";
            }  
            if (firstMovementKeyPressed == "DOWN" && !IsKeyDown(KEY_DOWN)) {
                firstMovementKeyPressed = "NONE";
            }   
        } else {
            if (IsKeyDown(KEY_RIGHT)) {
                firstMovementKeyPressed = "RIGHT";
                this->walkingMode = true;
            } else if (IsKeyDown(KEY_LEFT)) {
                firstMovementKeyPressed = "LEFT";
                this->walkingMode = true;
            } else if (IsKeyDown(KEY_UP)) {
                firstMovementKeyPressed = "UP";
                this->walkingMode = true;
            } else if (IsKeyDown(KEY_DOWN)) {
                firstMovementKeyPressed = "DOWN";
                this->walkingMode = true;
            }
        }
    }

    // Check if player is currently walking for animations.
    if(this->walkingMode){
        walkingAnimationTimer++;
        if(walkingAnimationTimer > 5){
            if(firstMovementKeyPressed == "LEFT"){
                frameRec.x += 64;
                frameRec.y = 448;
            } else if(firstMovementKeyPressed == "RIGHT"){
                frameRec.x += 64;
                frameRec.y = 384;
            } else if(firstMovementKeyPressed == "UP"){
                frameRec.x += 64;
                frameRec.y = 320;
            } else if(firstMovementKeyPressed == "DOWN"){
                frameRec.x += 64;
                frameRec.y = 256;
            }

            if(frameRec.x >= 320){
                frameRec.x = 0;
            }

            walkingAnimationTimer = 0;
        }
    }
    
    // If any movement key is released, set sprite sheet frames to standing still.
    if(IsKeyReleased(KEY_LEFT) || !this->walkingMode && this->PlayerDirection == 'W' ){
        frameRec.x = 0;
        frameRec.y = 192;
    } else if(IsKeyReleased(KEY_RIGHT) || !this->walkingMode && this->PlayerDirection == 'E' ){
        frameRec.x = 0;
        frameRec.y = 128;
    } else if(IsKeyReleased(KEY_UP) || !this->walkingMode && this->PlayerDirection == 'N' ){
        frameRec.x = 0;
        frameRec.y = 64;
    } else if(IsKeyReleased(KEY_DOWN) || !this->walkingMode && this->PlayerDirection == 'S' ){
        frameRec.x = 0;
        frameRec.y = 0;
    }

    /* Check Keyboard Input from Player for horizontal movement 
    if the player pressed anything, change the new_PlayerX and new_CameraX variables */
    if (firstMovementKeyPressed == "RIGHT") {
        new_CameraX += 5;
        PlayerDirection = 'E';
        new_PlayerX += 3;
    } 
    if (firstMovementKeyPressed == "LEFT") {
        new_CameraX -= 5;
        PlayerDirection = 'W';
        new_PlayerX -= 3;
    } 
    this->PlayerSurroundingRec = {(float)new_PlayerX+24, (float)new_PlayerY+16, 14, 28};

    if(firstMovementKeyPressed == "RIGHT"){
        /* Now change if we are colliding with anything, if yes, go back to the last "safe" position, if not, go there */
        for (int i = 0; i < totalBlockedLocations; i++) {
            if (CheckCollisionRecs(BlockedLocations[i], this->PlayerSurroundingRec)) {
                new_PlayerX = PlayerX;
                new_CameraX = CameraX;
            }
        }
        PlayerX = new_PlayerX;
        CameraX = new_CameraX;
    } else if (firstMovementKeyPressed == "LEFT"){
        /* Now change if we are colliding with anything, if yes, go back to the last "safe" position, if not, go there */
        for (int i = 0; i < totalBlockedLocations; i++) {
            if (CheckCollisionRecs(BlockedLocations[i], this->PlayerSurroundingRec)) {
                new_PlayerX = PlayerX;
                new_CameraX = CameraX;
            }
        }
        PlayerX = new_PlayerX;
        CameraX = new_CameraX;
    }

    /* Check Keyboard Input from Player for vertical movement 
    if the player pressed anything, change the new_PlayerY and new_CameraY variables */
    if(firstMovementKeyPressed == "UP") {
        new_CameraY -= 5;
        PlayerDirection = 'N';
        new_PlayerY -= 3;
    } 
    if (firstMovementKeyPressed == "DOWN") {
        new_CameraY += 5;
        PlayerDirection = 'S';
        new_PlayerY += 3;
    }
    this->PlayerSurroundingRec = {(float)new_PlayerX+24, (float)new_PlayerY+16, 14, 28};

    if(firstMovementKeyPressed == "UP"){
        /* Now change if we are colliding with anything, if yes, go back to the last "safe" position, if not, go there */
        for (int i = 0; i < totalBlockedLocations; i++) {
            if (CheckCollisionRecs(BlockedLocations[i], this->PlayerSurroundingRec)) {
                new_PlayerY = PlayerY;
                new_CameraY = CameraY;
            }
        }
        PlayerY = new_PlayerY;
        CameraY = new_CameraY;
    } else if (firstMovementKeyPressed == "DOWN"){
        /* Now change if we are colliding with anything, if yes, go back to the last "safe" position, if not, go there */
        for (int i = 0; i < totalBlockedLocations; i++) {
            if (CheckCollisionRecs(BlockedLocations[i], this->PlayerSurroundingRec)) {
                new_PlayerY = PlayerY;
                new_CameraY = CameraY;
            }
        }
        
        PlayerY = new_PlayerY;
        CameraY = new_CameraY;
    }

    // Update the game camera which follows the players location.
    this->CameraPosition = {{ this->CameraX, this->CameraY }, { this->CameraX, this->CameraY }, 0.0f, 2.5f };

    //cout << "\n\nFirst Movement key is... " << this->firstMovementKeyPressed << endl << endl;

}


/*************************************************************
 * This is a PRIVATE class function for handing the attacking
 * movements/animations for the player. This function will
 * check if any attack key is being pressed while a movement
 * key is not being pressed. This function will make the player
 * attack when needed and stop attacking when needed. This
 * function is of type void and does not return anything.
 *************************************************************/
void Player::HandlePlayerAttacking(){
    
    // Before allowing the player to use attack key, make sure player isn't trying to move positions.
    if(!IsKeyPressed(KEY_LEFT) && !IsKeyPressed(KEY_RIGHT) && !IsKeyPressed(KEY_UP) && !IsKeyPressed(KEY_DOWN) 
                               && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)){
        
        // Check if movement key is pressed/down (KEY Z).
        if(IsKeyPressed(KEY_Z) || IsKeyDown(KEY_Z)){
            if(this->PlayerDirection == 'S') {
                this->frameRec.y = 0;
                this->frameRec.x = 64;
                this->attackMode = true;
            } else if(this->PlayerDirection == 'N') {
                this->frameRec.y = 64;
                this->frameRec.x = 64;
                this->attackMode = true;
            } else if(this->PlayerDirection == 'E'){
                this->frameRec.y = 128;
                this->frameRec.x = 64;
                this->attackMode = true;
            }else if(this->PlayerDirection == 'W'){
                this->frameRec.y = 192;
                this->frameRec.x = 64;
                this->attackMode = true;
            }
        }

        // Check if player is attacking to update animated frameRec position.
        if(this->attackMode){
            this->attackAnimationTimer++;
            if(this->attackAnimationTimer >= 15){
                this->frameRec.x = 0;
                this->attackMode = false;
                this->attackAnimationTimer = 0;
            }
        } 

        // Check if player has stopped attacking to reset attack variables.
        if(IsKeyReleased(KEY_Z)){
            this->frameRec.x = 0;
            this->attackMode = false;
            this->attackAnimationTimer = 0;
        }

    }

}


/*************************************************************
 * This PRIVATE class function for the Player will be used to 
 * all of the functions associated with the logic of the player.
 * This function is of type void and does not return anything.
 *************************************************************/
void Player::HandlePlayerLogic(){

    // Call function to handle player attacking.
    HandlePlayerAttacking();

    // Call function to handle player walking.
    HandlePlayerWalking();

}


/*************************************************************
 * This PRIVATE class function for the Player will be used to 
 * set the logged in players username associated with the
 * database. This function is of type void and nothing will be
 * returned.
 *************************************************************/
void Player::setUsernameLoggedIn(string username){
    this->UsernameLoggedIn = username;
}

