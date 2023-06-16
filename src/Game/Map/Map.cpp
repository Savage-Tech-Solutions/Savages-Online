/* ************************************************************
 * PROGRAMMER  : // TODO: Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO: Finish Documentation
 **************************************************************/

#include "Map.hpp"

Map::Map() {
    this->mainTown = LoadTexture("../../../resources/Maps/Main-Town/v1/Main-Town.png");
    this->northMainTown = LoadTexture("../../../resources/Maps/Main-Town/v1/North-Main-Town.png");
    this->currentMapTexture = mainTown;
    this->mapBoundary = MAIN_TOWN;
    this->loadMapProperties = true;
    this->inputFileName = "../../../resources/Maps/Main-Town/v1/Main-Town.txt";
    this->binaryDigit = -1;
    this->rowSize = 25;
    this->columnSize = 25;
    this->head = nullptr;
    this->tail = nullptr;
    this->totalBlockedLocations = 0;
};

Map::~Map(){

};

/*******************************/
      // --- DRAWING --- //
/*******************************/

void Map::DrawCurrentMap(){
    // Call function to load properties for current map.
    LoadMapPropertiesForCurrentMap();
    // Draw Current map to the screen.
    DrawTexture(this->currentMapTexture, 0, 0, WHITE);
};

void Map::DrawMapBoundary(){
    // Draw Map Boundary to the screen.
    if(this->mapBoundary == MAIN_TOWN){
        DrawTexture(this->mainTown, 0, 0, WHITE);
    } else if(this->mapBoundary == NORTH_MAIN_TOWN){
        DrawTexture(this->northMainTown, 0, 0, WHITE);
    } else {
        ClearBackground(BLACK);
    };
};

/*******************************/
      // --- GETTERS --- //
/*******************************/

MapLocation *&Map::getTailProperties(){
    return this->tail;
};

MapLocation *&Map::getHeadProperties(){
    return this->head;
};

vector<Rectangle> Map::getBlockedLocations(){

    // Find total isBlocked locations from the linked list. (MapLocation isBlocked variable)
    vector<Rectangle> recVector;
    for(int i = 0; i < this->totalBlockedLocations; i++){

        if(this->head->isBlocked){
            recVector.push_back(head->location);
        } else {
            this->head = this->head->next;
        };
    };
    this->totalBlockedLocations = recVector.size();
    return recVector;
};

int Map::getCurrentAmountBlockedLocations(){
    return this->totalBlockedLocations;
};

MapBoundary Map::getMapBoundary(){
    return this->mapBoundary;
};

/*******************************/
      // --- SETTERS --- //
/*******************************/

void Map::setMapBoundary(MapBoundary boundary){
    this->mapBoundary = boundary;
};

void Map::setCurrentMap(int map){
    if(map == MAIN_TOWN){
        this->currentMapTexture = mainTown;
    } else if(map == NORTH_MAIN_TOWN){
        this->currentMapTexture = northMainTown;
    } else {
        //this->currentMapTexture = mainTown;
    };
};

void Map::setInputFileName(string file){
    this->inputFileName = file;
};

/*******************************
      // --- LOADERS --- //
********************************/

int Map::LoadLocationsFromFile(int binaryDigit){
    int result;
    if(binaryDigit == 0 || binaryDigit == 1){
        result = binaryDigit;
    } else {
        result = -1;
    };
    return result;
};

void Map::LoadMapPropertiesForCurrentMap(){

    // Create multi-dimensional array to hold binary digits from file. (TEMPORARY)
    int gameMapArray[rowSize][columnSize];

    // Load map properties from file.
    if(loadMapProperties) {
        // Open file for reading.
        fstream inFile;
        inFile.open(this->inputFileName);
        // Read binary digits from file and store them in a multi-dimensional array. (TEMPORARY ARRAY)
        int rowCounter = 0;
        if (inFile.is_open()) {
            while (inFile) {
                for(int i = 0; i < this->columnSize; i++){
                    inFile >> binaryDigit;
                    gameMapArray[rowCounter][i] = LoadLocationsFromFile(binaryDigit);
                };
                rowCounter++;
            };
        };
        // Display multi-dimensional array to the console for debugging purposes. (TEMPORARY ARRAY)
        for (int i = 0; i < this->rowSize; i++) {
            for (int k = 0; k < this->columnSize; k++) {
                std::cout << gameMapArray[i][k];
            };
            std::cout << std::endl;
        };
        // Draw blocked locations (DEBUGGING) for the current map && store them in a linked list.
        int recPositionX = 0;
        int recPositionY = 0;
        for (int i = 0; i < this->rowSize; i++) {
            for (int k = 0; k < this->columnSize; k++) {
                if(gameMapArray[i][k] == 1){  // equals 1
                    
                    // Draw red square (32x32 pixels) over blocked locations.
                    DrawRectangle(recPositionX, recPositionY, 32, 32, RED);
                    
                    MapLocation *tempHead = new MapLocation();
                    if(this->head == nullptr){
                        tempHead->x = recPositionX;
                        tempHead->y = recPositionY;
                        tempHead->tileSize = 32;
                        tempHead->isBlocked = true;
                        tempHead->next = new MapLocation();
                        this->totalBlockedLocations++;

                        // ---tempHead to *head && *tail ---//
                        this->head = tempHead;
                        this->tail = nullptr;
                    } else {
                        while(tail->next != nullptr){
                            tempHead = tempHead->next;
                        };
                        tempHead->x = recPositionX;
                        tempHead->y = recPositionY;
                        tempHead->tileSize = 32;
                        tempHead->isBlocked = true;
                        tempHead->next = new MapLocation();
                        this->totalBlockedLocations++;

                        //--- *tempHead to *tail ---//
                        this->tail = tempHead;
                    };
                    delete tempHead;
                } else {  // equals 0
                    MapLocation *tempHead = new MapLocation();
                    while(head->next != nullptr){
                        tempHead = tempHead->next;
                    };
                    tempHead->x = recPositionX;
                    tempHead->y = recPositionY;
                    tempHead->tileSize = 32;
                    tempHead->isBlocked = false;
                    tempHead->next = new MapLocation();

                    // No need to increment totalBlockedLocations because blocking is false.
                    
                    //--- *tempHead to *tail ---//
                    this->tail = tempHead;
                };
                recPositionX += 32;
            };
            recPositionX = 0;
            recPositionY += 32;
        };
        // Call function to turn off map properties loading. (Prevents infinite loop)
        TurnLoadMapPropertiesOff();
    };
};

/*******************************/
void Map::TurnLoadMapPropertiesOn(){
    this->loadMapProperties = true;
};

/*******************************/
void Map::TurnLoadMapPropertiesOff(){
    this->loadMapProperties = false;
};