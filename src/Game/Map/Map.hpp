/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#ifndef MAP_H
#define MAP_H

// System Libraries
#include <iostream>
#include <fstream>
#include <string>
using std::fstream;
using std::string;
using namespace std;

// User Libraries

// External Libraries
#include "raylib.h"

// Created enum type for map boundaries.
enum MapBoundary {
    NONE,
    MAIN_TOWN,
    NORTH_MAIN_TOWN,
};

const int ROW_SIZE = 25;                  // CONST - Used to set the row size of the game map array.
const int COL_SIZE = 25;                  // CONST - Used to set the column size of the game map array.
const int TOTAL_BLOCKED_LOCATIONS = 625;  // CONST - Used to set the total number of blocked locations on the map.

/*************************************************
* Class Map
*************************************************/
class Map {
    public:
        /*************************************************
        * Default Constructor
        * No parameters
        *************************************************/
        Map();

        /*************************************************
        * Destructor
        * No parameters
        *************************************************/
        ~Map();

        /*************************************************
        * This is the Map class function for drawing the
        * current map and all of its needed contents to 
        * the screen and ready to be handled when certain
        * events are triggered. This function is of type
        * void and does not return anything.
        *************************************************/
        void DrawCurrentMap();

        /*************************************************
        * This is the Map class function for getting the
        * blocked rectangle locations from the map to be
        * sent to the player object from main to be used
        * for collision detection against the player. This
        * function is of type Rectangle and will return
        * one index value at a time.
        *************************************************/
        Rectangle getBlockedLocation(int index);

        /*************************************************
        * This is the function for getting the total number
        * of blocked locations on the current map. This
        * function is read-only and will return type
        * integer.
        *************************************************/
        int getTotalBlockedLocations()const;

        /*************************************************
        * This is the Map class function for getting the
        * current maps boundary. This function is of type
        * MapBoundary and the map current map boundary
        * will be returned.
        *************************************************/
        MapBoundary getMapBoundary()const;

        /*************************************************
        * This is the Map class function for setting the
        * maps boundary. This function takes in one
        * parameter which is of type MapBoundary to set 
        * the current boundary.
        *************************************************/
        void setMapBoundary(MapBoundary boundary);

        /*************************************************
        * This is the Map class function for setting the
        * current maps background texture. This function
        * is needed upon game loading to load a new map
        * texture if the player isn't on the default
        * starting map anymore. This function uses a string
        * passed as a parameter to determine when map
        * texture to use as the current texture.
        *************************************************/
        void setCurrentMap(string mapName);

        /*************************************************
        * This is the Map class function for turning the
        * loadMapProperties boolean to true to allow a
        * map reload whenever the player has changed maps.
        * This function is of type void and does not 
        * return anything.
        *************************************************/
        void TurnLoadMapPropertiesOn();

        /*************************************************
        * This is the Map class function for setting the
        * input file name for the current map. This 
        * function should be called upon a map switch.
        * This function is of type void and does not return
        * anything.
        *************************************************/
        void setInputFileName(string FileName);

    private:
        /*************************************************
        * This is the PRIVATE Map class function for
        * loading the current properties needed for the
        * current game map. This function will be used
        * within the Map object. This function is of type
        * void and does not return anything.
        *************************************************/
        void LoadMapPropertiesForCurrentMap();

        /*************************************************
        * This is the PRIVATE class function for checking
        * what the number read from the input file is. 
        * The function will return the binary digit from
        * the input file if the number is a 1 or 0. Zero
        * is for a free'd location and the number One is
        * for a Blocked Location. This function will return
        * a negative 1 if any other value is received.
        *************************************************/
        int LocationsFromFile(int binaryDigit);
        
        Texture2D MainTown;             // Image/Texture for the map pertaining to Main Village.
        Texture2D NorthMainTown;        // Image/Texture for the map pertaining to Main Village North.
        Texture2D CurrentMapTexture;    // Image/Texture for current map.

        MapBoundary CurrentBounds;      // Used to determine what is drawn to screen currently.

        string inputFileName;           // Variable used interchangeably for inputting map data from a file.
        bool LoadMapProperties;         // Variable used to determine whether to load map properties (ONCE per map).
        int binaryDigit;                // Variable used as an aide in checking if the proper number is read-in.

        int GameMapArray[ROW_SIZE][COL_SIZE];                 // Array of type integer, storing 1's and 0's from input file.
        Rectangle BlockedLocations[TOTAL_BLOCKED_LOCATIONS];  // Rectangle array holding blocked locations from using integer game array.
        int totalBlockedLocations;                            // Total number of blocked locations for current map.
};

#endif