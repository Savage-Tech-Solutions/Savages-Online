/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "main.hpp"

int main(int argc, char* argv[]) {

    /**************************************************
     * Get Current Working Directory
     ***************************************************/
    char path_save[1024];
    char cwd[1024];
    char* p;
    if(!(p = strrchr(argv[0], '/')))
        getcwd(cwd, sizeof(cwd));
    else
    {
        *p = '\0';
        getcwd(path_save, sizeof(path_save));
        chdir(argv[0]);
        getcwd(cwd, sizeof(cwd));
        chdir(path_save);
    }
    string NEW_WORKING_DIR = string(cwd) + "/";
    chdir(NEW_WORKING_DIR.c_str());

    /**************************************************
     * Window Initialization
     ***************************************************/
    InitWindow(1280, 700, "Savages-Online | Version 0.0.1");

    /**************************************************
     * Object/Class Initialization
    ***************************************************/
    Game *savages = new Game;

    /**************************************************
     * Variable Initialization
     ***************************************************/
    bool showOnce = true;
    bool isGameRunning = true;
    CurrentGameState *gameState = new CurrentGameState;
    *gameState = EXIT_SCREEN;

    // Set Target FPS
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose() && isGameRunning){

        BeginDrawing();

        ClearBackground(GRAY);
        
        isGameRunning = savages->run(gameState);
        
        EndDrawing();
        
        // Testing functiom printContributors()
        if(showOnce){
            savages->printContributors();
            showOnce = false;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}