/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#include "api.hpp"

/*************************************************************
 * This function is used as a callback function to help 
 * allocate memory being sent to the server. This function will
 * return the size of the memory allocated to be used with the
 * data being sent. This function will be used when setting the
 * curl_easy_opt CURLOPT_WRITEFUNCTION with this function as 
 * its callback. Afterwards the data allocated for will get
 * passed to the CURLOPT_WRITEDATA curl_easy_opt setting to
 * complete the necessary action of allocating memory.
 *************************************************************/
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp){
  
  size_t realSize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = (char *) realloc(mem->memory, mem->size + realSize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realSize);
  mem->size += realSize;
  mem->memory[mem->size] = 0;
 
  return realSize;
};

/*************************************************************
 * This function is used to globally initialize curl. We must
 * wrap this function, and we cannot include raylib.h and
 * curl.h in the same file because curl.h includes windows.h
 *************************************************************/
void CurlGlobalInit(void) {
    curl_global_init(CURL_GLOBAL_ALL);
};

/*************************************************************
 * This function is used to globally cleanup curl. We must
 * also wrap this function, for the same reason as above.
 *************************************************************/
void CurlGlobalCleanup(void) {
    curl_global_cleanup();
};

/*************************************************************
 * This function will allow an account to be created using
 * curl to make an HTTP POST request from the C++ game client
 * to the node js web server. The passed json object will be
 * converted into a string before being sent to the server.
 *************************************************************/
// json CurlCreateAccount(json registration) {
    
//     CURL *curl = curl_easy_init();       // Initialization
//     CURLcode result;

//     MemoryStruct chunk;
//     chunk.memory = (char*) malloc(1);
//     chunk.size = 0;

//     /*******************************************************************************************/
//     /***********************************************
//      * This is for debugging purposes only.
//     ***********************************************/
//     std::cout << registration << std::endl << std::endl;                   // Output json object.
//     std::cout << registration.dump() << std::endl << std::endl;            // Output dumped json object.
//     std::cout << "is String? " << registration.is_string() << std::endl;   // Find out if json object is a string.
//     std::cout << "is object?" << registration.is_object() << std::endl;    // Find out if json object is an object.

//     std::string dataForSending = json::parse(registration);      // Parse json object into a string.
//     std::cout << dataForSending << std::endl;             // Output parsed contents.

//     dataForSending = json::parse(registration).dump();   // Parse json object and dump json object into a string.
//     std::cout << dataForSending << std::endl;            // Output parsed dumped contents as a string.

//     dataForSending = registration.dump();               // Dump json object into a string.
//     std::cout << dataForSending << std::endl;           // Output parsed dumped contents as a string.
//     /***********************************************
//      * End of debugging code block.
//     ***********************************************/
//     /*******************************************************************************************/

//     if(!curl){
//         std::cout << "\nError initializing curl!\n\n";
//     }
    
//     curl_slist *headers = NULL;
//     headers = curl_slist_append(headers, "Accept: application/json");
//     headers = curl_slist_append(headers, "Content-Type: application/json; charset=utf-8");

//     // Set options
//     curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/users");
//     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); 
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dataForSending.c_str());
//     /* send all data to this function  */
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
//     /* we pass our 'chunk' struct to the callback function */
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

//     // Perform action
//     result = curl_easy_perform(curl);

//     // Output a message if something went wrong!
//     if(result != CURLE_OK){
//         std::cout << "\nURL Downloading issue. -- " << curl_easy_strerror(result) << std::endl << std::endl;
//     };

//     // Output the data received back from the server (RAW FORMAT).
//     std::cout << "Data Received is: " << chunk.memory << std::endl;
//     std::cout << "Data Size is: " << chunk.size << std::endl << std::endl;

//     /*******************************************************************************************/
//     /*********************************************************************
//      * Nested function to convert a char* into a referenced json object.   // DEBUGGING PURPOSES
//     *********************************************************************/
//     void to_json(json& jsonOBJECT, char*& charOBJECT) {
//         jsonOBJECT = json::parse(charOBJECT);
//     };
//     json receivedData;
//     to_json(receivedData, chunk.memory);
//     std::cout << receivedData << std::endl;  // Output the json object.

//     std::string data(chunk.memory, chunk.size);
//     std::cout << data << std::endl;
//     /*******************************************************************************************/

//     curl_easy_reset(curl);     // reset easy options
//     curl_easy_cleanup(curl);   // always clean up curl

//     // Return whats sent back from server.
//     return receivedData;
// };


// /*************************************************************
//  * This function is used to to login a user into the game. Two
//  * string variables are passed by value to create a json
//  * encoded concatenated string to send to the server to check
//  * if a user exist. The server will send a string back, which
//  * will be converted into a string before having that strings
//  * memory address returned.
//  *************************************************************/
// json CurlLoginAccount(json login) {
    
//     CURL *curl = curl_easy_init();       // Initialization
//     CURLcode result;

//     MemoryStruct chunk;
//     chunk.memory = (char*) malloc(1);
//     chunk.size = 0;

//     /*******************************************************************************************/
//     /***********************************************
//      * This is for debugging purposes only.
//     ***********************************************/
//     std::cout << login << std::endl << std::endl;                   // Output json object.
//     std::cout << login.dump() << std::endl << std::endl;            // Output dumped json object.
//     std::cout << "is String? " << login.is_string() << std::endl;   // Find out if json object is a string.
//     std::cout << "is object?" << login.is_object() << std::endl;    // Find out if json object is an object.

//     std::string dataForSending = json::parse(login);    // Parse json object into a string.
//     std::cout << dataForSending << std::endl;           // Output parsed contents.

//     dataForSending = json::parse(login).dump();   // Parse json object and dump json object into a string.
//     std::cout << dataForSending << std::endl;     // Output parsed dumped contents as a string.

//     dataForSending = login.dump();               // Dump json object into a string.
//     std::cout << dataForSending << std::endl;    // Output parsed dumped contents as a string.
//     /***********************************************
//      * End of debugging code block.
//     ***********************************************/
//     /*******************************************************************************************/

//     if(!curl){
//         std::cout << "\nError initializing curl!\n\n";
//     }
    
//     curl_slist *headers = NULL;
//     headers = curl_slist_append(headers, "Accept: application/json");
//     headers = curl_slist_append(headers, "Content-Type: application/json; charset=utf-8");

//     // Set options
//     curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/users");
//     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); 
//     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, login.dump().c_str());
//     /* send all data to this function  */
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
//     /* we pass our 'chunk' struct to the callback function */
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

//     // Perform action
//     result = curl_easy_perform(curl);

//     // Output a message if something went wrong!
//     if(result != CURLE_OK){
//         std::cout << "\nURL Downloading issue. -- " << curl_easy_strerror(result) << std::endl << std::endl;
//     };

//     // Output the data received back from the server (RAW FORMAT).
//     std::cout << "Data Received is: " << chunk.memory << std::endl;
//     std::cout << "Data Size is: " << chunk.size << std::endl << std::endl;

//     /*******************************************************************************************/
//     /********************************************************************
//      * Nested function to convert a char* into a referenced json object.   // DEBUGGING PURPOSES
//     ********************************************************************/
//     void to_json(json& jsonOBJECT, char*& charOBJECT) {
//         jsonOBJECT = json::parse(charOBJECT);
//     };
//     json receivedData;
//     to_json(receivedData, chunk.memory);
//     std::cout << receivedData << std::endl;  // Output the json object.

//     std::string data(chunk.memory, chunk.size);
//     std::cout << data << std::endl;
//     /*******************************************************************************************/

//     curl_easy_reset(curl);     // reset easy options
//     curl_easy_cleanup(curl);   // always clean up curl

//     // Return whats sent back from server.
//     return receivedData;
// };