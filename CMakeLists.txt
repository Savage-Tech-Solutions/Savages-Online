cmake_minimum_required(VERSION 3.14)

project(Savages-Online)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# RAYLIB LIBRARY
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# CURL LIBRARY
set(CURL_VERSION 7.64.1)
find_package(CURL ${CURL_VERSION} REQUIRED)
if(NOT CURL_FOUND)
  include(FetchContent)
  FetchContent_Declare(
	CURL
	DOWNLOAD_EXTRACT_TIMESTAMP OFF
	URL https://curl.se/download/curl-${CURL_VERSION}.tar.gz
  )
  FetchContent_GetProperties(CURL)
  if (NOT CURL_POPULATED)
  	set(FETCHCONTENT_QUIET NO)
  	FetchContent_Populate(CURL)
	set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
	add_subdirectory(${CURL_SOURCE_DIR} ${CURL_BINARY_DIR})
  endif()
endif()

# JSON LIBRARY
# set(JSON_VERSION 3.11.2)
# find_package(json ${JSON_VERSION} REQUIRED)
# if(NOT JSON_FOUND)
#   include(FetchContent)
#   FetchContent_Declare(
# 	json
# 	DOWNLOAD_EXTRACT_TIMESTAMP OFF
# 	URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
#   )
#   FetchContent_GetProperties(json)
#   if (NOT json_POPULATED)
#   	set(FETCHCONTENT_QUIET NO)
#   	FetchContent_Populate(json)
# 	set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
# 	add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR})
#   endif()
# endif()

FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz)
FetchContent_GetProperties(raylib)

FetchContent_Declare(curl URL https://curl.se/download/curl-7.64.1.tar.gz)
FetchContent_GetProperties(CURL)

# FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
# FetchContent_MakeAvailable(json)

file(GLOB_RECURSE CPP_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME} raylib curl)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}+"/../include/**")