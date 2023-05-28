cmake_minimum_required(VERSION 3.14)
project(savages)
set(CMAKE_CXX_STANDARD 17)

find_package(raylib 4.5.0 QUIET)
find_package(CURL REQUIRED)
include(FetchContent)

if (NOT raylib_FOUND)
	FetchContent_Declare(
		raylib
		URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED)
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib)
		set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

		option(CUSTOMIZE_BUILD "" ON)
		option(SUPPORT_SCREEN_CAPTURE "" OFF)
		option(SUPPORT_FILEFORMAT_GIF "" ON)

		add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
	endif()
endif()
file(GLOB_RECURSE CPP_SOURCES src/*.cpp)
add_compile_options("-DSUPPORT_FILEFORMAT_GIF")
add_executable(${PROJECT_NAME} ${CPP_SOURCES})

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(${PROJECT_NAME} raylib nlohmann_json::nlohmann_json ${CURL_LIBRARIES})
#target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")