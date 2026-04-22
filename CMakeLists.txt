cmake_minimum_required(VERSION 3.10)
project(BattleGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tells CMake where to look for your .h files
include_directories(include)

# This grabs every .cpp file inside the 'src' folder automatically
file(GLOB SOURCES "src/*.cpp")

# Build the executable
add_executable(game main.cpp ${SOURCES})