set(CMAKE_C_FLAGS "-g -Wall")



add_executable(pgmtest pgmtest.c)
add_executable(convolution convolution.c)


target_link_libraries(pgmtest libpgmio)
target_link_libraries(convolution libpgmio)



