/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#ifndef map_hpp
#define map_hpp

// System Libraries
#include <iostream>
#include <fstream>
//#include <ifstream>
//#include <ofstream>
#include <string>
#include <vector>
using std::fstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
// using std::ifstream;
// using std::ofstream;
using std::fstream;

// User Libraries
#include "../Entity/Player/Player.hpp"   // NEW INCLUDE ADDED! (06/11/23)

// External Libraries
#include "raylib.h"

// Created enum type for map boundaries.
enum MapBoundary {
    NONE,
    MAIN_TOWN,
    NORTH_MAIN_TOWN,
};


/********************************/
struct MapLocation {
    int x;
    int y;
    int tileSize;
    Rectangle mapLocationsRec = {x, y, tileSize, tileSize};
    bool isBlocked;
};
/********************************/


/*************
* Class Map
*************/
class Map {
    public:
        /**********************
        * Default Constructor
        **********************/
        Map();

        /***********************
        * Destructor
        ***********************/
        ~Map();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void DrawCurrentMap();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        Rectangle getBlockedLocation(int index);

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        int getTotalBlockedLocations();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        MapBoundary getMapBoundary();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void setMapBoundary(MapBoundary boundary);

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void setCurrentMap(string mapName);

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void TurnLoadMapPropertiesOn();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void setInputFileName(string FileName);

    private:
        /*********************************
         * TODO: Finish Documentation
        **********************************/
        void LoadMapPropertiesForCurrentMap();

        /*********************************
         * TODO: Finish Documentation
        **********************************/
        int LocationsFromFile(int binaryDigit);
        
        /*********************************
         * ALL MAP CLASS PRIVATE VARIABLES
        **********************************/
        Texture2D mainTown;             // Texture for the map pertaining to Main Town.
        Texture2D northMainTown;        // Texture for the map pertaining to North Main Town.
        Texture2D currentMapTexture;    // Image/Texture for current map.
        MapBoundary currentBounds;      // Used to determine what map is drawn to screen currently.
        
        string inputFileName;           // Used to set the input file name for the current map.
        
        bool loadMapProperties;         // Used to determine if the map properties should be loaded.
        
        int binaryDigit;                // Used to determine if the location is blocked or not. (0 = not blocked, 1 = blocked) from text file.
        
        int mapRowSize;  // 800 (25x32) or (rowSize *tileSize) for Main Town Map.
        int mapColSize;  // 800 (25x32) or (colSize *tileSize) for Main Town Map.
        
        int tileSize;

        int mapWidth;
        int mapHeight;

        int totalBlockedLocations;

        // int *mapArray;
        // int *currentMapArray;
        // Rectangle *blockedLocations;
        
        vector<int>mapArray;
        vector<int> currentMapArray;
        vector<MapLocation> blockedLocations;


        

};

#endif