/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#include "Map.hpp"

/*************************************************************
 * This is the default constructor function for the map class.
 * This function will initialize all the attributes needed for
 * the map object to be initialized. 
 *************************************************************/
Map::Map() {
    this->MainTown = LoadTexture("resources/Maps/Main-Town/v1/Main-Town.png");
    this->NorthMainTown = LoadTexture("resources/Maps/Main-Town/v1/North-Main-Town.png");
    this->CurrentMapTexture = MainTown;
    this->CurrentBounds = MAIN_TOWN;

    this->LoadMapProperties = true;
    this->inputFileName = "resources/Maps/Main-Town/v1/Main-Town.txt";
    this->binaryDigit = 0;

    this->totalBlockedLocations = 0;

}


/*************************************************************
 * This is the destructor class function for the map class.
 * This function will get called when the map object goes out
 * of scope.
 *************************************************************/
Map::~Map(){

}


/*************************************************************
 * This is a helper function for reading in blocked locations
 * from an input file. The function will check to ensure that 
 * all ones and zeros have been read from the file and nothing
 * else. A negative 1 will be returned otherwise.
 *************************************************************/
int Map::LocationsFromFile(int binaryDigit){
    int result;
    if(binaryDigit == 0 || binaryDigit == 1){
        result = binaryDigit;
    } else {
        result = -1;
    }
    return result;
}


/*************************************************************
 * This is the Map class function for loading the current maps
 * properties. This function will read from an input file for
 * the current map a bunch of 1s and 0s. 1s are for blocked 
 * locations and 0s are for free'd locations. After the integer
 * array has been read-in, A Rectangle type array will be 
 * created using the numbers from the file and multiples of 32
 * since 32x32 is each pixel tile size. Afterward the 
 * LoadMapProperties boolean will be set to false. This function
 * is of type void and does not return anything.
 *************************************************************/
void Map::LoadMapPropertiesForCurrentMap(){
    
    if(LoadMapProperties) {
        // Save Binary Locations to integer array to be used later for creating blocked locations of rec type.
        ifstream inFile;
        inFile.open(inputFileName);
        int rowCounter = 0;
        if (inFile.is_open()) {
            while (inFile) {
                for(int i = 0; i < COL_SIZE; i++){
                    inFile >> binaryDigit;
                    GameMapArray[rowCounter][i] = LocationsFromFile(binaryDigit);
                }
                rowCounter++;
            }
        }
        
        // Display multi-dimensional array to the console for debugging purposes.
        for (int i = 0; i < ROW_SIZE; i++) {
            for (int k = 0; k < COL_SIZE; k++) {
                std::cout << GameMapArray[i][k];
            }
            std::cout << std::endl;
        }

        int recPositionX = 0;
        int recPositionY = 0;
        // Draw blocked locations for the current map.
        for (int i = 0; i < ROW_SIZE; i++) {
            for (int k = 0; k < COL_SIZE; k++) {
                if(GameMapArray[i][k] == 1){
                    //DrawRectangle(recPositionX, recPositionY, 32, 32, RED);
                    BlockedLocations[totalBlockedLocations] = {(float)recPositionX, (float)recPositionY, 32, 32};
                    totalBlockedLocations++;
                }
                recPositionX += 32;
            }
            recPositionX = 0;
            recPositionY += 32;
            
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
    LoadMapPropertiesForCurrentMap();

    // Draw Current map to the screen.
    DrawTexture(this->CurrentMapTexture, 0, 0, WHITE);

}


/*************************************************************
 * This is the Map class function for returning a blocked
 * location from the rectangle type array to main to be sent
 * over to the player object to be used in helping to detect
 * the players collision against the spots not allowed.
 *************************************************************/
Rectangle Map::getBlockedLocation(int index){
    return this->BlockedLocations[index];
}


/*************************************************************
 * This is the Map class function for getting the total number
 * of blocked locations on the current map. This function is
 * of type integer and will return the same data type.
 *************************************************************/
int Map::getTotalBlockedLocations()const{
    return this->totalBlockedLocations;
}


/*************************************************************
 * This is the Map class function for returning the current
 * map boundary to be used in the Game object to control
 * whenever a player has changed to a new map. This function
 * is of type MapBoundary and the current map boundary will
 * be returned.
 *************************************************************/
MapBoundary Map::getMapBoundary()const{
    return this->CurrentBounds;
}


/*************************************************************
 * This is the Map class function for setting the map
 * boundary for the current map. This function takes in one
 * parameter of type MapBoundary to set the current maps
 * boundary.
 *************************************************************/
void Map::setMapBoundary(MapBoundary boundary){
    this->CurrentBounds = boundary;
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
    if(mapName == "MainTown"){
        this->CurrentMapTexture = MainTown;
    } else if(mapName == "NorthMainTown"){
        this->CurrentMapTexture = NorthMainTown;
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
    this->LoadMapProperties = true;
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

