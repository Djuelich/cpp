cmake_minimum_required(VERSION 2.6)
project(PGMIO)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(libpgmio SHARED src/pgmio.c)


add_subdirectory(src)
