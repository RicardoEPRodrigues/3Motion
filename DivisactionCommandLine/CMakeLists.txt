cmake_minimum_required(VERSION 3.6)
project(DivisactionCommandLine)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../Divisaction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -O0 -fPIC -Wuninitialized -std=c++14")

set(SOURCE_FILES
        src/ConsoleUtilities/ProgressString.cpp
        src/ConsoleUtilities/ProgressString.h
        src/DivisactionCommandLine.cpp)

add_executable(DivisactionCommandLine ${SOURCE_FILES})
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/../Divisaction/Debug)
TARGET_LINK_LIBRARIES(DivisactionCommandLine Divisaction)