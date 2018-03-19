cmake_minimum_required (VERSION 2.6)

project (game-chicken-run LANGUAGES CXX C)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(APP_NAME chicken-run)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_COMPILER gcc)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -w")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE SRC_SOURCES "src/*.c*")
FILE(GLOB_RECURSE INC_HEADERS "include/*.h*")

find_package(Curses REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} )
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${APP_NAME} ${SRC_SOURCES} ${INC_HEADERS})
target_link_libraries(${APP_NAME} ${CURSES_LIBRARIES})
