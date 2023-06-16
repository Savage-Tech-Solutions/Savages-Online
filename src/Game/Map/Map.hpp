/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#ifndef Map_hpp
#define Map_hpp

// System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using std::fstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

// User Libraries
//#include "Player.hpp"

// External Libraries
#include "raylib.h"

// Created enum type for map boundaries.
enum MapBoundary {
    NONE,
    MAIN_TOWN,
    NORTH_MAIN_TOWN,
};

// Created struct type for map locations.
struct MapLocation {
    int x;
    int y;
    int tileSize;
    Rectangle location;
    bool isBlocked;
    MapLocation *next;
};

/*******************
* Class Map
*******************/
class Map {
    public:
        /********************
        * Default Constructor
        ********************/
        Map();

        /************
        * Destructor
        * ***********/
        ~Map();

        // Drawing Functions (PUBLIC)
        void DrawCurrentMap();
        void DrawMapBoundary();

        // GETTERS (PUBLIC)
        vector<Rectangle> getBlockedLocations();
        int getCurrentAmountBlockedLocations();
        MapBoundary getMapBoundary();
        fstream getInputFileName();

        // SETTERS (PUBLIC)
        void setMapBoundary(MapBoundary boundary);
        void setCurrentMap(int map);
        void setInputFileName(string file);

    private:
        // LOADING FUNCTIONS (PRIVATE)
        void LoadMapPropertiesForCurrentMap();
        int LoadLocationsFromFile(int binaryDigit);        

        // GETTER (PRIVATE)
        MapLocation *&getHeadProperties();
        MapLocation *&getTailProperties();

        // MAP PROPERTIES (PRIVATE) - ON || OFF
        void TurnLoadMapPropertiesOn();
        void TurnLoadMapPropertiesOff();
        
        // Texture2D Variables
        Texture2D mainTown;             // Image/Texture for the map pertaining to Main Village.
        Texture2D northMainTown;        // Image/Texture for the map pertaining to Main Village North.
        Texture2D currentMapTexture;    // Image/Texture for current map.

        // MapBoundary Variables
        MapBoundary mapBoundary;      // Used to determine what is drawn to screen currently.

        // Map variables & whether it's blocked or not.
        string inputFileName;           // Variable used interchangeably for inputting map data from a file.
        bool loadMapProperties;         // Variable used to determine whether to load map properties (ONCE per map).
        int binaryDigit;                // Variable used as an aide in checking if the proper number is read-in.

        // Map Dimensions
        int rowSize;                    // Variable used to keep track of the row size of the map.
        int columnSize;                 // Variable used to keep track of the column size of the map.

        // MapLocation Linked List PTR Variables
        MapLocation *head;              // Pointer to the head of the linked list.
        MapLocation *tail;              // Pointer to the tail of the linked list.

        // Total Blocked Locations on current map.
        int totalBlockedLocations;

};

#endif /* map_hpp */