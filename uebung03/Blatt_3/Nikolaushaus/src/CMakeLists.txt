set(CMAKE_C_FLAGS "-g -Wall")


add_executable(nikolaushaus nikolaushaus.c)

set(CMAKE_MODULE_PATH "../cmake/;${CMAKE_MODULE_PATH}")


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(nikolaushaus ${SDL2_LIBRARY})


