project(STL)
 
# States that CMake required version must be greater than 2.6
cmake_minimum_required(VERSION 2.8)
 

set(CMAKE_CXX_FLAGS "-std=c++11 ")

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")

# Build executable
add_executable(stl_aufg_1 Aufgabe2_1.cpp)
add_executable(stl_aufg_2 Aufgabe2_2.cpp)
add_executable(stl_aufg_3 Aufgabe2_3.cpp Summierer.cpp)
add_executable(stl_aufg_4 aufg2_4.cpp)

