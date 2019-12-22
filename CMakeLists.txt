cmake_minimum_required(VERSION 3.4)
project(decay-chains-bateman)

set(CMAKE_CXX_STANDARD 11)

# all include libraries
include_directories(include)

add_library(bateman_lib SHARED include/Nucleus.h src/Nucleus.cpp
                        include/Reader.h src/Reader.cpp
                        include/NumericalMethod.h src/NumericalMethod.cpp
                        include/SolveBateman.h src/SolveBateman.cpp)

add_executable(bateman src/main.cpp)
target_link_libraries(bateman bateman_lib)