CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(IndieStudio)

FIND_PACKAGE(raylib 4.0 QUIET) # [...]

if (NOT raylib_FOUND)
    INCLUDE(FetchContent)
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
    FetchContent_GetProperties(raylib)

if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
    endif()
endif()

#set(CMAKE_CXX_STANDARD 20)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
#set (CMAKE_CXX_FLAGS "-g3 -fPIC -I/usr/include/GL -L/usr/local/lib/raysan5")

file(GLOB sources src/*.cpp)

add_compile_options(-Wall -g3 -fno-gnu-unique)
add_executable(bomberman ${sources})

TARGET_LINK_LIBRARIES(bomberman raylib)

#target_link_libraries(bomberman PUBLIC GLESv2 glfw)
