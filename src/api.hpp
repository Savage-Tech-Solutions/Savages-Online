/* ************************************************************
 * PROGRAMMER  : // TODO:// Finish Documentation
 * PROJECT     : Savages-Online
 * VERSION     : 0.0.1
 * DESCRIPTION : // TODO:: Finish Documentation
 **************************************************************/

#ifndef api_hpp
#define api_hpp

// System Libraries
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

// User Libraries
// N/A

// External Libraries
#include <curl/curl.h>
#include <curl/easy.h>

// Created struct for memory being allocated.
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Function prototypes for networking with libcurl
static size_t WriteMemoryCallback(char *contents, size_t size, size_t nmemb, void *userp);
void CurlGlobalInit(void);
void CurlGlobalCleanup(void);

#endif /* api_hpp */