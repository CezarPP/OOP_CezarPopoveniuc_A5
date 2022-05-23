cmake_minimum_required(VERSION 3.22)
project(UnitTesting)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
add_executable(UnitTesting main.cpp catch_amalgamated.cpp)