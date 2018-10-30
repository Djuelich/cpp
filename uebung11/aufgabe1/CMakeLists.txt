project(THREADS)
 
# States that CMake required version must be greater than 2.6
cmake_minimum_required(VERSION 2.8)
 

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread ")

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")

# Build executable
add_executable(thread thread.cpp)
add_executable(thread1 thread1.cpp)
add_executable(thread2 thread2.cpp)
add_executable(thread3 thread3.cpp)


