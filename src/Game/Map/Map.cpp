/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#include "Map.hpp"

/********************************
 * Default Constructor
 *******************************/
Map::Map() {
    this->mainTown = LoadTexture("resources/Maps/Main-Town/v2/Main-Town.png");
    this->northMainTown = LoadTexture("../../../resources/Maps/");
    this->currentMapTexture = mainTown;

    this->currentBounds = MAIN_TOWN;
    this->inputFileName = "../../../resources/Maps/Main-Town/v2/Main-Town.txt";
    this->loadMapProperties = true;
    this->binaryDigit = -1;
    this->mapRowSize = 25;
    this->mapColSize = 25;
    this->tileSize = 32;

    this->mapLocation = new MapLocation;


};


/******************************
 * 
 ****************************/
Map::~Map(){
    UnloadTexture(this->mainTown);
    UnloadTexture(this->northMainTown);
    delete this->mapLocation;
};

/******************************
 * 
 ****************************/
int Map::LocationsFromFile(int binaryDigit){
    int result;
    if(binaryDigit == 0 || binaryDigit == 1){
        result = binaryDigit;
    } else {
        result = -1;
    }
    return result;
};


/******************************
 * 
 ****************************/
void Map::LoadMapPropertiesForCurrentMap(){
    
    if(loadMapProperties) {
        // Save Binary Locations to integer array to be used later for creating blocked locations of rec type.
        fstream::ifstream inFile;
        inFile.open(inputFileName);
        int rowCounter = 0;
        if (inFile.is_open()) {
            while (inFile) {
                for(int i = 0; i < mapColSize; i++){
                    inFile >> binaryDigit;
                    **currentMapArray[rowCounter][i] = LocationsFromFile(binaryDigit);
                }
                rowCounter++;
            }
        }
        
        // Display multi-dimensional array to the console for debugging purposes.
        for (int i = 0; i < this->mapRowSize; i++) {
            for (int k = 0; k < mapColSize; k++) {
                std::cout << *currentMapArray[i][k];
            }
            std::cout << std::endl;
        }

        int recPositionX = 0;
        int recPositionY = 0;

        // Draw blocked locations for the current map.
        for (int i = 0; i < this->mapRowSize; i++) {
            for (int k = 0; k < this->mapColSize; k++) {
                if(*GameMapArray[i][k] == 1){
                    //DrawRectangle(recPositionX, recPositionY, 32, 32, RED);
                    this->*blockedLocations = {(float)recPositionX, (float)recPositionY, 32, 32};
                    totalBlockedLocations++;
                }
                recPositionX += this->mapTileWidth;
            }
            recPositionX = 0;
            recPositionY += this->tileSize;
            
        }
        // Set to false to only load once.
        LoadMapProperties = false;
    }

}


/*************************************************************
 * This is the Map class function for drawing the current map
 * to the screen. This function should be called in main, and
 * this function is of type void and does not return anything.
 *************************************************************/
void Map::DrawCurrentMap(){

    // Call function to load properties for current map.
    setInputFileName("../../../resources/Maps/Main-Town/v2/Main-Town.txt");
    LoadMapPropertiesForCurrentMap();
    // Draw Current map to the screen.
    this->currentMapTexture = mainTown;
    this->currentBounds = MAIN_TOWN;
    DrawTexture(this->currentMapTexture, 0, 0, WHITE);
    
    // Draw Player here...

    setInputFileName("../../../resources/Maps/North-Main-Town/v1/North-Main-Town.txt");
    LoadMapPropertiesForCurrentMap();
    this->currentMapTexture = northMainTown;
    this->currentBounds = NORTH_MAIN_TOWN;
    // DrawTexture(this->currentMapTexture, 0, 0, WHITE);
    ClearBackground(GREEN);
};


/*************************************************************
 * This is the Map class function for returning a blocked
 * location from the rectangle type array to main to be sent
 * over to the player object to be used in helping to detect
 * the players collision against the spots not allowed.
 *************************************************************/
Rectangle Map::getBlockedLocation(int index){

    return blockedLocations[index].mapLocationsRec;
}


/*************************************************************
 * This is the Map class function for getting the total number
 * of blocked locations on the current map. This function is
 * of type integer and will return the same data type.
 *************************************************************/
int Map::getTotalBlockedLocations(){
    return this->totalBlockedLocations;
}


/*************************************************************
 * This is the Map class function for returning the current
 * map boundary to be used in the Game object to control
 * whenever a player has changed to a new map. This function
 * is of type MapBoundary and the current map boundary will
 * be returned.
 *************************************************************/
MapBoundary Map::getMapBoundary(){
    return this->currentBounds;
}


/*************************************************************
 * This is the Map class function for setting the map
 * boundary for the current map. This function takes in one
 * parameter of type MapBoundary to set the current maps
 * boundary.
 *************************************************************/
void Map::setMapBoundary(MapBoundary boundary){
    this->currentBounds = boundary;
}


/*************************************************************
 * This is the Map class function for setting the current
 * maps background texture/image. This function uses a string 
 * passed as a parameter to set the corresponding map with
 * the proper map texture. This function is need when loading
 * the game for the player and if the player isn't on the
 * default starting map anymore. This function is of type void
 * and does not return anything.
 *************************************************************/
void Map::setCurrentMap(string mapName){
    if(mapName == "mainTown"){
        this->currentMapTexture = mainTown;
        this->currentBounds = MAIN_TOWN;
    } else if(mapName == "northMainTown"){
        this->currentMapTexture = northMainTown;
        this->currentBounds = NORTH_MAIN_TOWN;
    } else {
        this->currentBounds = NONE;
        cout << "\nSomething went wrong with setting the current map." << endl;
    }
}

/*************************************************************
 * This is the Map class function for turning the map
 * properties boolean variable to true, to load the map
 * properties with the current needed data. The boolean will be
 * automatically set to false after loading the map properties.
 * This function is of type void and does not return anything.
 *************************************************************/
void Map::TurnLoadMapPropertiesOn(){
    this->loadMapProperties = true;
}


/*************************************************************
 * This is the Map class function for setting the input file
 * name for the current map. This map file is needed to know
 * where the blocked locations for the current map are. This
 * function is of type void and does not return anything.
 *************************************************************/
void Map::setInputFileName(string fileName){
    this->inputFileName = fileName;
}

