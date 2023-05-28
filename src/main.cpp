/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "main.hpp"

int main(int argc, char* argv[])
{
    // Get the current working directory
    //--------------------------------------------------------------------------------------

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

    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(1280, 700, "Savages-Online | Version 0.0.1");


    GameStates gameState = LOADING_SCREEN;

    /**************************************************
     * Object/Class Initialization
    ***************************************************/
    Game *savages = new Game;
    LoadingScreen *loadingScreen = new LoadingScreen;
    loadingScreen->setBackgroundTexture(Texture2D{});
    MainMenuScreen *mainMenuScreen;

    /**************************************************
     * Variable Initialization
     ***************************************************/
    bool showOnce = true;

    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(GRAY);

        switch(gameState){
            case LOADING_SCREEN:
                loadingScreen->DrawScreen();
                break;
            case MAIN_MENU_SCREEN:
                mainMenuScreen->DrawScreen(); 
                break;
            default:
                std::cout << "ERROR: Invalid Game State" << std::endl;
                break;
        }
        
        if(showOnce){
            savages->printContributors();
            showOnce = false;
        }
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

