cmake_minimum_required(VERSION 3.17)
project(adventofcode2020)

set(CMAKE_CXX_STANDARD 14)
file(COPY "inputs"  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(adventofcode2020 main.cpp day2.cpp day2.h)