cmake_minimum_required(VERSION 2.6)

project (game-chicken-run LANGUAGES C)
SET(APP_NAME chicken-run)

SET(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "./cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c -Wall -Wextra -pedantic -std=c11")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE SRC_SOURCES "src/*.c*")
FILE(GLOB_RECURSE INC_HEADERS "include/*.h*")

find_package(Curses REQUIRED)
include_directories(include )
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} )

add_executable(${APP_NAME} ${SRC_SOURCES} ${INC_HEADERS})
target_link_libraries(${APP_NAME}  ${CURSES_LIBRARIES})

