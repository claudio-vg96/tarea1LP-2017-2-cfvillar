cmake_minimum_required(VERSION 3.5)
project(tarea1LP_2017_2_cfvillar)

set(CMAKE_C_STANDARD 99)
include_directories(${CMAKE_SOURCE_DIR}/src)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${tarea1LP_2017_2_cfvillar_SOURCE_DIR}/bin)
##set(SOURCE_FILES src/main.c src/init.txt)
add_executable(tarea1LP_2017_2_cfvillar src/main.c )
